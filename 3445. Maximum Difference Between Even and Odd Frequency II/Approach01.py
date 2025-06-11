class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        def getPermutations():
            permutations = []
            for charA in "01234":
                for charB in "01234":
                    if charA != charB:
                        permutations.append((charA, charB))
            return permutations

        maximumDifference = float('-inf')

        for charA, charB in getPermutations():
            minDifferenceByParity = [[float('inf')] * 2 for _ in range(2)]
            prefixCountA = [0]
            prefixCountB = [0]
            left = 0

            for right, ch in enumerate(s):
                prefixCountA.append(prefixCountA[-1] + (ch == charA))
                prefixCountB.append(prefixCountB[-1] + (ch == charB))

                while (right - left + 1 >= k and
                       prefixCountA[left] < prefixCountA[-1] and
                       prefixCountB[left] < prefixCountB[-1]):
                    currentMin = minDifferenceByParity[prefixCountA[left] % 2][prefixCountB[left] % 2]
                    minDifferenceByParity[prefixCountA[left] % 2][prefixCountB[left] % 2] = \
                        min(currentMin, prefixCountA[left] - prefixCountB[left])
                    left += 1

                currentDifference = (
                    (prefixCountA[-1] - prefixCountB[-1]) -
                    minDifferenceByParity[1 - (prefixCountA[-1] % 2)][prefixCountB[-1] % 2]
                )
                maximumDifference = max(maximumDifference, currentDifference)

        return maximumDifference
