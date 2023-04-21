#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace PermutationSequence {
    class Solution {
        int factorial(int n){
            if(n == 0) return 1;
            return n * factorial(n-1);
        }



        bool isIn[10] = {0};


    public:
        string getPermutation(int n, int k) {
            if(n == 0){
                return "";
            }

            int f = factorial(n-1);
            int c = (k+f-1)/f;

            int i = 0;
            int counter = 0;

            while(counter != c){
                i++;
                if(!isIn[i]) {
                    counter++;
                }
            }

            char num = i + '0';
            isIn[i] = true;
            return num + getPermutation(n-1, k - (c-1) * f);
        }
    };

    void tests(){
        Solution sol;
        string per = sol.getPermutation(3, 1);
    }
}