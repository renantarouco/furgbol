// Copyright 2019 FURGBot

#include "io/multicast_receiver.h"

namespace furgbol {
namespace io {

MulticastReceiver::MulticastReceiver() {
    datagram_received = rxcpp::observable<>::create<std::string>(
        [this](rxcpp::subscriber<std::string> subscriber){
            std::string datagram = "MY-DATAGRAM";
            subscriber.on_next(datagram);
            subscriber.on_completed();
        }
    );
}

MulticastReceiver::~MulticastReceiver() {}

}
}
