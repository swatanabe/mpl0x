// push_front.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_PUSH_FRONT_HPP_INCLUDED
#define MPL0X_PUSH_FRONT_HPP_INCLUDED

#include "./inserter.hpp"
#include "./fold.hpp"

extern struct push_front_
{
    template<class Sequence, class Element>
    auto operator()(type_<Sequence>&, type_<Element>&)
        -> decltype(
               push_front_impl(type<Sequence>(), type<Element>())
           );
} & push_front;

#endif
