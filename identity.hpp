// identity.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_IDENTITY_HPP_INCLUDED
#define MPL0X_IDENTITY_HPP_INCLUDED

#include ".\type.hpp"

extern struct identity_ {
    template<class T>
    auto operator()(type_<T>&) -> decltype(type<T>());
}& identity;

#endif
