// integral_c.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_INTEGRAL_C_HPP_INCLUDED
#define MPL0X_INTEGRAL_C_HPP_INCLUDED

#include "./type.hpp"

template<class T, T Value>
struct integral_c_;

template<class T, T Value>
type_<integral_c_<T, Value> >& integral_c();

#endif
