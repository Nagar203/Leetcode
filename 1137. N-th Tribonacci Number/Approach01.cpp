#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int n0 = 0;
        int n1 = 1;
        int n2 = 1;

        if (n == 0) {
            return n0;
        } else if (n == 1) {
            return n1;
        } else if (n == 2) {
            return n2;
        }

        for (int i = 3; i < n + 1; i++) {
            int total = n0 + n1 + n2;
            n0 = n1;
            n1 = n2;
            n2 = total;
        }
        return n2;
    }
};