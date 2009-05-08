#include "./assert_same.hpp"
#include "./eval.hpp"
#include "./fold.hpp"
#include "./pop_front.hpp"
#include "./list.hpp"

ASSERT_SAME(eval(pop_front(
                     list(type<int>(),type<char>(),type<long>()))),
            eval(list(type<char>(),type<long>())));

template <class T, class U> struct cell;

extern struct cons_
{
    template <class T, class U>
    type_<cell<T,U> >& operator()(type_<T>&, type_<U>&);
}& cons;

ASSERT_SAME(eval(pop_front(
                     list(type<int>(),type<char>(),type<long>()))),
            eval(list(type<char>(),type<long>())));

ASSERT_SAME(eval(front(
                     list(type<int>(),type<char>(),type<long>()))),
            int);

ASSERT_SAME(eval(fold(type(cons), type<int>(), list())), int);
typedef cell<void,int> x;
ASSERT_SAME(eval(fold(type(cons), type<void>(), list(type<int>()))), x);

int main() {}
