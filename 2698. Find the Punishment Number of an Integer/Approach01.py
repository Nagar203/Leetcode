class Solution:
    def punishmentNumber(self, n: int) -> int:
        def can_partition(s, target, index, curr_sum):
            if index == len(s):
                return curr_sum == target
            temp_sum = 0
            for j in range(index, len(s)):
                temp_sum = temp_sum * 10 + int(s[j])
                if temp_sum + curr_sum > target:
                    break
                if can_partition(s, target, j + 1, curr_sum + temp_sum):
                    return True
            return False

        result = 0
        for i in range(1, n + 1):
            square_str = str(i * i)
            if can_partition(square_str, i, 0, 0):
                result += i * i
                
        return result