#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QPushButton button1("test");
    QPushButton button2("other", &button1);
    button1.setMinimumSize(200, 200);

    button1.show();

    return app.exec();
}
