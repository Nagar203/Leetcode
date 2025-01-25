class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        result = [0] * len(nums)
        # Group numbers based on the difference condition <= limit
        groupedNumbers = []

        # Sort numbers with their indices
        for num, index in self.getNumAndIndexes(nums):
            # Start a new group if the difference between num and the last number exceeds the limit
            if not groupedNumbers or num - groupedNumbers[-1][-1][0] > limit:
                groupedNumbers.append([(num, index)])
            else:
                # Append to the existing group
                groupedNumbers[-1].append((num, index))

        # Process each group of numbers
        for numAndIndexesGroup in groupedNumbers:
            sortedNums = []
            sortedIndices = []
            for num, index in numAndIndexesGroup:
                sortedNums.append(num)
                sortedIndices.append(index)
            sortedIndices.sort()  # Sort indices to maintain the lexicographical order
            for i in range(len(sortedNums)):
                result[sortedIndices[i]] = sortedNums[i]  # Assign sorted values to result

        return result

    def getNumAndIndexes(self, nums):
        numAndIndexes = [(num, index) for index, num in enumerate(nums)]
        numAndIndexes.sort()  # Sort pairs based on the numbers
        return numAndIndexes
