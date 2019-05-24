#include "pagedownloader.h"
#include <fstream>
PageDownloader::PageDownloader(const std::string &host, const std::string &get)
{
    stream.connect(host, "http");
    std::string _get = "GET " + get + " HTTP/1.1\r\n";
    stream << _get;
    std::string _host = "Host: " + host + "\r\n";
    stream << _host;
    stream << "Connection: close\r\n\r\n" << std::flush;
    in << stream.rdbuf();
    _page = in.str();
}

std::string &PageDownloader::page()
{
    return _page;
}
