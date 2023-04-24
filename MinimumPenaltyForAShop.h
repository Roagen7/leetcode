#pragma once

#include <string>

using namespace std;

namespace MinimumPenaltyForAShop {
    class Solution {


    public:
        int bestClosingTime(const string& customers) {
            int ytotal = 0;
            int ntotal = 0;

            for (const auto &c: customers) {
                if (c == 'Y') ytotal += 1;
                else ntotal += 1;
            }

            int minPenalty = INT_MAX;
            int minHour = 0;

            int yc = 0;
            int nc = 0;

            for (int i = 0; i < customers.length(); i++) {
                int penalty = nc + (ytotal - yc);

                if (penalty < minPenalty) {
                    minPenalty = penalty;
                    minHour = i;
                }

                if (customers[i] == 'Y') yc++;
                else nc++;
            }

            if (ntotal < minPenalty)
                return customers.length();

            return minHour;
        }
    };

    void tests(){
        Solution sol;
        int z = sol.bestClosingTime("YYYY");

    }
}