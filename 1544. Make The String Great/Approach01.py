class Solution:
    def makeGood(self, data: str) -> str:
        result = []
        for ch in data:
            if result and (ord(result[-1]) - ord('A') == ord(ch) - ord('a') or ord(result[-1]) - ord('a') == ord(ch) - ord('A')):
                result.pop()
            else:
                result.append(ch)
        return ''.join(result)
