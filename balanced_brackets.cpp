// My solution to the problem at https://www.hackerrank.com/challenges/balanced-brackets/problem

string isBalanced(string s) {
    std::unordered_map<char, char> pairs{
        {'(',')'},
        {'{', '}'},
        {'[', ']'}
    };

    std::stack<char> stack;

    for(auto c : s) {
        auto it = pairs.find(c);
        if(it != pairs.end()) {
            stack.push(c);
        }
        else {
            if(stack.size() == 0 || c != pairs[stack.top()])
                return "NO";
            else
                stack.pop();
        }
    }

    if(stack.size() == 0)
        return "YES";    
    
    return "NO";
}
