#include "io/multicast_receiver.h"

#include <string>
#include <iostream>

int main() {
    int cont = 0;
    while(1){
        furgbol::io::MulticastReceiver mcr("224.5.23.2",10020);
        std::cout<<"b "<<mcr.get_s()<<std::endl;
        std::cout<<"Tempo: "<<(cont++)<<" Tamanho da mensagem: "<<mcr.get_size()<<std::endl;
    }
}