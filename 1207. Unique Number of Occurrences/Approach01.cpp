#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int data[2001] = {0};
        int n = arr.size();
        for(auto &it: arr){
            if(it < 0){
                it += 1000;
            }
            data[it]++;
        }
        sort(data, data+2001);

        set<int> s;
        for(int i=1; i<2001; i++){
            if(data[i] != 0 and data[i] == data[i-1]){
                return false;
            }
        }
        return true;
    }
};