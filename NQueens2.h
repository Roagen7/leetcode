#pragma once
#pragma once

#include <string>
#include <vector>

using namespace std;

namespace NQueens2 {

    class Solution {
        int noSolutions = 0;

        bool canMakeMove(vector<string>& board, int y, int x){
            int n = board.size();

            for(int i = 0; i < n; i++){
                if(board[y][i] == 'Q'
                   || board[i][x] == 'Q'){
                    return false;
                }
            }

            int k = 0;
            while (x + k < n && y + k < n){
                if(board[y + k][x + k] == 'Q') return false;
                k++;
            }

            k = 0;
            while (x - k >= 0 && y - k >= 0){
                if(board[y - k][x - k] == 'Q') return false;
                k++;
            }

            k = 0;
            while (x + k < n && y - k >= 0){
                if(board[y - k][x + k] == 'Q') return false;
                k++;
            }

            k = 0;
            while (x - k >= 0 && y + k < n){
                if(board[y + k][x - k] == 'Q') return false;
                k++;
            }

            return true;
        }

        void makeMove(vector<string>& board, int queensToPlace){
            if(queensToPlace == 0){
                noSolutions++;
                return;
            }

            int x = queensToPlace - 1;
            for(int y = 0; y < board.size(); y++){
                if(board[y][x] == '.' && canMakeMove(board, y, x)){
                    board[y][x] = 'Q';
                    makeMove(board, queensToPlace-1);
                    board[y][x] = '.';
                }

            }


        }

    public:
        int totalNQueens(int n) {

            std::vector<string> board(n, string(n, '.'));

            makeMove(board, n);

            return noSolutions;
        }
    };

    void tests(){

        Solution sol;
        int y = sol.totalNQueens(4);
    }
}