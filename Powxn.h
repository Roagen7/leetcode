#pragma once

namespace Powxn {
    class Solution {
    public:
        double myPow(double x, int n, bool first= true) {

            if(n == 0){
                return 1;
            } else if(n < 0 && first){
                x = 1/x;
            }

            double halfPow = myPow(x, n/2, false);
            if(n % 2 == 0)
                return halfPow * halfPow;

            return x * halfPow * halfPow;
        }
    };

    void tests(){
        Solution sol;
        double y = sol.myPow(2.00000, -2);

    }

}

