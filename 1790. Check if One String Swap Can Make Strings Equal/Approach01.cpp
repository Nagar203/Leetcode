class Solution {
  public:
    bool areAlmostEqual(string str1, string str2) {
        int length1 = str1.length();
        int length2 = str2.length();
        
        if (length1 != length2) {
            return false;
        }

        if (str1 == str2) {
            return true;
        }

        vector<char> mismatchStr1, mismatchStr2;
        
        for (int i = 0; i < length1; i++) {
            if (str1[i] != str2[i]) {
                mismatchStr1.push_back(str1[i]);
                mismatchStr2.push_back(str2[i]);
                if (mismatchStr1.size() > 2) {
                    return false;
                }
            }
        }

        if (mismatchStr1.size() != 2) {
            return false;
        }

        return (mismatchStr1[0] == mismatchStr2[1] && mismatchStr1[1] == mismatchStr2[0]);
    }
};