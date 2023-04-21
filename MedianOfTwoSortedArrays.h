#pragma once

#include <vector>
using namespace std;

namespace MedianOfTwoSortedArrays {
    class Solution {
    public:

        double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
            // merge
            vector<int> merged;
            auto n  = nums1.size() + nums2.size();
            merged.reserve(n);

            auto piv2 = 0u;
            auto piv1 = 0;

            while(piv1 != nums1.size() && piv2 != nums2.size()){
                if(nums1[piv1] < nums2[piv2]){
                    merged.push_back(nums1[piv1]);
                    piv1 += 1;
                } else {
                    merged.push_back(nums2[piv2]);
                    piv2 += 1;
                }
            }

            auto pivot = piv1 == nums1.size() ? piv2 : piv1;
            auto notPivot = piv1 == nums1.size() ? piv1 : piv2;
            auto& unconsumed =  piv1 == nums1.size() ? nums2 : nums1;

            while(pivot + notPivot != n){
                merged.push_back(unconsumed[pivot]);
                pivot++;
            }

            if(n % 2 == 0){
                return ((double) merged[n/2 - 1] + (double) merged[n/2])/2;
            }

            return merged[n/2];

        }
    };

    void tests(){
        Solution sol;
        double s = sol.findMedianSortedArrays({1,2}, {3,4});
    }
}
