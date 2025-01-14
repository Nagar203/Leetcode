class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        commonPrefixCount = []

        # Iterate through each index and compute common elements in prefixes
        for i in range(n):
            prefixA = set(A[:i+1])
            prefixB = set(B[:i+1])
            commonPrefixCount.append(len(prefixA & prefixB))

        return commonPrefixCount