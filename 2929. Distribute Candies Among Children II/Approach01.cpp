class Solution {
public:
    long long distributeCandies(int totalCandies, int maxCandiesPerChild) {
        const int limitPlusOne = maxCandiesPerChild + 1;
        const long oneChildOverLimit = countWays(totalCandies - limitPlusOne);
        const long twoChildrenOverLimit = countWays(totalCandies - 2 * limitPlusOne);
        const long threeChildrenOverLimit = countWays(totalCandies - 3 * limitPlusOne);
        return countWays(totalCandies) - 3 * oneChildOverLimit + 3 * twoChildrenOverLimit - threeChildrenOverLimit;
    }
private:
    long countWays(int candies) {
        if (candies < 0){
            return 0;
        }            
        return computeCombination(candies + 2, 2);  
    }
    long computeCombination(int n, int k) {
        long result = 1;
        for (int i = 1; i <= k; ++i){
            result = result * (n - i + 1) / i;
        }            
        return result;
    }
};