#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode* createList(std::vector<int> vi){
    auto head = new ListNode(vi[0]);
    auto current = head;

    for(int i = 1; i < vi.size(); i++){
        current->next = new ListNode(vi[i]);
        current = current->next;
    }

    return head;
}

