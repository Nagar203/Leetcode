class Solution:
    def reverseParentheses(self, s: str) -> str:
        open_parenthesis_indices = []
        result = []

        for c in s:
            if c == '(':
                open_parenthesis_indices.append(len(result))
            elif c == ')':
                start_index = open_parenthesis_indices.pop()
                result[start_index:] = reversed(result[start_index:])
            else:
                result.append(c)

        return ''.join(result)