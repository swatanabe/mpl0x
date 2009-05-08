// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef UNTYPE_DWA200957_HPP
# define UNTYPE_DWA200957_HPP

# include "./type.hpp"

// Unwrapper for type_
template <class T> struct untype;

template <class T>
struct untype<type_<T>& >
{
    typedef T type;
};

#endif // UNTYPE_DWA200957_HPP
