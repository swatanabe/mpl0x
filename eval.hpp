// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef EVAL_DWA200957_HPP
# define EVAL_DWA200957_HPP

# include "./untype.hpp"

#define eval(x) untype<decltype(x)>::type

#endif // EVAL_DWA200957_HPP
