#include <vector>
using namespace std;


namespace ProfitableSchemes {

    #define MAX 1000000007

    class Solution {

    private:
        int schemes[101][200][101] = {0};
        bool counted[101][200][101] = {false};

    public:
        int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit,
                              int currentIx = 0, int currentProfit = 0) {
            if(currentProfit > minProfit) currentProfit = minProfit + 1;
            if(currentIx == group.size()) return minProfit <= currentProfit ? 1 : 0;
            if(counted[n][currentProfit][currentIx])
                return schemes[n][currentProfit][currentIx];

            counted[n][currentProfit][currentIx] = true;
            schemes[n][currentProfit][currentIx] = profitableSchemes(n,
                                                                 minProfit,
                                                                 group,
                                                                 profit,
                                                                 currentIx+1,
                                                                 currentProfit) % MAX;
            if(n - group[currentIx] >= 0){
                schemes[n][currentProfit][currentIx] += profitableSchemes(n - group[currentIx],
                                                                      minProfit,
                                                                      group,
                                                                      profit,
                                                                     currentIx+1,
                                                                     currentProfit + profit[currentIx]) % MAX;
                schemes[n][currentProfit][currentIx] %= MAX;
            }

            return schemes[n][currentProfit][currentIx];

        }
    };

    void tests(){
        Solution solution;
        vector<int> group = {1,1,1,1,2,2,1,2,1,1};
        vector<int> profit = {0,1,0,0,1,1,1,0,2,2};

        int z = solution.profitableSchemes(1, 1, group, profit);
    }

}