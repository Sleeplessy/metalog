// Created by Sleeplessy on 2018/10/3.

#ifndef METALOG_ITERABLE_HPP
#define METALOG_ITERABLE_HPP

#include <type_traits>
#include <metalog/core/content.hpp>

namespace metalog {
template<typename T, typename = void>
struct is_iterable : std::false_type {};

template<typename T>
struct is_iterable<T,
                   std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>
    : std::true_type {};

};

#endif //METALOG_ITERABLE_HPP
