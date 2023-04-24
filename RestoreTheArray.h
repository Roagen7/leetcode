#pragma once

#include <string>

using namespace std;

namespace RestoreTheArray {
    class Solution {
        #define MAX 1000000007

        int dp[100000] = {0 };

        int dfs(string& s, const int& k, int ix){

            if(ix == s.length()) return 1;
            if(dp[ix] != -1) return dp[ix];

            int num = 0;
            int count = 0;
            int y = ix;

            for(const auto& c : s.substr(ix, s.length())){
                num *= 10;
                num += c - '0';
                if(num <= 0 || num > k) break;
                count = (count + dfs(s, k, ++y)) % MAX;
            }

            dp[ix] = count;
            return count;
        }

    public:
        int numberOfArrays(string& s, int k) {
            for(int & i : dp) i = -1;
            int z = dfs(s, k, 0);
            return z;
        }
    };

    void tests(){
        Solution sol;
        sol.numberOfArrays("1000", 10);
    }

}