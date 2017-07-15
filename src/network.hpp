#pragma once

#include "SDL_net.h"
#include "fatal-error.hpp"

namespace nf
{
  class Network
  {
  private:
    UDPsocket socket;
  public:
    Network(const Uint16 port);
    ~Network();
    void receive_data() const;
  };
}
