#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL or head->next == NULL or head->next->next == NULL){
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while(slow != fast){
            if(slow == NULL or fast == NULL) return false;
            slow = slow->next;
            if(fast->next == NULL) return false;
            fast = fast->next->next;
        }
        return true;
    }
};