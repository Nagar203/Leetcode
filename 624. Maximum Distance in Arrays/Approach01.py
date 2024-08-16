from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        maxDistance = 0  # Initialize the maximum distance to zero
        currentMin, currentMax = arrays[0][0], arrays[0][-1]  # Start with the first array's min and max values

        # Iterate through each array starting from the second one
        for array in arrays[1:]:
            # Calculate distances using the first and last elements of the current array
            distanceFromMax = abs(array[0] - currentMax)  # Distance from the current array's first element to current maximum
            distanceFromMin = abs(array[-1] - currentMin)  # Distance from the current array's last element to current minimum
            
            # Update the maximum distance if the current distances are greater
            maxDistance = max(maxDistance, distanceFromMax, distanceFromMin)
            
            # Update currentMin and currentMax to include the current array
            currentMin = min(currentMin, array[0])  # Update current minimum value
            currentMax = max(currentMax, array[-1])  # Update current maximum value

        return maxDistance  # Return the largest distance found