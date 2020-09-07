//My solution to the challenge available at https://www.hackerrank.com/challenges/encryption/problem

struct mult {
    const int factor_a;
    const int factor_b;
    const int value;

    mult(int a, int b) : factor_a(a), factor_b(b), value(a*b){}
};

mult get_minimum_area(int size, int x, int y) {    
    mult operations[] = {{x,x}, {y,y}, {x,y}};

    mult* best = operations;

    for(auto& op : operations) {
        if(op.value >= size)
            if(op.value <= best->value || best->value < size)
                best = &op;
    }

    return *best;
}

// Complete the encryption function below.
string encryption(string s) {
    std::string s_stripped;

    for(auto& c : s) {
        s_stripped.push_back(c);
    }

    mult row_collumn = get_minimum_area(s_stripped.size(), std::floor(std::sqrt(s_stripped.size())), std::ceil(std::sqrt(s_stripped.size())));
    s_stripped.resize(row_collumn.value, ' ');

    std::string temp;
    temp.resize(row_collumn.value,' ');

    for(int row = 0; row < row_collumn.factor_a; ++row) {
        for(int collumn =0; collumn < row_collumn.factor_b;++collumn) {
            temp[collumn*row_collumn.factor_a + row] = s_stripped[row*row_collumn.factor_b + collumn];
        }
    }

    std::string result;
    for(size_t i = 0; i < temp.size(); ++i) {
        result.push_back(temp[i]);
        if((i+1) % row_collumn.factor_a == 0)
            if(result[result.size() -1] != ' ')
                result.push_back(' ');
    }

    return result;
}
