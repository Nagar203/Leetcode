#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& numbers) {
        unordered_map<int, int> numberFrequency;

        // Count the frequency of each number
        for (int number : numbers) {
            numberFrequency[number]++;
        }

        // Check for zeroes
        if (numberFrequency[0] > 1) {
            return true;
        }

        // Check if double exists for any number
        for (const auto& [number, frequency] : numberFrequency) {
            if (numberFrequency.count(2 * number) > 0 && number != 2 * number) {
                return true;
            }
        }

        return false;
    }
};