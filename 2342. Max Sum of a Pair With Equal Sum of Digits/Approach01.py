from collections import defaultdict

class Solution:
    def maximumSum(self, numbers):
        maxDigitSum = 81  # Maximum possible digit sum (9*9)
        maxPairSum = -1
        digitSumGroups = defaultdict(list)

        for number in numbers:
            digitSumGroups[self.calculateDigitSum(number)].append(number)

        for group in digitSumGroups.values():
            if len(group) < 2:
                continue
            group.sort(reverse=True)
            maxPairSum = max(maxPairSum, group[0] + group[1])

        return maxPairSum

    def calculateDigitSum(self, number):
        digitSum = 0
        while number > 0:
            digitSum += number % 10
            number //= 10
        return digitSum

