class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        # isPrerequisiteMatrix[i][j] := True if course i is a prerequisite of course j
        isPrerequisiteMatrix = [[False] * numCourses for _ in range(numCourses)]

        # Populate the initial prerequisites
        for prerequisitePair in prerequisites:
            prerequisiteCourse = prerequisitePair[0]
            dependentCourse = prerequisitePair[1]
            isPrerequisiteMatrix[prerequisiteCourse][dependentCourse] = True

        # Use the Floyd-Warshall algorithm to determine all prerequisite relationships
        for intermediateCourse in range(numCourses):
            for courseA in range(numCourses):
                for courseB in range(numCourses):
                    isPrerequisiteMatrix[courseA][courseB] = (
                        isPrerequisiteMatrix[courseA][courseB]
                        or (
                            isPrerequisiteMatrix[courseA][intermediateCourse]
                            and isPrerequisiteMatrix[intermediateCourse][courseB]
                        )
                    )

        # Check each query
        result = []
        for queryPair in queries:
            courseA = queryPair[0]
            courseB = queryPair[1]
            result.append(isPrerequisiteMatrix[courseA][courseB])

        return result