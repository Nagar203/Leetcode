#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        vector<int> winner, loser;

        for(int i=0; i<n; i++){
            winner.push_back(matches[i][0]);
            loser.push_back(matches[i][1]);
        }

        unordered_map<int, int> win_mp, los_mp;
        for(int i=0; i<n; i++){
            win_mp[winner[i]]++;
            los_mp[loser[i]]++;
        }

        winner.clear();
        loser.clear();
        vector<vector<int>> result;

        for(auto it=win_mp.begin(); it!=win_mp.end(); it++){
            if( los_mp.find(it->first) == los_mp.end() ){
                winner.push_back(it->first);
            }
        }

        for(auto it=los_mp.begin(); it!=los_mp.end(); it++){
            if(it->second == 1){
                loser.push_back(it->first);
            }
        }
        sort(winner.begin(), winner.end());
        sort(begin(loser), end(loser));
        result.push_back(winner);
        result.push_back(loser);
        return result;
    }
};