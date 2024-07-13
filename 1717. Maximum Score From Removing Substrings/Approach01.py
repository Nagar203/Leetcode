





class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x > y:
            return self.calculate_gain(s, "ab", x, "ba", y)
        else:
            return self.calculate_gain(s, "ba", y, "ab", x)

    def calculate_gain(self, s: str, first_pair: str, first_points: int, second_pair: str, second_points: int) -> int:
        total_points = 0
        first_stack = []
        second_stack = []

        for c in s:
            if first_stack and first_stack[-1] == first_pair[0] and c == first_pair[1]:
                first_stack.pop()
                total_points += first_points
            else:
                first_stack.append(c)

        for c in first_stack:
            if second_stack and second_stack[-1] == second_pair[0] and c == second_pair[1]:
                second_stack.pop()
                total_points += second_points
            else:
                second_stack.append(c)

        return total_points
