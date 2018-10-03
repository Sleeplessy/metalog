// Created by Sleeplessy on 2018/10/2.
//

#ifndef METALOG_PRINTABLE_HPP
#define METALOG_PRINTABLE_HPP

#include <ostream>
#include <type_traits>
#include <typeinfo>
#include <string_view>
namespace metalog {

// This defines a meta struct stands for whether a data type could be printed to the log console
template<typename CONTENT_TYPE, typename = void>
struct is_printable : std::false_type {
  using content_type = CONTENT_TYPE;
  std::string_view type_name = typeid(CONTENT_TYPE).name();
};

// Enables the arithmetic type like int, long, double, etc.
template<typename ARITHMETIC_CONTENT_TYPE>
struct is_printable<ARITHMETIC_CONTENT_TYPE,
                    std::void_t<typename std::enable_if<std::is_arithmetic<ARITHMETIC_CONTENT_TYPE>::value>::type >>
    : std::true_type {
  using content_type = ARITHMETIC_CONTENT_TYPE;
  std::string_view type_name = typeid(ARITHMETIC_CONTENT_TYPE).name();
};

template<>
struct is_printable<char *>
    : std::true_type {
  using content_type = char *;
};


// A macro to expand custom printable types
#define INVOKE_PRINTABLE(TYPE) \
template<> \
struct metalog::is_printable<TYPE> \
    : std::true_type {\
    using content_type = TYPE;\
    std::string_view type_name = #TYPE; \
    };
}
#endif //METALOG_PRINTABLE_HPP
