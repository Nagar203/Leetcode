#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& numbers) {
        std::vector<int> sortedNumbers(numbers);
        std::unordered_map<int, int> numberRank;

        std::ranges::sort(sortedNumbers);

        for (const int number : sortedNumbers) {
            if (!numberRank.contains(number)) {
                numberRank[number] = numberRank.size() + 1;
            }
        }

        for (int& number : numbers) {
            number = numberRank[number];
        }

        return numbers;
    }
};