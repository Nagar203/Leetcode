class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string result;

        if (numerator < 0 ^ denominator < 0)
            result += "-";

        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);

        result += to_string(absNumerator / absDenominator);

        long long remainder = absNumerator % absDenominator;
        if (remainder == 0)
            return result;

        result += '.';
        unordered_map<long long, int> remainderPosition;

        while (remainder) {
            if (remainderPosition.find(remainder) != remainderPosition.end()) {
                result.insert(remainderPosition[remainder], 1, '(');
                result += ')';
                break;
            }
            remainderPosition[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / absDenominator);
            remainder %= absDenominator;
        }

        return result;
    }
};
