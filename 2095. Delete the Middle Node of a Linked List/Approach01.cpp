#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return NULL;
        }
        ListNode *slow = head, *fast = head, *prev;
        while(fast != NULL and fast->next != NULL){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete(slow);
        return head;
    }
};