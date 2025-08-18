class Solution:
    def judgePoint24(self, numbers):
        doubleNumbers = [float(num) for num in numbers]
        return self.canMake24(doubleNumbers)

    def canMake24(self, currentNumbers):
        if len(currentNumbers) == 1:
            return abs(currentNumbers[0] - 24) < 0.001

        for i in range(len(currentNumbers)):
            for j in range(i):
                for result in self.generateResults(currentNumbers[i], currentNumbers[j]):
                    nextRound = [result]
                    for k in range(len(currentNumbers)):
                        if k == i or k == j:  # Skip used numbers
                            continue
                        nextRound.append(currentNumbers[k])
                    if self.canMake24(nextRound):
                        return True
        return False

    def generateResults(self, numA, numB):
        results = [numA * numB, numA + numB, numA - numB, numB - numA]
        if abs(numB) > 1e-6:  # Avoid division by zero
            results.append(numA / numB)
        if abs(numA) > 1e-6:  # Avoid division by zero
            results.append(numB / numA)
        return results
