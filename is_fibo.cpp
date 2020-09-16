//My solution to the problem available at https://www.hackerrank.com/challenges/is-fibo/problem


using largest_int = long long;

constexpr int NTH_FIB = 70;

struct fib_base {

    virtual largest_int result() = 0;
    virtual fib_base& before() = 0;
};

template<int N>
struct fibonacci;

template<>
struct fibonacci<0>  : public fib_base {
    static constexpr largest_int value = 0;

    virtual largest_int result(){
        return value;
    }
    virtual fib_base& before() {
        return fibonacci<0>::instance();
    }

    static fibonacci& instance() {
        static fibonacci v;
        return v;
    }
};

template<>
struct fibonacci<1>  : public fib_base {
    static constexpr largest_int value = 1;

    virtual largest_int result(){
        return value;
    }
    virtual fib_base& before() {
        return fibonacci<0>::instance();
    }

    static fibonacci& instance() {
        static fibonacci v;
        return v;
    }
};

template<int N>
struct fibonacci  : public fib_base {
    static constexpr largest_int value = fibonacci<N-1>::value + fibonacci<N-2>::value;

    virtual largest_int result(){
        return value;
    }
    virtual fib_base& before() {
        return fibonacci<N-1>::instance();
    }

    static fibonacci& instance() {
        static fibonacci v;
        return v;
    }
};


std::unordered_set<largest_int>& init_fib() {
    static std::unordered_set<largest_int> set;
    fib_base* ptr = &fibonacci<NTH_FIB>::instance();
    
    while(true) {
        set.insert({ptr->result()});
        if(ptr->result() == 0)
            break;

        ptr = &ptr->before();
    }

    return set;
}

std::unordered_set<largest_int>& fib_numbers() {
    static std::unordered_set<largest_int>& set = init_fib();
    return set;
}

// Complete the solve function below.
string solve(long n) {
    static std::unordered_set<largest_int>& map = fib_numbers();

    if(map.find(n) != map.end()) {
        return "IsFibo";
    }

    return "IsNotFibo";
}
