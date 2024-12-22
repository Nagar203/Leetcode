from dataclasses import dataclass


@dataclass
class IndexedQuery:
    queryIndex: int
    aliceIndex: int  # Alice's index
    bobIndex: int  # Bob's index

    def __iter__(self):
        yield self.queryIndex
        yield self.aliceIndex
        yield self.bobIndex


class Solution:
    def leftmostBuildingQueries(self, buildingHeights: list[int], queries: list[list[int]]) -> list[int]:
        results = [-1] * len(queries)
        monotonicStack = []

        buildingIndex = len(buildingHeights) - 1
        for queryIndex, aliceIndex, bobIndex in sorted(
            [IndexedQuery(i, min(a, b), max(a, b)) for i, (a, b) in enumerate(queries)],
            key=lambda x: -x.bobIndex
        ):
            if aliceIndex == bobIndex or buildingHeights[aliceIndex] < buildingHeights[bobIndex]:
                results[queryIndex] = bobIndex
            else:
                while buildingIndex > bobIndex:
                    while monotonicStack and buildingHeights[monotonicStack[-1]] <= buildingHeights[buildingIndex]:
                        monotonicStack.pop()
                    monotonicStack.append(buildingIndex)
                    buildingIndex -= 1

                lastGreaterIndex = self._lastGreater(monotonicStack, aliceIndex, buildingHeights)
                if lastGreaterIndex != -1:
                    results[queryIndex] = monotonicStack[lastGreaterIndex]

        return results

    def _lastGreater(self, indexList: list[int], targetIndex: int, buildingHeights: list[int]):
        left = -1
        right = len(indexList) - 1
        while left < right:
            mid = (left + right + 1) // 2
            if buildingHeights[indexList[mid]] > buildingHeights[targetIndex]:
                left = mid
            else:
                right = mid - 1
        return left