#pragma once

#include <vector>
#include <string>

using namespace std;

namespace SubstringWithConcatenationOfAllWords {
    class Solution {
    public:
        vector<int> findSubstring(string s, vector<string> words) {
            std::vector<int> ixes;

            std::sort(words.begin(), words.end());
            int wordSize = words[0].size();
            int substringLength = wordSize * words.size();
            int len = s.length();

            for(int i = 0; i <= len - substringLength; i++){
                string sub = s.substr(i, substringLength);
                bool isValid = true;

                std::vector<string> parts;
                for(int j = 0; j < sub.length(); j+= wordSize){
                    parts.push_back(sub.substr(j,wordSize));
                }
                std::sort(parts.begin(), parts.end());
                if(parts == words){
                    ixes.push_back(i);
                }

            }
            return ixes;
        }
    };

    void tests(){
        Solution sol;
        vector<std::string> words = {"a","a"};

        auto y = sol.findSubstring("a", words);

    }
}