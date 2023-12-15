#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int row  = paths.size();
        unordered_map<string, int> mp;

        for(int i=0; i < row; i++){
            if(mp.find(paths[i][1]) != mp.end()){
                mp[paths[i][1]]  += 1;
            }
            else{
                mp[paths[i][1]] = 1;
            }
            
            if(mp.find(paths[i][0]) != mp.end()){
                mp[paths[i][0]] += 1;
            }
            else{
                mp[paths[i][0]] = 1;
            }
        }
        vector<string> result;
        for(auto i: mp){
            if(i.second == 1){
                result.push_back(i.first);
            }
        }

        for(int i = 0; i < row; i++){
            if(result[0] == paths[i][0]){
                return result[1]; 
            }
        }

        return result[0];
    }
};