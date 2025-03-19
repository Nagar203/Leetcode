class Solution {
 public:
  int minOperations(vector<int>& binaryArray) {
    const int arraySize = binaryArray.size();
    int operationCount = 0;

    for (int i = 0; i + 2 < arraySize; ++i) {
      if (binaryArray[i] == 0) {
        binaryArray[i + 1] ^= 1;
        binaryArray[i + 2] ^= 1;
        ++operationCount;
      }
    }

    return binaryArray[arraySize - 1] == 0 || binaryArray[arraySize - 2] == 0 ? -1 : operationCount;
  }
};
