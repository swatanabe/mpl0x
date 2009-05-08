// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef EMPTY_DWA200957_HPP
# define EMPTY_DWA200957_HPP

# include "./type.hpp"

extern struct empty_
{
    template <class T>
    auto operator()(type_<T>& x) -> decltype(empty_impl(type<T>()));
}&
empty;

#endif // EMPTY_DWA200957_HPP
