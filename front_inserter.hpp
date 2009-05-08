// front_inserter.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_FRONT_INSERTER_HPP_INCLUDED
#define MPL0X_FRONT_INSERTER_HPP_INCLUDED

#include "./inserter.hpp"
#include "./push_front.hpp"
#include "./type.hpp"

extern struct front_inserter_
{
    template<class Sequence>
    auto operator()(type_<Sequence>&)
        -> decltype(
               inserter(type(push_front), type<Sequence>())
           );
} & front_inserter;

#endif
