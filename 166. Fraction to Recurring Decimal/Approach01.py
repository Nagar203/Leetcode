class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        result = []

        if (numerator < 0) ^ (denominator < 0):
            result.append("-")

        absNumerator = abs(numerator)
        absDenominator = abs(denominator)

        result.append(str(absNumerator // absDenominator))

        remainder = absNumerator % absDenominator
        if remainder == 0:
            return "".join(result)

        result.append(".")
        remainderPosition = {}

        while remainder:
            if remainder in remainderPosition:
                insertIndex = remainderPosition[remainder]
                result.insert(insertIndex, "(")
                result.append(")")
                break

            remainderPosition[remainder] = len(result)
            remainder *= 10
            result.append(str(remainder // absDenominator))
            remainder %= absDenominator

        return "".join(result)
