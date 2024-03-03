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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        
        if(cnt == n){
            ListNode* prev = NULL;
            prev = head->next;
            delete(head);
            head = prev;
            return head;
        }
        temp = head;
        ListNode* prev = NULL;
        int target = cnt-n+1;
        cnt = 0;
        
        while(temp!=NULL){
            cnt++;
            if(cnt == target){
                prev->next = temp->next;
                delete(temp);
                break;
            }
            prev = temp;
            temp = temp->next;            
        }
        return head;

    }
};