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
    bool isPalindrome(ListNode* head) {
        vector<int> result;
        if(!head){
            return true;
        }

        while(head){
            result.push_back(head->val);
            head = head->next;
        }

        int n = result.size();
        return equal(result.begin(), result.begin() + n/2, result.rbegin());
    }
};