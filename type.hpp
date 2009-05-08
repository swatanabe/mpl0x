// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef TYPE_DWA200957_HPP
# define TYPE_DWA200957_HPP

// wrapper class template and generator; allows us to pass all types
// (wrapped) to other functions.
template <class T>
struct type_;

// Used to wrap the type of an object, when you have one
template <class T>
type_<T>& type(T&);

// Used to wrap a particular type when you have no object
template <class T>
type_<T>& type();

#endif // TYPE_DWA200957_HPP
