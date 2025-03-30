from typing import List

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastOccurrence = {char: index for index, char in enumerate(s)}  
        partitions = []
        partitionEnd = 0
        partitionSize = 0

        for index, char in enumerate(s):
            partitionEnd = max(partitionEnd, lastOccurrence[char])
            partitionSize += 1
            if index == partitionEnd:
                partitions.append(partitionSize)
                partitionSize = 0  
                
        return partitions