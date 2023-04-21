#pragma once

#include <map>
#include <vector>
#include <cmath>

#include "utils/TreeNode.h"

using namespace std;

namespace MaximumWidthOfBinaryTree {

    class Solution {

        vector<unsigned int> minValues;
        vector<unsigned int> maxValues;

        void getFarthestNodes(TreeNode* root, int depth = 0, unsigned int right = 0){
            if(root == nullptr) return;

            unsigned int leftIx = right;
            unsigned int rightIx = right + 1;

            if(minValues.size() <= depth){
                minValues.push_back(INT_MAX);
            }
            if(maxValues.size() <= depth){
                maxValues.push_back(0);
            }
            if(minValues[depth] > leftIx && root->left != nullptr){
                minValues[depth] = leftIx;
            }
            if(minValues[depth] > rightIx && root->right != nullptr){
                minValues[depth] = rightIx;
            }
            if(maxValues[depth] < rightIx && root->right != nullptr){
                maxValues[depth] = rightIx;
            }
            if(maxValues[depth] < leftIx && root->left != nullptr){
                maxValues[depth] = leftIx;
            }

            getFarthestNodes(root->left, depth+1, 2*leftIx);
            getFarthestNodes(root->right, depth+1,  2*rightIx);
        }

    public:
        int widthOfBinaryTree(TreeNode* root) {
            getFarthestNodes(root);
            unsigned int max = 0;

            for(int i = 0; i < maxValues.size() - 1; i++) {
                if(maxValues[i] - minValues[i] > max){
                    max = maxValues[i] - minValues[i];
                }
            }
            return max + 1;
        }

    };

    void tests(){
        Solution sol;
        TreeNode root(1,
                       new TreeNode(3, new TreeNode(5), new TreeNode(3)),
                       new TreeNode(2, nullptr, new TreeNode(9))
                      );


        int y = sol.widthOfBinaryTree(&root);
    }

}