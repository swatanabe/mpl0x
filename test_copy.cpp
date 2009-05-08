// test_copy.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include "./copy.hpp"
#include "./push_front.hpp"
#include "./inserter.hpp"
#include "./list.hpp"
#include "./assert_same.hpp"
#include "./eval.hpp"

ASSERT_SAME(eval(copy(list(), inserter(type(push_front), list()))), eval(list()));
ASSERT_SAME(eval(copy(list(type<int>(), type<char>()), inserter(type(push_front), list()))),
            eval(list(type<char>(), type<int>())));
