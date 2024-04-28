class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        return self.dfs(ring, key, 0, {}) + len(key)

    def dfs(self, ring: str, key: str, index: int, mem: dict) -> int:
        if index == len(key):
            return 0

        hash_key = ring + str(index)
        if hash_key in mem:
            return mem[hash_key]

        result = float("inf")

        for i in range(len(ring)):
            if ring[i] == key[index]:
                min_rotates = min(i, len(ring) - i)
                new_ring = ring[i:] + ring[:i]
                remaining_rotates = self.dfs(new_ring, key, index + 1, mem.copy())
                result = min(result, min_rotates + remaining_rotates)

        mem[hash_key] = result
        return result
