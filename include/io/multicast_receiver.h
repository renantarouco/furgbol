// Copyright 2019 FURGBot

#ifndef IO_MULTICAST_RECEIVER_H
#define IO_MULTICAST_RECEIVER_H

#include <string>

#include <boost/asio.hpp>
#include <rxcpp/rx.hpp>

namespace furgbol {
namespace io {

class MulticastReceiver {
 public:
  MulticastReceiver(std::string, uint16_t);
  ~MulticastReceiver();
  rxcpp::observable<std::string> datagram_received;
 private:
  boost::asio::io_service io_;
  boost::asio::ip::udp::socket socket_;
  boost::asio::ip::udp::endpoint listen_endpoint_;
  boost::asio::ip::udp::endpoint sender_endpoint_;
  char buffer_[8192];
};

}  // namespace io
}  // namespace furgbol

#endif  // IO_MULTICAST_RECEIVER_H
