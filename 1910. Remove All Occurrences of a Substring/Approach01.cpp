class Solution {
  public:
    string removeOccurrences(string inputStr, string targetStr) {
        while (true) {
            size_t index = inputStr.find(targetStr);
            if (index != string::npos) {
                inputStr.erase(index, targetStr.length());
            } else {
                break;
            }
        }
        return inputStr;
    }
};