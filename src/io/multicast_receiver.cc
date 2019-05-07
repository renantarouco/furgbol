// Copyright 2019 FURGBot

#include "io/multicast_receiver.h"

namespace furgbol {
namespace io {

MulticastReceiver::MulticastReceiver(std::string group_addr, uint16_t port) :
  io_(),
  socket_(io_),
  listen_endpoint_(boost::asio::ip::address_v4::any(), port) {
  socket_.open(listen_endpoint_.protocol());
  socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
  socket_.bind(listen_endpoint_);
  socket_.set_option(
    boost::asio::ip::multicast::join_group(
      boost::asio::ip::address::from_string(group_addr)));
  datagram_received = rxcpp::observable<>::create<std::string>(
    [this](rxcpp::subscriber<std::string> s){
      while (1) {
        try {
            // size_t bytes_rcvd = socket_.receive_from(
            // boost::asio::buffer(buffer_, 8192),
            // sender_endpoint_);
            s.on_next("MYDATAGRAM");
        } catch (boost::system::system_error error) {
            s.on_error(rxcpp::util::make_error_ptr(error.what()));
            break;
        }
      }
      s.on_completed();
    });
}

MulticastReceiver::~MulticastReceiver() {}

}  // namespace io
}  // namespace furgbol
