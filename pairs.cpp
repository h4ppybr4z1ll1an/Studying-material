// Two different solutions to the problem available at https://www.hackerrank.com/challenges/pairs/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=search

int pairs(int k, vector<int> arr) {
    std::unordered_set<int> values;

    for(auto v : arr) {
        values.insert(v);
    }

    int counter = 0;

    for(auto v : arr) {
        if(values.find(v + k) != values.end())
            ++counter;
    }

    return counter;
}

int pairs_alternative(int k, vector<int> arr) {
    std::map<int, int> counter;

    int count = 0;
    for(auto v : arr) {
        count += (++counter[v] -1) + (++counter[v+k] - 1);
    }

    return count;
}


