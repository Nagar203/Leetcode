#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        int check = -1;

        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            int val = arr[i];

            if(mp.find(val) != mp.end()){
                mp[val] += 1;
            }
            else{
                mp[val] = 1;
            }
        }

        for(auto i = mp.begin(); i != mp.end(); i++){
            if(i->second > check){            
                result = i->first;
                check = i->second;
            }
        }
        
        return result;
    }
};