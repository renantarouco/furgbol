// Copyright 2019 FURGBot

#ifndef IO_MULTICAST_RECEIVER_H
#define IO_MULTICAST_RECEIVER_H

#include <string>
#include <boost/asio.hpp>

namespace furgbol {
namespace io {

class MulticastReceiver {
  private:
    boost::asio::io_service io_;
    boost::asio::ip::udp::endpoint endpoint_;
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    char buffer_[8192];
    int size_t;

  public:
    MulticastReceiver(std::string group_ip,uint16_t port);
    ~MulticastReceiver();
    int get_size();
    std::string get_s();
};

}  // namespace io
}  // namespace furgbol

#endif  // IO_MULTICAST_RECEIVER_H
