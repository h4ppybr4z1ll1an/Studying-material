//My solution to the problem found at https://www.hackerrank.com/challenges/ctci-big-o/problem


string primality(int n) {
    const std::string prime = "Prime";
    const std::string n_prime = "Not prime";
    
    if(n == 2 || n == 3 || n == 5) return prime;

    if(n % 2 == 0) return n_prime;

    if(n & 1 && n != 1) {            
        if(n % 6 == 5 || n % 6 == 1) {
            int n_sqr = sqrt(n);
            for(int i = 5; i <= n_sqr; i+=2) {
                if(n%i == 0)
                    return n_prime;
            }
            return prime;
        }
            
    }
    
    return n_prime;

}
