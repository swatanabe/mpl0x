// apply.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_APPLY_HPP_INCLUDED
#define MPL0X_APPLY_HPP_INCLUDED

#include "./type.hpp"

template<class Fn>
Fn& make(type_<Fn>&);

template<class Fn, class... Args>
auto apply_impl(type_<Fn>& fn, type_<Args>&... args)
    -> decltype(
           make(type<Fn>())(type<Args>()...)
       );

extern struct apply_
{
    template<class Fn, class... Args>
    auto operator()(type_<Fn>& fn, type_<Args>&... args)
        -> decltype(
               apply_impl(type<Fn>(), type<Args>()...)
           );
} & apply;

#endif
