#include "io/multicast_receiver.h"

#include <string>
#include <iostream>

int main() {
    furgbol::io::MulticastReceiver mcr;
    mcr.datagram_received.subscribe(
        [](std::string datagram){
            std::cout << "next datagram: " << datagram << std::endl;
        },
        [](std::exception_ptr ep){
            std::cout << "error" << std::endl;
        },
        [](){
            std::cout << "completed" << std::endl;
        }
    );
}