#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequencyMap;

        // Count the frequency of each string in the array
        for (const string& str : arr) {
            frequencyMap[str]++;
        }

        // Iterate through the array to find the k-th distinct string
        for (const string& str : arr) {
            if (frequencyMap[str] == 1) {
                k--;
                if (k == 0) {
                    return str;  // Return the k-th distinct string
                }
            }
        }

        return "";  // If there are fewer than k distinct strings, return an empty string
    }
};