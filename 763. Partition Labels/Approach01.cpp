#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;  
        vector<int> partitions;
        int partitionEnd = 0;
        int partitionSize = 0;

        for (int index = 0; index < s.size(); ++index)
            lastOccurrence[s[index]] = index;

        for (int index = 0; index < s.size(); ++index) {
            partitionEnd = max(partitionEnd, lastOccurrence[s[index]]);
            partitionSize++;

            if (index == partitionEnd) {
                partitions.push_back(partitionSize);
                partitionSize = 0;
            }
        }

        return partitions;
    }
};