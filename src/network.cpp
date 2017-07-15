#include "network.hpp"

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
  UDPpacket *packet = SDLNet_AllocPacket(1024);
  char buffer[1024];

  switch (SDLNet_UDP_Recv(socket, packet)) {
    case 1:
      memcpy(buffer, packet->data, packet->len);
      buffer[packet->len] = '\0';
      std::cout << buffer << "\n";
      std::cout << packet->len << " bytes received\n";
      break;
  }
}
