class Solution:
    # Helper function to find the largest lexicographical sequence
    def findLargestSequence(self, sequence, isUsed, index, n):
        if index == (2 * n - 1):
            return True
        if sequence[index] != 0:
            return self.findLargestSequence(sequence, isUsed, index + 1, n)

        for num in range(n, 0, -1):
            if isUsed[num]:
                continue
            isUsed[num] = True
            sequence[index] = num

            if num == 1:
                if self.findLargestSequence(sequence, isUsed, index + 1, n):
                    return True
            elif (index + num) < (2 * n - 1) and sequence[index + num] == 0:
                sequence[index + num] = num
                if self.findLargestSequence(sequence, isUsed, index + 1, n):
                    return True
                sequence[index + num] = 0  

            isUsed[num] = False  
            sequence[index] = 0  

        return False

    # Main function to construct the lexicographically largest sequence
    def constructDistancedSequence(self, n):
        sequence = [0] * (2 * n - 1)
        isUsed = [False] * (n + 1)
        self.findLargestSequence(sequence, isUsed, 0, n)
        return sequence