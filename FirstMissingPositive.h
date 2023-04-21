#pragma once

#include <vector>

using namespace std;

namespace FirstMissingPositive {
    class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            auto n = nums.size();

            for(auto i = 0u; i < n;i++){
                auto& x = nums[i];
                if(x >=1 && x <= n && nums[x-1] != x)
                    swap(nums[nums[i--]-1], x);
            }

            for(auto i = 0u; i < n; i++)
                if(nums[i] != i+1) return i+1;

            return n+1;
        }
    };

    void tests(){
        Solution sol;
        vector<int> data = {1,2,0};

        int x = sol.firstMissingPositive(data);

    }
}
