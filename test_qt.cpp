#include <QString>
#include <QByteArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QTextCodec>

#include <fmt/core.h>


// ²Î¿¼£º https://stackoverflow.com/a/4182144/12291425

class MyNetworkTest : public QObject {
    Q_OBJECT
   public:
    QNetworkAccessManager *manager;
    explicit MyNetworkTest(QCoreApplication *application) {
        manager = new QNetworkAccessManager(application);
        connect(manager, &QNetworkAccessManager::finished, this,
                &MyNetworkTest::process_result);
    }
   signals:
    void finished();

    public slots:
    void do_get() const {
        manager->get(QNetworkRequest(QUrl("http://127.0.0.1:5000/conf/IPC1")));
    }
    void process_result(QNetworkReply *reply) {
        auto result = reply->readAll();
        auto answer_utf8 = QString::fromUtf8(result);
        auto answer_gbk =
            QTextCodec::codecForName("GBK")->fromUnicode(answer_utf8);
        fmt::print("{}\n", answer_gbk.toStdString());
        emit finished();
    }
};

#include "test_qt.moc"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    MyNetworkTest *test = new MyNetworkTest(&app);
    QObject::connect(test, &MyNetworkTest::finished, &app, &QCoreApplication::quit);
    // This will run the task from the application event loop.
    QTimer::singleShot(0, test, &MyNetworkTest::do_get);
    return app.exec();
}
