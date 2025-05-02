class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<char> result(dominoes.begin(), dominoes.end());
        int lastLeft = -1, lastRight = -1;

        for (int index = 0; index <= dominoes.size(); ++index) {
            if (index == dominoes.size() || dominoes[index] == 'R') {
                if (lastLeft < lastRight) {
                    while (lastRight < index) {
                        result[lastRight] = 'R';
                        ++lastRight;
                    }
                }
                lastRight = index;
            }
            else if (dominoes[index] == 'L') {
                if (lastRight < lastLeft || (lastLeft == -1 && lastRight == -1)) {
                    if (lastLeft == -1 && lastRight == -1) {
                        ++lastLeft;
                    }
                    while (lastLeft < index) {
                        result[lastLeft] = 'L';
                        ++lastLeft;
                    }
                } else {
                    int leftPointer = lastRight + 1;
                    int rightPointer = index - 1;
                    while (leftPointer < rightPointer) {
                        result[leftPointer++] = 'R';
                        result[rightPointer--] = 'L';
                    }
                }
                lastLeft = index;
            }
        }

        return string(result.begin(), result.end());
    }
};
