#include "fatal-error.hpp"

namespace
{
  void
  _log_error(const std::string &error_message)
  {
    std::cerr << __FILE__ << ": " << error_message << "\n";
  }
}

void
nf::fatal_error(const std::string& error_message)
{
  _log_error(error_message);
  std::exit(EXIT_FAILURE);
}

void
nf::fatal_error_sdl(const std::string& error_message, const nf::ErrorType error_type)
{
  _log_error(error_message);
  switch (error_type) {
    case nf::ErrorType::SDL: _log_error(SDL_GetError()); break;
    case nf::ErrorType::SDL_NET: _log_error(SDLNet_GetError()); break;
    default: break;
  }
  std::exit(EXIT_FAILURE);
}
