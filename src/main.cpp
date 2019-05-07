// Copyright 2019 FURGBot

#include <iostream>
#include <string>

#include "io/multicast_receiver.h"

int main() {
    furgbol::io::MulticastReceiver mcr("224.32.25.7", 20010);
    mcr.datagram_received.subscribe(
        [](std::string datagram){
            std::cout << "next datagram: " << datagram << std::endl;
        },
        [](std::exception_ptr ep){
            std::cout << "error" << std::endl;
        },
        [](){
            std::cout << "completed" << std::endl;
        });
}
