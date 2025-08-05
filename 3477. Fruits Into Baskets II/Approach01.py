class SegmentTree:
    def __init__(self, values: list[int]):
        self.size = len(values)
        self.tree = [0] * (self.size * 4)
        self._build(values, 0, 0, self.size - 1)

    def update(self, index: int, newValue: int):
        self._update(0, 0, self.size - 1, index, newValue)

    def queryFirst(self, target: int) -> int:
        return self._queryFirst(0, 0, self.size - 1, target)

    def _build(self, values: list[int], treeIndex: int, left: int, right: int):
        if left == right:
            self.tree[treeIndex] = values[left]
            return
        mid = (left + right) // 2
        self._build(values, 2 * treeIndex + 1, left, mid)
        self._build(values, 2 * treeIndex + 2, mid + 1, right)
        self.tree[treeIndex] = max(self.tree[2 * treeIndex + 1], self.tree[2 * treeIndex + 2])

    def _update(self, treeIndex: int, left: int, right: int, index: int, newValue: int):
        if left == right:
            self.tree[treeIndex] = newValue
            return
        mid = (left + right) // 2
        if index <= mid:
            self._update(2 * treeIndex + 1, left, mid, index, newValue)
        else:
            self._update(2 * treeIndex + 2, mid + 1, right, index, newValue)
        self.tree[treeIndex] = max(self.tree[2 * treeIndex + 1], self.tree[2 * treeIndex + 2])

    def _queryFirst(self, treeIndex: int, left: int, right: int, target: int) -> int:
        if self.tree[treeIndex] < target:
            return -1
        if left == right:
            self.update(left, -1)  # Mark as used
            return left
        mid = (left + right) // 2
        if self.tree[2 * treeIndex + 1] >= target:
            return self._queryFirst(2 * treeIndex + 1, left, mid, target)
        return self._queryFirst(2 * treeIndex + 2, mid + 1, right, target)


class Solution:
    def numOfUnplacedFruits(self, fruits: list[int], baskets: list[int]) -> int:
        unplacedCount = 0
        segmentTree = SegmentTree(baskets)

        for fruitSize in fruits:
            if segmentTree.queryFirst(fruitSize) == -1:
                unplacedCount += 1

        return unplacedCount