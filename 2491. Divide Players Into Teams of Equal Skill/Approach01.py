from typing import *

class Solution:
    def dividePlayers(self, skillLevels: List[int]) -> int:
        numPlayers = len(skillLevels)
        targetTeamSkill = sum(skillLevels) // (numPlayers // 2)
        totalSkillProduct = 0
        skillCount = {}

        for skill in skillLevels:
            skillCount[skill] = skillCount.get(skill, 0) + 1

        for skill, frequency in skillCount.items():
            requiredSkill = targetTeamSkill - skill
            if skillCount.get(requiredSkill, 0) != frequency:
                return -1
            totalSkillProduct += skill * requiredSkill * frequency

        return totalSkillProduct // 2