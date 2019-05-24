#ifndef PAGEDOWNLOADER_H
#define PAGEDOWNLOADER_H
#include <string>
#include <sstream>
#include <boost/asio.hpp>

class PageDownloader
{
private:
    std::string _page;
    std::ostringstream in;
    boost::asio::ip::tcp::iostream stream;
public:
    PageDownloader(const std::string &host, const std::string &get);
    PageDownloader() = delete;
    PageDownloader(const PageDownloader &other) = delete;
    PageDownloader(const PageDownloader &&other) = delete;
    std::string &page();
};

#endif // PAGEDOWNLOADER_H
