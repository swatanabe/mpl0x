// bind.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#ifndef MPL0X_BIND_HPP_INCLUDED
#define MPL0X_BIND_HPP_INCLUDED

#include "./type.hpp"

extern struct bind_
{
    template<class Fn, class...Args>
    auto operator()(type_<Fn>& fn, type_<Args>&...args)
        -> decltype(
            type<bind_(type_<Fn>&, type_<Args>&...)>()
        );
} & bind;

template<class Fn, class... BindArgs, class... Args>
auto apply_impl(type_<bind_(type_<Fn>&, type_<BindArgs>&...)>&, type_<Args>&...)
    -> decltype(
           bind_impl(type<bind_(type_<Fn>&, type_<BindArgs>&...)>(), type<Args>()...)
       );

template<class Fn, class... BindArgs, class... Args>
auto bind_impl(type_<bind_(type_<Fn>&, type_<BindArgs>&...)>&, type_<Args>&...)
    -> decltype(
           apply(bind_impl(type<Fn>(), type<Args>()...), bind_impl(type<BindArgs>(), type<Args>()...)...)
       );

template<class t, class...args>
auto bind_impl(type_<t>&, type_<args>&...)
    -> decltype(
           type<t>()
       );

template<int N>
struct arg_;

template<int N>
auto arg() -> decltype(type<arg_<N> >());

extern type_<arg_<1> > & _1;
extern type_<arg_<2> > & _2;
extern type_<arg_<3> > & _3;

template<class Front, class...Rest>
auto bind_impl(type_<arg_<1> >&, type_<Front>&, type_<Rest>&...)
    -> decltype(type<Front>());

template<int N, class Front, class...Rest>
auto bind_impl(type_<arg_<N> >&, type_<Front>&, type_<Rest>&...)
    -> decltype(bind_impl(arg<N-1>(), type<Rest>()...));

template<class Fn, class...Args>
int make(type_<bind_(type_<Fn>&, type_<Args>&...)>&);

#endif
