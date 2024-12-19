#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunksCount = 0;
        int maxElement = INT_MIN;

        for (int currentIndex = 0; currentIndex < arr.size(); ++currentIndex) {
            maxElement = max(maxElement, arr[currentIndex]);
            if (maxElement == currentIndex) {
                ++chunksCount;
            }
        }

        return chunksCount;
    }
};