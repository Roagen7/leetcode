#pragma once

#include <stack>
#include <iostream>

#include "utils/ListNode.h"

using namespace std;

namespace ReverseNodesInKGroups {
    class Solution {

    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            stack<ListNode*> sta;


            auto root = new ListNode();
            root->next = head;
            auto current = root;


            while(current != nullptr) {
                auto followup = current->next;
                for(int i = 0; i < k; i++){
                    if(followup == nullptr){
                        // handle edge case
                        head = root->next;
                        delete root;
                        return head;
                    }
                    sta.push(followup);
                    followup = followup->next;
                }

                while(!sta.empty()){
                    current->next = sta.top();
                    sta.pop();
                    current = current->next;
                }
                current->next = followup;
            }

            head = root->next;
            delete root;
            return head;
        }
    };

    void tests(){

        Solution solution;
        auto list = createList({1,2,3,4,5});
        auto out = solution.reverseKGroup(list, 3);

    }
}