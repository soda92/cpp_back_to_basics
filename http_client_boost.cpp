#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>
#include <fmt/core.h>
#include <vector>
extern "C" {
#include "windows.h"
}
using namespace std;
using namespace std::chrono;

namespace beast = boost::beast;  // from <boost/beast.hpp>
namespace http = beast::http;    // from <boost/beast/http.hpp>
namespace net = boost::asio;     // from <boost/asio.hpp>
using tcp = net::ip::tcp;        // from <boost/asio/ip/tcp.hpp>

// from: https://www.sindsun.com/articles/16/136
string utf8_to_gbk(string src) {
    auto t0 = steady_clock::now();
    auto src_str = src.c_str();
    int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
    wchar_t* wszGBK = new wchar_t[len + 1];
    memset(wszGBK, 0, len * 2 + 2);
    MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char* szGBK = new char[len + 1];
    memset(szGBK, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    string strTemp(szGBK);
    if (wszGBK) delete[] wszGBK;
    if (szGBK) delete[] szGBK;
    return strTemp;
}


// Performs an HTTP GET and prints the response
int main(int argc, char** argv) {
    auto t0 = steady_clock::now();
    try {
        auto const host = "127.0.0.1";
        auto const port = "5000";
        auto const target = "/test/zh_hans";
        int version = 11;

        // The io_context is required for all I/O
        net::io_context ioc;

        // These objects perform our I/O
        tcp::resolver resolver(ioc);
        beast::tcp_stream stream(ioc);

        // Look up the domain name
        auto const results = resolver.resolve(host, port);
        fmt::print(
            "resolve time elpased: {}ms\n",
            duration_cast<milliseconds>(steady_clock::now() - t0).count());

        // Make the connection on the IP address we get from a lookup
        stream.connect(results);
        fmt::print(
            "connect time elpased: {}ms\n",
            duration_cast<milliseconds>(steady_clock::now() - t0).count());

        // Set up an HTTP GET request message
        http::request<http::string_body> req{http::verb::get, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Send the HTTP request to the remote host
        http::write(stream, req);
        fmt::print(
            "send header time elpased: {}ms\n",
            duration_cast<milliseconds>(steady_clock::now() - t0).count());

        // This buffer is used for reading and must be persisted
        beast::flat_buffer buffer;

        // Declare a container to hold the response
        http::response<http::string_body> res;

        // Receive the HTTP response
        http::read(stream, buffer, res);
        fmt::print(
            "read response time elpased: {}ms\n",
            duration_cast<milliseconds>(steady_clock::now() - t0).count());

        // Write the message to standard out

        string str = res.body();
        string str2 = utf8_to_gbk(str);
        fmt::print(
            "convert time elpased: {}ms\n",
            duration_cast<milliseconds>(steady_clock::now() - t0).count());

        // Gracefully close the socket
        beast::error_code ec;
        stream.socket().shutdown(tcp::socket::shutdown_both, ec);
        fmt::print(
            "shutdown time elpased: {}ms\n",
            duration_cast<milliseconds>(steady_clock::now() - t0).count());

        // not_connected happens sometimes
        // so don't bother reporting it.
        //
        if (ec && ec != beast::errc::not_connected)
            throw beast::system_error{ec};

        // If we get here then the connection is closed gracefully
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
