from typing import *

class Solution:
    def get_nsl(self, arr, n):
        result = [0] * n
        st = []

        for i in range(n):
            if not st:
                result[i] = -1
            else:
                while st and arr[st[-1]] > arr[i]:
                    st.pop()
                result[i] = -1 if not st else st[-1]
            st.append(i)

        return result

    def get_nsr(self, arr, n):
        result = [0] * n
        st = []

        for i in range(n-1, -1, -1): 
            if not st:
                result[i] = n
            else:
                while st and arr[st[-1]] >= arr[i]:
                    st.pop()
                result[i] = n if not st else st[-1] 
            st.append(i)

        return result   

    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 1e9+7
        n = len(arr)
        
        left_index = self.get_nsl(arr, n)
        right_index = self.get_nsr(arr, n)
        result  = 0
        
        for i in range(n):
            left = i - left_index[i]
            right = right_index[i] - i

            result = (result + left*right*arr[i])%MOD
        
        return int(result)