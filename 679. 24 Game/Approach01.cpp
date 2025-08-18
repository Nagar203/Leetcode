class Solution {
public:
    bool judgePoint24(vector<int>& numbers) {
        vector<double> doubleNumbers;
        for (const int number : numbers)
            doubleNumbers.push_back(number);
        return canMake24(doubleNumbers);
    }

private:
    bool canMake24(vector<double>& currentNumbers) {
        if (currentNumbers.size() == 1)
            return abs(currentNumbers[0] - 24) < 0.001;

        for (int i = 0; i < currentNumbers.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                for (const double result : generateResults(currentNumbers[i], currentNumbers[j])) {
                    vector<double> nextRound{result};
                    for (int k = 0; k < currentNumbers.size(); ++k) {
                        if (k == i || k == j) // Skip used numbers
                            continue;
                        nextRound.push_back(currentNumbers[k]);
                    }
                    if (canMake24(nextRound))
                        return true;
                }
            }
        }
        return false;
    }

    vector<double> generateResults(double numA, double numB) {
        return {numA * numB, numA / numB, numB / numA, numA + numB, numA - numB, numB - numA};
    }
};
