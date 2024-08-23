from math import gcd

class Solution:
    def fractionAddition(self, expression: str) -> str:
        accumulatedNumerator = 0
        accumulatedDenominator = 1
        
        index = 0
        while index < len(expression):
            sign = 1
            if expression[index] == '-' or expression[index] == '+':
                if expression[index] == '-':
                    sign = -1
                index += 1

            numerator = 0
            while index < len(expression) and expression[index].isdigit():
                numerator = numerator * 10 + int(expression[index])
                index += 1
            numerator *= sign
            index += 1  # Skip the '/'
            denominator = 0
            while index < len(expression) and expression[index].isdigit():
                denominator = denominator * 10 + int(expression[index])
                index += 1
            
            # Calculate new accumulated fraction
            accumulatedNumerator = accumulatedNumerator * denominator + numerator * accumulatedDenominator
            accumulatedDenominator *= denominator
            
            # Simplify the fraction by the greatest common divisor
            commonDivisor = abs(gcd(accumulatedNumerator, accumulatedDenominator))
            accumulatedNumerator //= commonDivisor
            accumulatedDenominator //= commonDivisor

        return f"{accumulatedNumerator}/{accumulatedDenominator}"