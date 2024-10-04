#include <unordered_set>
#include <vector>

class Solution {
public:
    long long dividePlayers(std::vector<int>& skillLevels) {
        const int numPlayers = skillLevels.size();
        const int targetTeamSkill = std::accumulate(skillLevels.begin(), skillLevels.end(), 0) / (numPlayers / 2);
        long long totalSkillProduct = 0;
        std::unordered_map<int, int> skillCount;

        for (const int skill : skillLevels)
            ++skillCount[skill];

        for (const auto& [skill, frequency] : skillCount) {
            const int requiredSkill = targetTeamSkill - skill;
            if (const auto it = skillCount.find(requiredSkill);
                it == skillCount.cend() || it->second != frequency)
                return -1;
            totalSkillProduct += static_cast<long long>(skill) * requiredSkill * frequency;
        }

        return totalSkillProduct / 2;
    }
};