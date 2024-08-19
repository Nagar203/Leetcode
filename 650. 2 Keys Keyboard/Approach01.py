from typing import *

class Solution:
    def kthSmallest(self, array, k):
        # Find the maximum value in the array
        maxValue = 0
        for num in array:
            if num > maxValue:
                maxValue = num

        # Create a boolean array to track the presence of each value
        presence = [0] * maxValue

        # Mark the presence of each value in the boolean array
        for num in array:
            presence[num - 1] = 1

        # Find the k-th smallest element by counting marked values
        count = 0
        kthSmallestElement = 0
        for i in range(maxValue):
            if presence[i] == 1:
                count += 1
                kthSmallestElement = i + 1
                if count == k:
                    break

        return kthSmallestElement