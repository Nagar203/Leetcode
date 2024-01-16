#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
private:
    unordered_set<int> data;
public:
    RandomizedSet() {
        srand(static_cast<unsigned int>(time(0)));
    }

    bool insert(int val) {
        if (data.find(val) != data.end()) { return false; }
        data.insert(val);
        return true;
    }

    bool remove(int val) {
        auto it = data.find(val);
        if (it != data.end()) {
            data.erase(it);
            return true;
        }
        return false;
    }

    int getRandom() {
        if (data.empty()) { return -1; }
        int randomIndex = rand() % data.size();
        auto it = data.begin();
        advance(it, randomIndex);
        return *it;
    }
};