class Solution:
    def maxTotalFruits(self, fruits: list[list[int]], startPos: int, k: int) -> int:
        furthestFruitPos = max(startPos, fruits[-1][0])
        maxFruitsCollected = 0

        fruitAmounts = [0] * (furthestFruitPos + 1)
        prefixSum = [0] * (furthestFruitPos + 2)

        for position, amount in fruits:
            fruitAmounts[position] = amount

        for i in range(furthestFruitPos + 1):
            prefixSum[i + 1] = prefixSum[i] + fruitAmounts[i]

        def collectFruits(leftSteps, rightSteps):
            leftBound = max(0, startPos - leftSteps)
            rightBound = min(furthestFruitPos, startPos + rightSteps)
            return prefixSum[rightBound + 1] - prefixSum[leftBound]

        # Move right first
        maxRightSteps = min(furthestFruitPos - startPos, k)
        for rightSteps in range(maxRightSteps + 1):
            leftSteps = max(0, k - 2 * rightSteps)
            maxFruitsCollected = max(maxFruitsCollected, collectFruits(leftSteps, rightSteps))

        # Move left first
        maxLeftSteps = min(startPos, k)
        for leftSteps in range(maxLeftSteps + 1):
            rightSteps = max(0, k - 2 * leftSteps)
            maxFruitsCollected = max(maxFruitsCollected, collectFruits(leftSteps, rightSteps))

        return maxFruitsCollected