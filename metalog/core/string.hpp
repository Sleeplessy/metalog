// Created by Sleeplessy on 2018/10/2.

#ifndef METALOG_STRING_HPP
#define METALOG_STRING_HPP

#include <metalog/core/iostream.hpp>
#include <metalog/core/printable.hpp>
#include <metalog/core/content.hpp>
#include <string>

namespace metalog {
template<typename CHAR_T>
struct is_printable<std::basic_string<CHAR_T>> : std::true_type {

  using content_type = std::basic_string<CHAR_T>;
  // I guess one would like to use wstring_view if he produced a wide string
  std::basic_string_view<CHAR_T> type_name = wrap_type_name();

  auto &&wrap_type_name() {
    if constexpr(std::is_same_v<CHAR_T, char>) {
      return "std::basic_string<char>";
    } else {
      return L"std::basic_string<wchar_t>";
    }
  }
};

template<typename CHAR_T>
struct content<std::basic_string<CHAR_T>> : meta_content<std::basic_string<CHAR_T>> {
  content(std::basic_string<CHAR_T> content_body, std::basic_ostream<CHAR_T> &output_stream = wrap_cout<CHAR_T>())
      : body(content_body), log_stream{output_stream} {}
      template <typename OS_CHAR_T>
  void print(std::basic_ostream<OS_CHAR_T> &output_stream) {
    output_stream << body.data();
  }

  void print() {
    log_stream << body.data();
  }

  constexpr auto &get_log_stream() {
    return log_stream;
  }

  using content_type  = std::basic_string<CHAR_T>;
  content_type body;

  using os_type = std::basic_ostream<CHAR_T>;
  os_type &log_stream;
};
}

#endif //METALOG_STRING_HPP
