/*
Solution to the challenge available at: 
https://www.testdome.com/d/cpp-interview-questions/7

Description:

Implement function countNumbers that accepts a sorted vector of unique integers and, efficiently with respect to time used, counts the number of vector elements that are less than the parameter lessThan.

For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should return 2 because there are two vector elements less than 4.
*/


#include <iostream>
#include <string>
#include <vector>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{

    if (sortedVector.size()) {

        auto low_bound = sortedVector.begin() -1;
        auto high_bound = sortedVector.end();
        auto pivot = low_bound + (high_bound - low_bound)/2;
        
        while (high_bound - low_bound != 1) {   
            int val = *pivot;

            if (val == lessThan) 
                return pivot - sortedVector.begin();
            
            if (val > lessThan) {
                high_bound = pivot;
                pivot = low_bound + (high_bound - low_bound)/2;
                continue;
            }
            if (val < lessThan) {
                low_bound = pivot;
                pivot = low_bound + (high_bound - low_bound)/2;
                continue;
            }

        }

        return pivot - (sortedVector.begin()-1);

    }

    return 0;
}

int main()
{
    std::vector<int> v{ 1,2, 3,4, 5, 7 };
    std::cout << countNumbers(v, 4);
}

