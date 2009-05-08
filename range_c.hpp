// range_c.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_RANGE_C_HPP_INCLUDED
#define MPL0X_RANGE_C_HPP_INCLUDED

#include "./type.hpp"
#include "./integral_c.hpp"
#include "./bool.hpp"

template<class T, T Low, T High>
struct range_c_;

template<class T, T Low, T High>
type_<range_c_<T, Low, High> >& range_c();

template<class T, T Low, T High>
type_<range_c_<T, Low + 1, High> >& pop_front_impl(type_<range_c_<T, Low, High> >&);

template<class T, T Low>
int pop_front_impl(type_<range_c_<T, Low, Low> >&);

template<class T, T Low>
_true_ empty_impl(type_<range_c_<T, Low, Low> >&);
template<class T, T Low, T High>
_false_ empty_impl(type_<range_c_<T, Low, High> >&);

template<class T, T Low, T High>
type_<integral_c_<T, Low> >& front_impl(type_<range_c_<T, Low, High> >&);

#endif
