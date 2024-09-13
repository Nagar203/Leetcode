class Solution {
public:
    vector<int> xorQueries(vector<int>& inputArray, vector<vector<int>>& queries) {
        vector<int> result; // To store the result of each query
        vector<int> prefixXor(inputArray.size() + 1); // To store prefix XOR values

        // Calculate prefix XOR for the input array
        for (int i = 0; i < inputArray.size(); ++i)
            prefixXor[i + 1] = prefixXor[i] ^ inputArray[i];

        // Process each query
        for (const vector<int>& query : queries) {
            const int startIndex = query[0];
            const int endIndex = query[1];
            // XOR from startIndex to endIndex can be found using prefix XOR values
            result.push_back(prefixXor[startIndex] ^ prefixXor[endIndex + 1]);
        }

        return result;
    }
};