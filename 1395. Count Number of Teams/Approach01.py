from typing import List

class Solution:
    def numTeams(self, ratings: List[int]) -> int:
        totalTeams = 0

        # Iterate through each soldier, considering them as the middle soldier in a team
        for middle in range(1, len(ratings) - 1):
            # Calculate the number of soldiers on the left with less/greater ratings than the middle soldier
            leftLessCount = 0
            leftGreaterCount = 0
            for left in range(middle):
                if ratings[left] < ratings[middle]:
                    leftLessCount += 1
                elif ratings[left] > ratings[middle]:
                    leftGreaterCount += 1

            # Calculate the number of soldiers on the right with less/greater ratings than the middle soldier
            rightLessCount = 0
            rightGreaterCount = 0
            for right in range(middle + 1, len(ratings)):
                if ratings[right] < ratings[middle]:
                    rightLessCount += 1
                elif ratings[right] > ratings[middle]:
                    rightGreaterCount += 1

            # Calculate the number of valid teams using the current middle soldier
            totalTeams += leftLessCount * rightGreaterCount + leftGreaterCount * rightLessCount

        return totalTeams
