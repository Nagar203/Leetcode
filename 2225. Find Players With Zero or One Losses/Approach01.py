from typing import *
import collections

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        n = len(matches)
        win = {}
        loser = {}

        for i in range(n):
            if matches[i][0] in win:
                win[matches[i][0]] += 1
            else:
                win[matches[i][0]] = 1

            if matches[i][1] in loser:
                loser[matches[i][1]] += 1
            else:
                loser[matches[i][1]] = 1
        
        winner_list_1 = []
        winner_list_2 = []
        
        winner_list_1 = [key for key in win.keys() if key not in loser.keys()]
        winner_list_2 = [ key for key,val in loser.items() if val==1] 
        
        result = []
        winner_list_1.sort()
        winner_list_2.sort()
        result.append(winner_list_1)
        result.append(winner_list_2)

        return result