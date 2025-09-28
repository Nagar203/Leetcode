class Solution {
public:
    int largestPerimeter(vector<int>& sideLengths) {
        ranges::sort(sideLengths);

        for (int largestIndex = sideLengths.size() - 1; largestIndex > 1; --largestIndex) {
            if (sideLengths[largestIndex - 2] + sideLengths[largestIndex - 1] > sideLengths[largestIndex]) {
                return sideLengths[largestIndex - 2] +
                       sideLengths[largestIndex - 1] +
                       sideLengths[largestIndex];
            }
        }

        return 0;
    }
};
