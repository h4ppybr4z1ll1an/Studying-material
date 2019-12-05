//My solution to the problem found at https://www.hackerrank.com/challenges/2d-array/problem

#include <vector>
int hourglassSum(std::vector<std::vector<int>> v) {
    
    int arr[6][6];

    {
        int i = 0;
        int j = 0;
        
        for(std::vector<int> x : v) {
            for(int y : x) { arr[i][j] = y; ++j;}
        }
        ++i;
    }

    int max;

    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {

            int hourglass = arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                                        arr[i+1][j+1] +
                            arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            
            if(i == 0 && j == 0)
                max = hourglass;
            else 
                max = hourglass > max ? hourglass : max;
                
        }
    }

    return max;

}
