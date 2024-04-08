#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& student, vector<int>& sand) {
        int n = student.size();
        int arr[2] = {0};
                  
        for(int &x : student)
            arr[x]++;
        
        for(int i = 0; i<n; i++) {
            if(arr[sand[i]] == 0) return n-i;
            arr[sand[i]]--;
        }
        
        return 0;
    }
};