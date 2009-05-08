// test_bind.hpp
//
// Copyright (c) 2009
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include "./bind.hpp"
#include "./fold.hpp"
#include "./list.hpp"
#include "./eval.hpp"
#include "./assert_same.hpp"
#include "./identity.hpp"

ASSERT_SAME(
    eval(bind(type(list), type<double>())),
    bind_(type_<list_>&, type_<double>&)
);

ASSERT_SAME(
    eval(apply(bind(type(list), type<double>()))),
    eval(list(type<double>()))
);

ASSERT_SAME(
    eval(fold(bind(type(list), _1, _2, type<double>()), type<int>(), list(type<char>()))),
    eval(list(type<int>(), type<char>(), type<double>()))
);

ASSERT_SAME(
    eval(fold(bind(type(list), bind(type(identity), _1), _2, type<double>()), type<int>(), list(type<char>()))),
    eval(list(type<int>(), type<char>(), type<double>()))
);
