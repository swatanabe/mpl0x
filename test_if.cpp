// if.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include "./if.hpp"
#include "./eval.hpp"
#include "./assert_same.hpp"
#include "./type.hpp"

ASSERT_SAME(eval(if_(true_, type<char>(), type<double>())), char);

ASSERT_SAME(eval(if_(false_, type<char>(), type<double>())), double);
