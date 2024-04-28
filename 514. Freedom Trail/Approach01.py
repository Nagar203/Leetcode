class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        char_indices = {}
        for i, char in enumerate(ring):
            if char not in char_indices:
                char_indices[char] = []
            char_indices[char].append(i)

        memo = {}

        def dfs(ring_index: int, key_index: int) -> int:
            if key_index == len(key):
                return 0

            if (ring_index, key_index) in memo:
                return memo[(ring_index, key_index)]

            min_steps = float("inf")

            for next_ring_index in char_indices[key[key_index]]:
                steps = abs(next_ring_index - ring_index)
                steps = min(steps, len(ring) - steps)
                remaining_steps = dfs(next_ring_index, key_index + 1)
                min_steps = min(min_steps, steps + remaining_steps)
            memo[(ring_index, key_index)] = min_steps

            return min_steps

        return dfs(0, 0) + len(key)
