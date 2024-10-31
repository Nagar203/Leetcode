from typing import *

class Solution:
    def minimumTotalDistance(self, robots, factories):
        robots.sort()
        factories.sort()

        memo = [[[None] * len(robots) for _ in range(len(factories))] for _ in range(len(robots))]

        return self.calculateMinDistance(robots, factories, 0, 0, 0, memo)

    # Helper function to calculate minimum distance
    def calculateMinDistance(self, robots, factories, robotIndex, factoryIndex, repairedCount, memo):
        if robotIndex == len(robots):
            return 0
        if factoryIndex == len(factories):
            return float('inf')
        if memo[robotIndex][factoryIndex][repairedCount] is not None:
            return memo[robotIndex][factoryIndex][repairedCount]

        # Option to skip the current factory and try the next one
        skipCurrentFactory = self.calculateMinDistance(robots, factories, robotIndex, factoryIndex + 1, 0, memo)

        # Get the factory position and repair limit
        factoryPosition = factories[factoryIndex][0]
        repairLimit = factories[factoryIndex][1]

        # Option to use the current factory if the repair limit allows
        useCurrentFactory = (
            self.calculateMinDistance(robots, factories, robotIndex + 1, factoryIndex, repairedCount + 1, memo)
            + abs(robots[robotIndex] - factoryPosition)
            if repairLimit > repairedCount else float('inf')
        )

        # Memoize and return the minimum distance for this configuration
        memo[robotIndex][factoryIndex][repairedCount] = min(skipCurrentFactory, useCurrentFactory)
        return memo[robotIndex][factoryIndex][repairedCount]