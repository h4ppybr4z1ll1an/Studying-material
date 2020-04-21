//My FizzBuzz solution.

#include <iostream>
#include <string>
#include <map>
int main()
{
    std::map<int, std::string> numbers{
        {3,"Fizz"},
        {5, "Buzz"}
    };

    for (int i = 0; i < 100; ++i) {
        std::string to_print;
        
        for (auto& val : numbers) 
            if (!(i % val.first) && i > 0) 
                to_print += val.second;
            
        if (!to_print.size())
            to_print += std::to_string(i);

        std::cout << to_print << "\n";

    }

}
