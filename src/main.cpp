// Copyright 2019 FURGBot

#include <iostream>
#include <string>

#include "io/multicast_receiver.h"

int main() {
    furgbol::io::MulticastReceiver mcr("224.5.23.2", 10020);
    std::cout << "Syn: " <<std::endl;
    mcr.do_receive_syn();
    std::cout << "Asyn: " <<std::endl;
    mcr.do_receive_asyn();
}
