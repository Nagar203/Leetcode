#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folderPaths) {
        vector<string> result;
        string previousFolder;

        ranges::sort(folderPaths);

        for (const string& currentFolder : folderPaths) {
            if (!previousFolder.empty() && currentFolder.find(previousFolder) == 0 && currentFolder[previousFolder.length()] == '/')
                continue;
            result.push_back(currentFolder);
            previousFolder = currentFolder;
        }

        return result;
    }
};
