#include <bits/stdc++.h>

class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        queue<P> que;
        que.push({0, 0});
        que.push({firstPerson, 0});
        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;
        
        while(!que.empty()) {
            auto [person, time] = que.front();
            
            que.pop();
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && earlySecretTime[nextPerson] > t) {
                    earlySecretTime[nextPerson] = t;
                    que.push({nextPerson, t});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};