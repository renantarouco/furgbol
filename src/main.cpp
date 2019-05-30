// Copyright 2019 FURGBot

#include <iostream>
#include <string>

#include "io/multicast_receiver.h"

int main() {
    furgbol::io::MulticastReceiver mcr("224.5.23.2",10020);
    std::cout << "Tamanho da mensagem: " << mcr.get_size() <<std::endl;
}
