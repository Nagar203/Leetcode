class Solution:
    def areAlmostEqual(self, str1: str, str2: str) -> bool:
        length1 = len(str1)
        length2 = len(str2)
        
        if length1 != length2:
            return False

        if str1 == str2:
            return True

        mismatchStr1 = []
        mismatchStr2 = []

        for i in range(length1):
            if str1[i] != str2[i]:
                mismatchStr1.append(str1[i])
                mismatchStr2.append(str2[i])
                if len(mismatchStr1) > 2:
                    return False

        if len(mismatchStr1) != 2:
            return False

        return mismatchStr1[0] == mismatchStr2[1] and mismatchStr1[1] == mismatchStr2[0]