// Created by Sleeplessy on 2018/10/3.

#ifndef METALOG_ITERABLE_HPP
#define METALOG_ITERABLE_HPP

#include <iterator>
#include <utility>
#include <experimental/iterator>
#include <metalog/core/content.hpp>

namespace metalog {
template<typename T, typename = void>
struct is_iterable : std::false_type {};

template<typename T>
struct is_iterable<T,
                   std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>
    : std::true_type {
};

// Enables the arithmetic type like int, long, double, etc.
template<typename ELEM_T, template<typename = ELEM_T> typename CONTENT_TYPE>
struct is_printable<CONTENT_TYPE<ELEM_T>,
                    std::void_t<typename std::enable_if<is_iterable<typename CONTENT_TYPE<ELEM_T>::value>::type,
                                                        typename std::enable_if<is_printable<ELEM_T>::value>::type>>>
    : std::true_type {
  using content_type = CONTENT_TYPE<ELEM_T>;
  std::string_view type_name = typeid(CONTENT_TYPE<ELEM_T>).name();
};

// An iterable content
template<typename CONTAINER_T, typename CHAR_T>
struct content<CONTAINER_T,
               CHAR_T,
               std::void_t<typename std::enable_if<is_iterable<CONTAINER_T>::value>::type,
                           typename std::enable_if<is_printable<typename CONTAINER_T::value_type>::value>::type>>
    : meta_content<CONTAINER_T> {
  content(CONTAINER_T content_body, std::basic_ostream<CHAR_T> &output_stream = wrap_cout<CHAR_T>())
      : body(content_body), log_stream(output_stream) {}
  using content_type = CONTAINER_T;
  enum bracket_type {
    null, // NONE
    bracket, // ()
    square, // []
    brace, // {}
    pointy, // <>
  };
  void print(std::basic_ostream<CHAR_T> &output_stream, content_type &body) {
    output_stream << get_bracket().first.data();
    std::copy(std::begin(body),
              std::end(body),
              std::experimental::make_ostream_joiner(output_stream, ", "));
    output_stream << get_bracket().second.data();
  }

  void print(std::basic_ostream<CHAR_T> &output_stream) {
    print(output_stream, body);
  }

  auto wrap_type_name() {
    return typeid(CONTAINER_T).name();
  }
  content_type body;
  std::basic_ostream<CHAR_T>& log_stream;
  std::string_view type_name = wrap_type_name();
  std::string_view sparerator = ",";
  bracket_type bracket_value = bracket_type::null;

  std::pair<std::string_view, std::string_view> get_bracket() {
    switch (bracket_value) {
    case bracket_type::null:return {"", ""};
    case bracket_type::bracket:return {"(", ")"};
    case bracket_type::square:return {"[", "]"};
    case bracket_type::brace:return {"{", "}"};
    case bracket_type::pointy:return {"<", ">"};
    default:return {"", ""};
    }
  }
};


};

#endif //METALOG_ITERABLE_HPP
