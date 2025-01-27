class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<bool> result;
    // isPrerequisiteMatrix[i][j] := true if course i is a prerequisite of course j
    vector<vector<bool>> isPrerequisiteMatrix(numCourses, vector<bool>(numCourses));

    // Populate the initial prerequisites
    for (const vector<int>& prerequisitePair : prerequisites) {
      const int prerequisiteCourse = prerequisitePair[0];
      const int dependentCourse = prerequisitePair[1];
      isPrerequisiteMatrix[prerequisiteCourse][dependentCourse] = true;
    }

    // Use the Floyd-Warshall algorithm to determine all prerequisite relationships
    for (int intermediateCourse = 0; intermediateCourse < numCourses; ++intermediateCourse)
      for (int courseA = 0; courseA < numCourses; ++courseA)
        for (int courseB = 0; courseB < numCourses; ++courseB)
          isPrerequisiteMatrix[courseA][courseB] =
              isPrerequisiteMatrix[courseA][courseB] ||
              (isPrerequisiteMatrix[courseA][intermediateCourse] &&
               isPrerequisiteMatrix[intermediateCourse][courseB]);

    // Check each query
    for (const vector<int>& queryPair : queries) {
      const int courseA = queryPair[0];
      const int courseB = queryPair[1];
      result.push_back(isPrerequisiteMatrix[courseA][courseB]);
    }

    return result;
  }
};