// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOL_DWA200957_HPP
# define BOOL_DWA200957_HPP

# include "./type.hpp"

template <bool x> struct bool_;

typedef type_<bool_<false> >& _false_;
typedef type_<bool_<true> >& _true_;

extern _false_ false_;
extern _true_ true_;

#endif // BOOL_DWA200957_HPP
