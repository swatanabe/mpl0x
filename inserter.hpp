// inserter.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_INSERTER_HPP_INCLUDED
#define MPL0X_INSERTER_HPP_INCLUDED

#include "./type.hpp"

extern struct inserter_
{
    template<class Operation, class State>
    auto operator()(type_<Operation>&, type_<State>&)
        -> decltype(
               type<inserter_(type_<Operation>&, type_<State>&)>()
           );
} & inserter;

extern struct operation_
{
    template<class Operation, class State>
    auto operator()(type_<inserter_(type_<Operation>&, type_<State>&)>&)
        -> decltype(
               type<Operation>()
           );
} & operation;

extern struct state_
{
    template<class Operation, class State>
    auto operator()(type_<inserter_(type_<Operation>&, type_<State>&)>&)
        -> decltype(
               type<State>()
           );
} & state;

#endif
