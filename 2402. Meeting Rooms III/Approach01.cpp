#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings)); 

        vector<int> rooms_used_count(n, 0); 
        vector<long long> last_available_info(n, 0); 
        

        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];
            bool found = false;

            long long early_end_room_time = LLONG_MAX;
            int early_end_room = 0;

            for(int room = 0; room < n; room++) {
                if(last_available_info[room] <= start) {
                    found = true;
                    last_available_info[room] = end;
                    rooms_used_count[room]++;
                    break;
                }

                if(last_available_info[room] < early_end_room_time) {
                    early_end_room = room;
                    early_end_room_time = last_available_info[room];
                }
            }

            if(!found) {
                last_available_info[early_end_room] += (end - start);
                rooms_used_count[early_end_room]++;
            }

        }

        int result_room = -1;
        int max_use     = 0;  
        for(int room = 0; room < n; room++) {
            if(rooms_used_count[room] > max_use) {
                max_use = rooms_used_count[room];
                result_room = room;
            }
        }

        return result_room;
    }
};