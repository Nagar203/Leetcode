class Solution {
public:
    bool canChange(string start, string target) {
        const int length = start.length();
        int startIndex = 0;  // Index for the start string
        int targetIndex = 0; // Index for the target string

        while (startIndex <= length && targetIndex <= length) {
            while (startIndex < length && start[startIndex] == '_')
                ++startIndex;
            while (targetIndex < length && target[targetIndex] == '_')
                ++targetIndex;

            if (startIndex == length || targetIndex == length)
                return startIndex == length && targetIndex == length;

            if (start[startIndex] != target[targetIndex])
                return false;

            if (start[startIndex] == 'R' && startIndex > targetIndex)
                return false;

            if (start[startIndex] == 'L' && startIndex < targetIndex)
                return false;

            ++startIndex;
            ++targetIndex;
        }

        return true;
    }
};