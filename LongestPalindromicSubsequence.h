#pragma once
#include <string>
#include <vector>

using namespace std;

namespace LongestPalindromicSubsequence {
    class Solution {
    private:
        int dp[1000][1000] = {0};

        int dfs(const string& s, int left, int right){
            if(left == right) return 1;
            if(left > right) return 0;
            if(dp[left][right]) return dp[left][right];
            if(s[left] == s[right]) {
                dp[left][right] = 2 + dfs(s, left+1, right-1);
            } else {
                dp[left][right] = max(dfs(s, left, right-1), dfs(s, left+1, right));
            }
            return dp[left][right];
        }

    public:
        int longestPalindromeSubseq(string s) {
            return dfs(s, 0, s.length()-1);
        }
    };

    void tests(){
        Solution sol;
        int z = sol.longestPalindromeSubseq("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
    }
}
