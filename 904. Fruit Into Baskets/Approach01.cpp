class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        unordered_map<int, int> fruitCount;

        for (int left = 0, right = 0; right < fruits.size(); ++right) {
            ++fruitCount[fruits[right]];

            while (fruitCount.size() > 2) {
                if (--fruitCount[fruits[left]] == 0)
                    fruitCount.erase(fruits[left]);
                ++left;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
