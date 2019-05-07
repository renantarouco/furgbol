// Copyright 2019 FURGBot

#ifndef IO_MULTICAST_RECEIVER_H
#define IO_MULTICAST_RECEIVER_H

#include <rxcpp/rx.hpp>

namespace furgbol {
namespace io {

class MulticastReceiver {
 public:
  MulticastReceiver();
  ~MulticastReceiver();
};

}  // namespace io
}  // namespace furgbol

#endif  // IO_MULTICAST_RECEIVER_H
