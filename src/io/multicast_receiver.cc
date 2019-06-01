// Copyright 2019 FURGBot

#include <string>

#include "io/multicast_receiver.h"

namespace furgbol {
namespace io {

MulticastReceiver::MulticastReceiver(std::string group_ip ,uint16_t port):
    io_(),
    socket_(io_),
    endpoint_(boost::asio::ip::address_v4::any(), port){
    socket_.open(endpoint_.protocol());
    socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
    socket_.bind(endpoint_);
    socket_.set_option(
      boost::asio::ip::multicast::join_group(boost::asio::ip::address::from_string(group_ip)));
    //sincronosize_t = socket_.receive_from(boost::asio::buffer(buffer_, 8192),endpoint_);
    size_t = socket_.async_receive_from(
        boost::asio::buffer(buffer_, 8192), endpoint_,
        boost::bind(&receiver::handle_receive_from, this, 
        boost::asio::placeholders::error, 
        boost::asio::placeholders::bytes_transferred));
}

MulticastReceiver::~MulticastReceiver() {}
int MulticastReceiver::get_size(){
    return size_t;
}
}
}
