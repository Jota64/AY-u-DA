#include <NoWinnerException.hpp>

const char* NoWinnerException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW 
{
  return "No winner";
}
