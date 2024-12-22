#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct IndexedQuery {
    int queryIndex;
    int aliceIndex; // Alice's index
    int bobIndex;   // Bob's index

    IndexedQuery(int qIndex, int a, int b)
        : queryIndex(qIndex), aliceIndex(a), bobIndex(b) {}

    bool operator<(const IndexedQuery &other) const {
        return bobIndex > other.bobIndex;
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int> &buildingHeights, vector<vector<int>> &queries) {
        vector<int> results(queries.size(), -1);
        vector<int> monotonicStack;

        int buildingIndex = buildingHeights.size() - 1;
        vector<IndexedQuery> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            int aliceIndex = min(queries[i][0], queries[i][1]);
            int bobIndex = max(queries[i][0], queries[i][1]);
            sortedQueries.emplace_back(i, aliceIndex, bobIndex);
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        for (const auto &query : sortedQueries) {
            int queryIndex = query.queryIndex;
            int aliceIndex = query.aliceIndex;
            int bobIndex = query.bobIndex;

            if (aliceIndex == bobIndex || buildingHeights[aliceIndex] < buildingHeights[bobIndex]) {
                results[queryIndex] = bobIndex;
            } else {
                while (buildingIndex > bobIndex) {
                    while (!monotonicStack.empty() && buildingHeights[monotonicStack.back()] <= buildingHeights[buildingIndex]) {
                        monotonicStack.pop_back();
                    }
                    monotonicStack.push_back(buildingIndex);
                    --buildingIndex;
                }

                int lastGreaterIndex = lastGreater(monotonicStack, aliceIndex, buildingHeights);
                if (lastGreaterIndex != -1) {
                    results[queryIndex] = monotonicStack[lastGreaterIndex];
                }
            }
        }

        return results;
    }

private:
    int lastGreater(const vector<int> &indexList, int targetIndex, const vector<int> &buildingHeights) {
        int left = -1, right = indexList.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (buildingHeights[indexList[mid]] > buildingHeights[targetIndex]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};