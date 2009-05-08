// copy.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_COPY_HPP_INCLUDED
#define MPL0X_COPY_HPP_INCLUDED

#include "./inserter.hpp"
#include "./fold.hpp"

extern struct copy_
{
    template<class Source, class Dest>
    auto operator()(type_<Source>&, type_<Dest>&)
        -> decltype(
               fold(operation(type<Dest>()), state(type<Dest>()), type<Source>())
           );
} & copy;

#endif
