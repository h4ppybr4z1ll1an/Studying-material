#My solution to the problem at: https://www.hackerrank.com/challenges/countingsort4/problem

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countSort function below.
def countSort(arr):
    map = {}
    for idx, pair in enumerate(arr, start = 1):
        if idx <= len(arr)/2:
            pair[1] = '-'
        if not int(pair[0]) in map:
            map[int(pair[0])] = [pair[1]]
        else:
            map[int(pair[0])].append(pair[1])
    
            
    map_keys = sorted(map.keys())
    for key in map_keys:
        for text in map[key]:
            print(text, end = ' ')
        
    

if __name__ == '__main__':
    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(input().rstrip().split())

    countSort(arr)
