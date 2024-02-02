#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int get_digits(int n){
        int result = 0;
        while(n){
            result++;
            n = n/10;
        }
        return result;
    }
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int n_low = get_digits(low);
        int n_high = get_digits(high);
        vector<int> result;
        int cnt = n_low;

        while(cnt<=n_high){
            for(int i=0; i<(10-cnt); i++){
                int val = stoi(s.substr(i, cnt));
                if(val >= low and val<= high){
                    result.push_back(val);
                }

            }
            cnt++;
        }
        return result;
    }
};