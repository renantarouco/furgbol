// Copyright 2019 FURGBot

#include "io/multicast_receiver.h"
#include <string>
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
    size_t = socket_.receive_from(boost::asio::buffer(buffer_, 8192),endpoint_);

}

MulticastReceiver::~MulticastReceiver() {}
int MulticastReceiver::get_size(){
    return size_t;
}
std::string MulticastReceiver::get_s(){
    std::string B;
    B = buffer_;
    return B;
}
}
}
