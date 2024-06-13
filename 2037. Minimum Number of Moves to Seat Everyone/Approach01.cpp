#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int result = 0;

        ranges::sort(seats);
        ranges::sort(students);

        for (int i = 0; i < seats.size(); ++i)
            result += abs(seats[i] - students[i]);

        return result;
    }
};