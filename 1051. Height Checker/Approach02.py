class Solution:
    def heightChecker(self, heights):
        length = len(heights)
        current_height = 0
        result = 0
        height_count = [0] * 101

        for height in heights:
            height_count[height] += 1
            
        for i in range(length):
            while height_count[current_height] == 0:
                current_height += 1
            if heights[i] != current_height:
                result += 1
            height_count[current_height] -= 1
        
        return result
