from typing import *
import collections
import sys

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        freq_t = collections.Counter(t)
        m = len(s)
        n = len(t)
        
        if(n>m):
            return ''

        i, j = 0, 0
        required_cnt = n
        min_window_size = sys.maxsize
        start_i = 0

        while(j<m):
            ch = s[j]
            if(freq_t[ch] > 0):
                required_cnt -= 1
            freq_t[ch] -= 1
            while(required_cnt == 0):
                curr_window_size = j-i+1
                if(curr_window_size < min_window_size):
                    min_window_size = curr_window_size
                    start_i = i
                freq_t[s[i]] += 1
                if(freq_t[s[i]] > 0):
                    required_cnt += 1
                i += 1 
            j += 1
        
        if(min_window_size == sys.maxsize):
            return ''
        return s[start_i: start_i + min_window_size]
        