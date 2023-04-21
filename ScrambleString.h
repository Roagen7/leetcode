#pragma once

#include <string>
#include <map>

using namespace std;

namespace ScrambleString {
    class Solution {
        map<pair<string, string>, bool> memo;

    public:
        bool isScramble(string s1, string s2) {
            if(s1 > s2){
                swap(s1, s2);
            }
            auto found = memo.find(make_pair(s1,s2));
            if(found != memo.end()){
                return found->second;
            }

            if(s1.length() != s2.length()) return false;
            if(s1 == s2) return true;

            bool flag = false;
            for(int i = 1; i < s1.length(); i++){
                auto s1x = s1.substr(0,i);
                auto s1y = s1.substr(i, s1.length());
                auto s2x = s2.substr(0, i);
                auto s2y = s2.substr(i, s2.length());

                auto s2a = s2.substr(s2.length() - i, i);
                auto s2b = s2.substr(0, s2.length() - i);

                flag = flag
                         || (isScramble(s1x, s2x) && isScramble(s1y, s2y))
                         || (isScramble(s1x, s2a) && isScramble(s1y, s2b));
            }

            memo.insert(make_pair(make_pair(s1, s2), flag));

            return flag;
        }
    };

    void tests(){
        auto v = Solution().isScramble("abcde", "caebd");
    }
}