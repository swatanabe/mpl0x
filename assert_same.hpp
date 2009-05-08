// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef ASSERT_SAME_DWA200957_HPP
# define ASSERT_SAME_DWA200957_HPP

template <class T, class U> struct assert_same;
template <class T> struct assert_same<T,T> { typedef int type; };

# define ASSERT_SAME(x,y) typedef assert_same<x,y>::type AssertionOfSameness

#endif // ASSERT_SAME_DWA200957_HPP
