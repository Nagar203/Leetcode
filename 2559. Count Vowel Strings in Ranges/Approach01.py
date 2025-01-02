from typing import List

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowelsSet = {'a', 'e', 'i', 'o', 'u'}
        prefixSumArray = [0] * (len(words) + 1)

        # Compute prefix sums where prefixSumArray[i] indicates the count of valid words up to index i-1
        for index, word in enumerate(words):
            prefixSumArray[index + 1] = prefixSumArray[index] + (1 if word[0] in vowelsSet and word[-1] in vowelsSet else 0)

        # Process each query and calculate the count of valid words within the range
        resultList = []
        for queryStart, queryEnd in queries:
            resultList.append(prefixSumArray[queryEnd + 1] - prefixSumArray[queryStart])

        return resultList