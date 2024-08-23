#include <string>
#include <sstream>
#include <cmath>
#include <numeric> // for std::gcd

class Solution {
public:
    std::string fractionAddition(std::string expression) {
        int accumulatedNumerator = 0;
        int accumulatedDenominator = 1;
        
        std::istringstream input(expression);
        char separator;
        int numerator, denominator;
        
        while (input >> numerator >> separator >> denominator) {
            accumulatedNumerator = accumulatedNumerator * denominator + numerator * accumulatedDenominator;
            accumulatedDenominator *= denominator;
            
            int commonDivisor = std::abs(std::gcd(accumulatedNumerator, accumulatedDenominator));
            accumulatedNumerator /= commonDivisor;
            accumulatedDenominator /= commonDivisor;
        }
        
        return std::to_string(accumulatedNumerator) + "/" + std::to_string(accumulatedDenominator);
    }
};