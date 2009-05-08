// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef POP_FRONT_DWA200957_HPP
# define POP_FRONT_DWA200957_HPP

# include "./type.hpp"

extern struct pop_front_
{
    template <class T>
    auto operator()(type_<T>& x) -> decltype(pop_front_impl(type<T>()));
}&
pop_front;

#endif // POP_FRONT_DWA200957_HPP
