class Solution {
 public:
  double maxAverageRatio(vector<vector<int>>& classData, int extraStudents) {
    // (extra pass ratio, pass, total)
    priority_queue<tuple<double, int, int>> maxHeap;

    for (const vector<int>& classInfo : classData) {
      const int passedStudents = classInfo[0];
      const int totalStudents = classInfo[1];
      maxHeap.emplace(extraPassRatio(passedStudents, totalStudents), passedStudents, totalStudents);
    }

    for (int i = 0; i < extraStudents; ++i) {
      const auto [_, passedStudents, totalStudents] = maxHeap.top();
      maxHeap.pop();
      maxHeap.emplace(extraPassRatio(passedStudents + 1, totalStudents + 1), passedStudents + 1, totalStudents + 1);
    }

    double totalRatio = 0;

    while (!maxHeap.empty()) {
      const auto [_, passedStudents, totalStudents] = maxHeap.top();
      maxHeap.pop();
      totalRatio += passedStudents / static_cast<double>(totalStudents);
    }

    return totalRatio / classData.size();
  }

 private:
  // Returns the extra pass ratio if a brilliant student joins.
  double extraPassRatio(int passedStudents, int totalStudents) {
    return (passedStudents + 1) / static_cast<double>(totalStudents + 1) -
           passedStudents / static_cast<double>(totalStudents);
  }
};