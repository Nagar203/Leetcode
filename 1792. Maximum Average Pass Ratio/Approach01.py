import heapq

class Solution:
    def maxAverageRatio(self, classData: list[list[int]], extraStudents: int) -> float:
        # (extra pass ratio, pass, total)
        maxHeap = []

        for classInfo in classData:
            passedStudents = classInfo[0]
            totalStudents = classInfo[1]
            heapq.heappush(maxHeap, (-self.extraPassRatio(passedStudents, totalStudents), passedStudents, totalStudents))

        for _ in range(extraStudents):
            _, passedStudents, totalStudents = heapq.heappop(maxHeap)
            heapq.heappush(maxHeap, (-self.extraPassRatio(passedStudents + 1, totalStudents + 1), passedStudents + 1, totalStudents + 1))

        totalRatio = 0

        while maxHeap:
            _, passedStudents, totalStudents = heapq.heappop(maxHeap)
            totalRatio += passedStudents / totalStudents

        return totalRatio / len(classData)

    def extraPassRatio(self, passedStudents: int, totalStudents: int) -> float:
        return (passedStudents + 1) / (totalStudents + 1) - passedStudents / totalStudents