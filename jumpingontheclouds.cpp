//My submission to a challenge on HackerRank that can be seen on the link below
//https://www.hackerrank.com/challenges/jumping-on-the-clouds

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {

    int jumps = 0;
    int curr_pos = 0;
    while(curr_pos != c.size() -1) {
        if(curr_pos + 2 < c.size()) {
            if(c.at(curr_pos +2) == 0) {
                curr_pos += 2;
                ++jumps;
                continue;
            }
            else if(c.at(curr_pos +1) == 0) {
                ++curr_pos;
                ++jumps;
                continue;
            }
        }
        else {
            if(c.at(curr_pos + 1) == 0) {
                ++curr_pos;
                ++jumps;
                continue;
            }
        }
    }
    return jumps;
}
