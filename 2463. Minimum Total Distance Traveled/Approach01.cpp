#include <unordered_set>
#include <vector>

class Solution {
 public:
  long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
    ranges::sort(robots);
    ranges::sort(factories);

    vector<vector<vector<long>>> memo(
        robots.size(),
        vector<vector<long>>(factories.size(), vector<long>(robots.size()))
    );

    return calculateMinDistance(robots, factories, 0, 0, 0, memo);
  }

 private:
  // Calculates the minimum distance to repair robots[i..n) with factories[j..n),
  // where factories[j] has already repaired `repairedCount` robots.
  long calculateMinDistance(const vector<int>& robots,
                            const vector<vector<int>>& factories, int robotIndex,
                            int factoryIndex, int repairedCount,
                            vector<vector<vector<long>>>& memo) {
    if (robotIndex == robots.size())
      return 0;
    if (factoryIndex == factories.size())
      return LONG_MAX;
    if (memo[robotIndex][factoryIndex][repairedCount] > 0)
      return memo[robotIndex][factoryIndex][repairedCount];

    // Option to skip the current factory and try the next one
    const long skipCurrentFactory =
        calculateMinDistance(robots, factories, robotIndex, factoryIndex + 1, 0, memo);

    // Get the factory position and repair limit
    const int factoryPosition = factories[factoryIndex][0];
    const int repairLimit = factories[factoryIndex][1];

    // Option to use the current factory if the repair limit allows
    const long useCurrentFactory =
        repairLimit > repairedCount
            ? calculateMinDistance(robots, factories, robotIndex + 1, factoryIndex, repairedCount + 1, memo) +
                  abs(robots[robotIndex] - factoryPosition)
            : LONG_MAX / 2;

    // Memoize and return the minimum distance for this configuration
    return memo[robotIndex][factoryIndex][repairedCount] = min(skipCurrentFactory, useCurrentFactory);
  }
};