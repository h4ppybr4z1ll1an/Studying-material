// My submission to the challenge at https://www.hackerrank.com/challenges/angry-children/problem

int maxMin(int k, vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    int minimum_unfairness;

    for(size_t i = 0; i < arr.size() - k + 1; ++i) {
        if(i == 0)  {
            minimum_unfairness = arr[i+k-1] - arr[i];
            continue;
        }

        int max_min = arr[i+k-1] - arr[i];
        
        if(max_min < minimum_unfairness)
            minimum_unfairness = max_min;        
    }

    return minimum_unfairness;
}
