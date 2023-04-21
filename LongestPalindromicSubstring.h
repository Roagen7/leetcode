#pragma once

#include <vector>
#include <string>

using namespace std;

namespace LongestPalindromicSubstring {

    class Solution {
    public:

        bool isPalindrome(const string& s){
            for(int i = 0; i < s.length()/2; i++){
                if(s[i] != s[s.length() - i - 1]) return false;
            }

            return true;
        }

        string longestPalindrome(const string& s) {
            auto max = 0u;
            auto n = s.length();
            string longest = "";

            for(int i = 0; i < n; i++){

                int left = i;
                int right = i;
                while(left >= 0 && right <= s.length() - 1 && s[left] == s[right]){
                    left--;
                    right++;
                }
                if(right - left - 1 > max){
                    max = right - left - 1;
                    longest = s.substr(left + 1, max);
                }

                right = i+1;
                left = i;

                while(left >= 0 && right <= s.length() - 1 && s[left] == s[right]){
                    left--;
                    right++;
                }
                if(right - left - 1 > max){
                    max = right - left - 1;
                    longest = s.substr(left + 1, max);
                }

            }

            return longest;
        }
    };

    void tests() {
        Solution sol;
        auto s = sol.longestPalindrome("babad");
    }
}