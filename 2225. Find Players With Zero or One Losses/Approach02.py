from typing import *
import collections

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        n = len(matches)       
        win_list = []
        loser_list = []

        for i in range(n):
            win_list.append(matches[i][0])
            loser_list.append(matches[i][1])
        
        win = collections.Counter(win_list)
        loser = collections.Counter(loser_list)
        
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