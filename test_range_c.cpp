// test_range_c.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include "./range_c.hpp"
#include "./assert_same.hpp"
#include "./eval.hpp"
#include "./list.hpp"
#include "./copy.hpp"
#include "./front_inserter.hpp"

ASSERT_SAME(eval(copy(range_c<int, 0, 5>(), front_inserter(list()))),
            eval(list(integral_c<int, 4>(),
                      integral_c<int, 3>(),
                      integral_c<int, 2>(),
                      integral_c<int, 1>(),
                      integral_c<int, 0>())));
