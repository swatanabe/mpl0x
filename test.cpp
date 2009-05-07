template <class T>
struct type_;

template <class T>
type_<T>& type(T&);

template <class T>
type_<T>& type();

template <class...T> 
struct list_;

template <class...T>
type_<list_<T...> >&
list(T&...);

//template <class F, class Args...>
//struct apply_;

// apply
extern struct apply_
{
template <class F, class...Args>
auto operator()(type_<F>& f, Args&... a) -> decltype(F()(a...));
} &apply;

extern struct vector_
{
    template <class...Elements>
    type_<vector_(type_<Elements>&...)>& operator()(type_<Elements>&...);
}
    & vector;

// add_pointer
extern struct add_pointer_
{
    template <class T>
    type_<T*>& operator()(type_<T>&);
}
    &add_pointer;

template <class H, class T>
struct cell;

extern struct cons_
{
    template <class T, class U>
    type_<cell<T,U> >& operator()(type_<T>&, type_<U>&);
}
    &cons;

template <class Fn, class X>
auto fold(Fn& fn, X& x, type_<vector_()>& v) -> decltype(x);

template <class Fn, class X, class H, class...T>
auto
fold(type_<Fn>& fn, X& x, type_<vector_(type_<H>&,T...)>& v)
    -> decltype(
                fold(
                     fn,
                     Fn()(x, type<H>()),
                     type<vector_(T...)>()
                     )
                );

template <class T, class U> struct assert_same;
template <class T> struct assert_same<T,T> {};

template <class T> struct untype;
template <class T>
struct untype<type_<T>& >
{
    typedef T type;
};

// Inc
extern struct inc_
{
    template <int i>
    type_<int[i+1]>& operator()(type_<int[i]>&);
}
    &inc;

// Count
type_<int[1]>&
count(type_<vector_()>&);

template <class H, class...T>
auto count(type_<vector_(type_<H>&,T...)>&)
    -> decltype(inc(count(type<vector_(T...)>())));



#define eval(x) untype<decltype(x)>::type

assert_same<eval(apply(type(add_pointer), type<void>())), void*> x1;
assert_same<eval(apply(type(cons), type<void>(), type<int>())), cell<void,int> > x2;


assert_same<eval(count(vector())), int[1]> b1;
assert_same<eval(count(vector(type<int>()))), int[2]> b2;
assert_same<eval(count(vector(type<int>(),type<long>()))), int[3]> b3;

assert_same<eval(fold(type(cons), type<void>(), vector())), void> a1;
assert_same<eval(fold(type(cons), type<void>(), vector(type<int>()))), cell<int,void> > a2;

int main() {}
