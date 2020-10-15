//My solution to the problem at https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem

std::unordered_map<int, int> cache;

bool is_cached(int value, int& result) {
    if(cache.find(value) != cache.end()) {
        result = cache[value];
        return true;
    }
    return false;
}

void store_cache(int steps, int value) {
    cache[steps] = value;
}

int remaining_steps(int current_steps, int remaining) {
    if(remaining - current_steps < 0)
        return 0;
    else if(remaining - current_steps > 0) {
        int result;

        if(is_cached(remaining - current_steps, result))
            return result;

        result = remaining_steps(1, remaining - current_steps) + remaining_steps(2, remaining - current_steps) + remaining_steps(3, remaining - current_steps);

        store_cache(remaining - current_steps, result);

        return result;
    }
    
    return 1;
}

int stepPerms(int n) {
    int result = remaining_steps(1,n) + remaining_steps(2,n) + remaining_steps(3,n);
    return result % 10000000007;
}
