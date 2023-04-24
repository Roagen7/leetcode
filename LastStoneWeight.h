#pragma once

#include <vector>

using namespace std;

namespace LastStoneWeight {

            class Solution {
            public:
                int lastStoneWeight(vector<int>& stones) {
                    sort(stones.begin(), stones.end());

                    for(auto n = stones.size(); n > 1; n--){
                        auto stoneX = stones[n-1];
                        auto stoneY = stones[n-2];
                        stones.pop_back();
                        stones.pop_back();

                        if(stoneX == stoneY){
                            n--;
                            continue;
                        }
                        int newStone = stoneX > stoneY ? stoneX - stoneY : stoneY - stoneX;
                        stones.push_back(newStone);
                        sort(stones.begin(), stones.end());
                    }

                    if(stones.empty()) return 0;
                    return stones[0];
                }
            };

    void tests(){
        Solution sol;
        vector<int> y = {2,2};
        int z = sol.lastStoneWeight(y);

    }
}