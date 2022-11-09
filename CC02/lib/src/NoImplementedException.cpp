#include <NoImplementedException.hpp>

const char* NoImplementedException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW 
{
  return "This operation has not been implemented yet";
}
