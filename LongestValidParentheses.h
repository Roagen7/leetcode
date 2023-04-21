#pragma once

#include <string>

using namespace std;

namespace LongestValidParentheses {
    class Solution {
    public:
        int longestValidParentheses(const string& s) {
            int max = 0;

            for(int i = 0; i < s.length(); i++){

                auto sub = s.substr(i, s.length());
                int par = 0;
                int currentStreak = 0;


                for(const char& c : sub){
                    if(c == ')'){
                        par -= 1;
                    } else {
                        par += 1;
                    }

                    currentStreak ++;
                    if(par == 0 && currentStreak > max){
                        max = currentStreak;
                    } else if(par < 0){
                        currentStreak = 0;
                        par = 0;
                    }
                }
            }

            return max;
        }
    };

    void tests(){
        Solution solution;
        int x = solution.longestValidParentheses("");
    }
}
