#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> char_indices;
        for (int i = 0; i < ring.size(); ++i) {
            char_indices[ring[i]].push_back(i);
        }

        unordered_map<pair<int, int>, int, pair_hash> memo;

        return dfs(0, 0, ring, key, char_indices, memo) + key.length();
    }

private:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    int dfs(int ring_index, int key_index, const string& ring,
            const string& key,
            const unordered_map<char, vector<int>>& char_indices,
            unordered_map<pair<int, int>, int, pair_hash>& memo) {
        if (key_index == key.length()) {
            return 0;
        }

        if (memo.count({ring_index, key_index})) {
            return memo[{ring_index, key_index}];
        }

        int min_steps = INT_MAX;

        for (int next_ring_index : char_indices.at(key[key_index])) {
            int steps = abs(next_ring_index - ring_index);
            steps = min(steps, (int)ring.length() - steps);
            int remaining_steps = dfs(next_ring_index, key_index + 1, ring, key,
                                      char_indices, memo);
            min_steps = min(min_steps, steps + remaining_steps);
        }

        memo[{ring_index, key_index}] = min_steps;

        return min_steps;
    }
};
