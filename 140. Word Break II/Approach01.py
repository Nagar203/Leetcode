from typing import *

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict) 
        memo = {} 

        def solve(s):
            if s in memo:
                return memo[s]

            result = []
            for i in range(1, len(s)):
                prefix = s[:i]
                suffix = s[i:]
                if prefix in word_set:
                    for word in solve(suffix):
                        result.append(prefix + " " + word)

            if s in word_set:
                result.append(s)

            memo[s] = result
            return result

        return solve(s)

        