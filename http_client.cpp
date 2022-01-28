#include <iostream>
#include <string>

#include "httplib.h"
using namespace std;

int main() {
    httplib::Client cli{"localhost:5000"};
    auto res = cli.Get("/conf/IPC1");
    std::string ret;
    if (res && res->status == 200) {
        ret = res->body;
    }
    cout << ret << "\n";
    return 0;
}
