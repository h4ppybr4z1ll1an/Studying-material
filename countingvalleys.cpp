//My answer to the a challenge in HackerRank on the link below
//https://www.hackerrank.com/challenges/counting-valleys/problem

#include <iostream>
#include <string>
using namespace std;

int countingValleys(int n, string s) {

    int valleys = 0;
    
    int y_axis = 0; //Sea level, Gary beguns here

    auto crossed_sea_level = [&y_axis](char c)-> int{return (y_axis == 0 && c == 'D');};

    for(char c : s) {
        valleys += crossed_sea_level(c);
        y_axis += c == 'D' ? -1 : 1;
    }

    return valleys;
}
