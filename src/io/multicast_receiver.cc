// Copyright 2019 FURGBot

#include <string>
#include <iostream>

#include "io/multicast_receiver.h"

namespace furgbol {
namespace io {

MulticastReceiver::MulticastReceiver(std::string group_ip ,uint16_t port):
    io_(),
    socket_(io_),
    // Create the socket so that multiple may be bound to the same address
    endpoint_(boost::asio::ip::address_v4::any(), port){
    socket_.open(endpoint_.protocol());
    socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
    socket_.bind(endpoint_);

    // Join the multicast group.
    socket_.set_option(
      boost::asio::ip::multicast::join_group(boost::asio::ip::address::from_string(group_ip)));
}

void MulticastReceiver::do_receive_asyn(){
  socket_.async_receive_from(boost::asio::buffer(buffer_, 8192), endpoint_,
    boost::bind(&MulticastReceiver::handle_receive, this,
    boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
  io_.run();
}
void MulticastReceiver::handle_receive(const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout<<bytes_transferred<<std::endl;
    if (!error || error == boost::asio::error::message_size){//check if you received a message
        //do_receive_asyn();
	}
}
void MulticastReceiver::do_receive_syn(){
  size = socket_.receive_from(boost::asio::buffer(buffer_, 8192),endpoint_);
  std::cout<<size<<std::endl;
}
MulticastReceiver::~MulticastReceiver() {}
}
}
