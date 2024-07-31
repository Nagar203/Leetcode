#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // dp[i] represents the minimum height needed to place the first i books
        vector<int> dp(books.size() + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < books.size(); ++i) {
            int currentShelfWidth = 0;
            int currentShelfHeight = 0;
            // Try placing books from index j to i on the current shelf.
            for (int j = i; j >= 0; --j) {
                const int bookWidth = books[j][0];
                const int bookHeight = books[j][1];
                currentShelfWidth += bookWidth;
                if (currentShelfWidth > shelfWidth)
                    break; // Shelf width exceeded, cannot place more books on this shelf.
                currentShelfHeight = max(currentShelfHeight, bookHeight);
                dp[i + 1] = min(dp[i + 1], dp[j] + currentShelfHeight);
            }
        }

        return dp.back();
    }
};
