// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef LIST_DWA200957_HPP
# define LIST_DWA200957_HPP

# include "./type.hpp"
# include "./bool.hpp"

extern struct list_
{
    template <class...Elements>
    type_<list_(type_<Elements>&...)>& operator()(type_<Elements>&...);
}&
list;

template <class H, class...T>
type_<list_(T...)>& pop_front_impl(type_<list_(H,T...)>&);

template <class H, class...T>
H& front_impl(type_<list_(H,T...)>&);

template <class...Elements>
_false_ empty_impl(type_<list_(Elements...)>&);

template <class...Elements>
_true_ empty_impl(type_<list_()>&);

#endif // LIST_DWA200957_HPP
