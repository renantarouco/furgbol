// Copyright 2019 FURGBot

#ifndef IO_MULTICAST_RECEIVER_H
#define IO_MULTICAST_RECEIVER_H

#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace furgbol {
namespace io {

class MulticastReceiver {
  private:
    boost::asio::io_service io_;
    boost::asio::ip::udp::endpoint endpoint_;
    boost::asio::ip::udp::socket socket_;
    char buffer_[8192];
    int size;

  public:
    MulticastReceiver(std::string group_ip,uint16_t port);
    ~MulticastReceiver();
    void do_receive_syn();
    void do_receive_asyn();
    void handle_receive(const boost::system::error_code& error, size_t bytes_transferred);

};

}  // namespace io
}  // namespace furgbol

#endif  // IO_MULTICAST_RECEIVER_H
