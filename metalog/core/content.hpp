// Created by Sleeplessy on 2018/10/3.

#ifndef METALOG_CONTENT_HPP
#define METALOG_CONTENT_HPP

#include <string>
#include <metalog/core/printable.hpp>
#include <metalog/core/iostream.hpp>
#include <ostream>
#include "iterable.hpp"
namespace metalog {

template<typename CONTENT_BODY>
struct meta_content {
  //static_assert(is_printable<CONTENT_BODY>::value, "content body must be a printable type");
  virtual void print() {}

  template <typename CHAR_T>
  void print(std::basic_ostream<CHAR_T>& os)
  {

  }
  using content_type = CONTENT_BODY;
  std::string_view type_name = typeid(CONTENT_BODY).name();
};

template<typename CONTENT_BODY, typename CHAR_T = char , typename = void>
struct content : meta_content<CONTENT_BODY> {
  void print(CONTENT_BODY body, std::basic_ostream<CHAR_T> &output_stream) {
    output_stream << body;
  }
};

template<typename CONTENT_BODY>
struct is_printable<content<CONTENT_BODY>> : std::true_type {

  using content_type = CONTENT_BODY;

  auto &&wrap_type_name() {
    return typeid(CONTENT_BODY).name();
  }

  std::string_view type_name = wrap_type_name();
};

template<typename CONTENT_BODY, typename CHAR_T>
std::basic_ostream<CHAR_T> &operator<<(std::basic_ostream<CHAR_T> &os, content<CONTENT_BODY> &content_body) {
  content_body.print(os);
  return os;
}

}
#endif //METALOG_CONTENT_HPP
