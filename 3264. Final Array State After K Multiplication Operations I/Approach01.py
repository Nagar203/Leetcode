class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        
        while(k):
            minValIndex = nums.index(min(nums))  
            print(minValIndex)              
            nums[minValIndex] = nums[minValIndex]*multiplier
            k -= 1
        return nums