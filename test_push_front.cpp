// test_push_front.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include "./push_front.hpp"
#include "./assert_same.hpp"
#include "./eval.hpp"

ASSERT_SAME(eval(push_front(list(), type<int>())), eval(list(type<int>())));
ASSERT_SAME(eval(push_front(list(type<char>()), type<int>())), eval(list(type<int>(), type<char>())));
