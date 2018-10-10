// Created by Sleeplessy on 2018/10/3.

#ifndef METALOG_IOSTREAM_HPP
#define METALOG_IOSTREAM_HPP

#include <iostream>

namespace metalog {
// wrap a default sys ostream
template<typename CHAR_T>
constexpr auto &&wrap_cout() {
  if constexpr (std::is_same_v<CHAR_T, char>) {
    return std::cout;
  } else {
    return std::wcout;
  }
}
}

#endif //METALOG_IOSTREAM_HPP
