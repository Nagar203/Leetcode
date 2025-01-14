#include <vector>
#include <unordered_set>
#include <algorithm> // for set_intersection
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> commonPrefixCount;

        // Iterate through each index and compute common elements in prefixes
        for (int i = 0; i < n; ++i) {
            unordered_set<int> prefixA(A.begin(), A.begin() + i + 1);
            unordered_set<int> prefixB(B.begin(), B.begin() + i + 1);
            
            // Calculate the intersection of the sets
            unordered_set<int> intersection;
            for (const auto& elem : prefixA) {
                if (prefixB.find(elem) != prefixB.end()) {
                    intersection.insert(elem);
                }
            }
            
            // Add the size of the intersection to the result
            commonPrefixCount.push_back(intersection.size());
        }

        return commonPrefixCount;
    }
};