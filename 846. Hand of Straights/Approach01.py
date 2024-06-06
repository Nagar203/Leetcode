from collections import defaultdict


class Solution:
    def isNStraightHand(self, hand, groupSize):
        mp = defaultdict(int)

        for card in hand:
            mp[card] += 1

        for start in sorted(mp):
            value = mp[start]
            if value > 0:
                for i in range(start, start + groupSize):
                    mp[i] -= value
                    if mp[i] < 0:
                        return False

        return True
