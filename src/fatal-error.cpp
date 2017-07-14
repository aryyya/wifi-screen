#include "fatal-error.hpp"

namespace
{
  static void
  _log_error(const std::string &error_message)
  {
    std::cout << __FILE__ << ": " << error_message << "\n";
  }
}

void
nf::fatal_error(const std::string& error_message)
{
  _log_error(error_message);
  std::exit(EXIT_FAILURE);
}

void
nf::fatal_error_sdl(const std::string& error_message)
{
  _log_error(error_message);
  _log_error(SDL_GetError());
  std::exit(EXIT_FAILURE);
}
