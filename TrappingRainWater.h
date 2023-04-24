#pragma once

#include <vector>
#include <iostream>


using namespace std;

namespace TrappingRainWater {
    class Solution {

    public:
        int trap(const vector<int>& height){
            int left = 0;
            int right = height.size() - 1;


            vector<int> levelsRight(height.size(), 0);
            vector<int> levelsLeft(height.size(), 0);

            int levelsMax = 0;
            for(int i = 0; i < height.size(); i++){
                levelsMax = max(height[i], levelsMax);
                levelsLeft[i] = levelsMax;
            }
            levelsMax = 0;
            for(int i = height.size() - 1; i >= 0; i--){
                levelsMax = max(height[i], levelsMax);
                levelsRight[i] = levelsMax;
            }

            int cells = 0;
            for(int i = 0; i < height.size() - 1; i++){
                cells += min(levelsRight[i], levelsLeft[i]) - height[i];
            }

            return cells;

        }

    };

    void tests(){
        Solution sol;
        int z = sol.trap({4,2,0,3,2,5});

    }
}