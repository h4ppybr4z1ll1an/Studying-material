// My solution to the problem available at https://www.hackerrank.com/challenges/special-multiple/problem

size_t ninary(size_t& value) {
    size_t to_ret = 0;

    for(size_t i = 0; i < sizeof(size_t) * 8; ++i) {     
        if((value >> i) & 1) {
            to_ret += std::pow(10, i) * 9;
        }
    }
    return to_ret;
}

string solve(int n) {
    
    for(size_t i = 1; i < std::numeric_limits<size_t>::max(); ++i) {
        size_t as_nines = ninary(i);

        if((as_nines % n ) == 0)
            return std::to_string(as_nines);
    }
    return {""};
}   
