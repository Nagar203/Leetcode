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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt = 0;
        ListNode* list2_last_node;
        ListNode* checkList = list2;

        while(checkList != NULL){
            list2_last_node = checkList;
            checkList = checkList->next;
        }

        cout<<list2_last_node->next;

        ListNode* prev;
        ListNode* temp;
        temp = list1;

        while(temp != NULL){
            if(cnt == a){
                prev->next = list2;
            }
            if(cnt == b){
                list2_last_node->next = temp->next;
            }
            prev = temp;
            temp = temp->next;
            cnt++;
        }

        return list1;
    }
};