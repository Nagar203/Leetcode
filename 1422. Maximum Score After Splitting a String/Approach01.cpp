#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero_cnt = 0;
        int one_cnt = 0;
        int cnt = 0;
        int sum = 0;

        while(s[cnt] != '\0'){
            if(s[cnt] == '1'){
                one_cnt++;
            }
            cnt++;
        }

        if(one_cnt == 0){
            return (n-1);
        }
    
        for(int i=0; i< n-1; i++){
            if(s[i] == '0'){
                zero_cnt++;
            }
            else{
                one_cnt--;
            }
            
            if(sum < (zero_cnt + one_cnt)){
                sum = zero_cnt + one_cnt;
            }

            cnt++;
        }
        return sum;
    }
};