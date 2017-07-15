#include "network.hpp"

namespace
{
  const int UDP_RECV_NONE = 0;
  const int UDP_RECV_RECEIVED = 1;
  const int UDP_RECV_ERROR = -1;
}

nf::Network::Network(const Uint16 port)
{
  socket = SDLNet_UDP_Open(port);
  if (socket == nullptr) nf::fatal_error_sdl("sdl udp socket open error", nf::ErrorType::SDL_NET);
}

nf::Network::~Network()
{
  SDLNet_UDP_Close(socket);
  socket = nullptr;
}

void
nf::Network::receive_data() const
{
  UDPpacket *packet = SDLNet_AllocPacket(64);
  const int status = SDLNet_UDP_Recv(socket, packet);

  if (status == UDP_RECV_RECEIVED) {
#ifdef DEV_MODE
    std::cout << "packet received\n";
#endif
  }
  
#ifdef DEV_MODE
  else if (status == UDP_RECV_ERROR) {
    std::cerr << "sdl net udp recv error\n";
  }
#endif
}
