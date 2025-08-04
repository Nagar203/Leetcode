class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        maxFruits = 0
        fruitCount = {}
        left = 0

        for right in range(len(fruits)):
            fruitCount[fruits[right]] = fruitCount.get(fruits[right], 0) + 1

            while len(fruitCount) > 2:
                fruitCount[fruits[left]] -= 1
                if fruitCount[fruits[left]] == 0:
                    del fruitCount[fruits[left]]
                left += 1

            maxFruits = max(maxFruits, right - left + 1)

        return maxFruits