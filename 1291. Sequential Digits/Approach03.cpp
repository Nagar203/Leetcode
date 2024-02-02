#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> q;

        for(int i=1; i<=8; i++){
            q.push(i);
        }

        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(val > high){break;}
            if(val >= low and val <= high){
                result.push_back(val);
            }

            int next_digit = val%10 + 1;
            if(next_digit <= 9){
                q.push(val*10 + next_digit);
            }
        }
        return result;
    }
};