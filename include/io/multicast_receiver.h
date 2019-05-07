// Copyright 2019 FURGBot

#ifndef IO_MULTICAST_RECEIVER_H
#define IO_MULTICAST_RECEIVER_H

#include <string>

#include <rxcpp/rx.hpp>

namespace furgbol {
namespace io {

class MulticastReceiver {
 public:
  MulticastReceiver();
  ~MulticastReceiver();
  rxcpp::observable<std::string> datagram_received;
};

}  // namespace io
}  // namespace furgbol

#endif  // IO_MULTICAST_RECEIVER_H
