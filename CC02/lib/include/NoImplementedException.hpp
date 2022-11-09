#pragma once

#include <exception>

class NoImplementedException: public std::exception
{
public:
  const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};
