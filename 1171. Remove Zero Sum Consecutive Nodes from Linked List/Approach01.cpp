#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefix_sum = 0;
        unordered_map<int, ListNode*> mp;
        ListNode* result = new ListNode(0);
        result->next = head;
        mp[0] = result;

        while(head){
            prefix_sum += head->val;
            if(mp.find(prefix_sum) != mp.end()){
                ListNode* P = mp[prefix_sum];
                ListNode* start = P;
                int P_sum = prefix_sum;
                while(start != head){
                    start = start->next;
                    P_sum += start->val;
                    if(start != head){
                        mp.erase(P_sum);
                    }
                }
                P->next = start->next;
            }
            else{
                mp[prefix_sum] = head;
            }
            head = head->next;
        }
        return result->next;
    }
};