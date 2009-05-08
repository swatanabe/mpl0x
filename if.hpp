// identity.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_IF_HPP_INCLUDED
#define MPL0X_IF_HPP_INCLUDED

#include "./type.hpp"
#include "./bool.hpp"

extern struct _if_ {
    template<class True, class False>
    auto operator()(_true_&, type_<True>& t, type_<False>& f) -> decltype(type<True>());
    template<class True, class False>
    auto operator()(_false_&, type_<True>& t, type_<False>& f) -> decltype(type<False>());
}& if_;

#endif
