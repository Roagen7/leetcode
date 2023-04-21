#pragma once

#include <vector>

#include "utils/ListNode.h"

using namespace std;

namespace MergeKSortedLists {

    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {

            if(lists.empty()){
                return nullptr;
            }

            auto out = new ListNode();
            auto current = out;

            bool finished = false;

            while(!finished){

                finished = true;
                auto chosen_ix = 0u;
                int min = INT_MAX;

                for(auto i = 0u; i < lists.size(); i++){
                    auto& list = lists[i];
                    if(lists[i] != nullptr){
                        finished = false;
                        if(list->val < min){
                            min = list->val;
                            chosen_ix = i;
                        }
                    }
                }

                if(finished) continue;

                current->next = new ListNode(min);
                current = current->next;
                lists[chosen_ix] = lists[chosen_ix]->next;
            }

            return out->next;
        }
    };

    void tests(){

        Solution sol;
        auto list1 = new ListNode(1);
        list1->next = new ListNode(4);
        list1->next->next = new ListNode(5);
        auto list2 = new ListNode(1);
        list2->next = new ListNode(3);
        list2->next->next = new ListNode(4);
        auto list3 = new ListNode(2);
        list3->next = new ListNode(6);

        vector<ListNode*> lists;
        lists.push_back(nullptr);
//        lists.push_back(list1);
//        lists.push_back(list2);
//        lists.push_back(list3);

        auto y = sol.mergeKLists(lists);
    }
}
