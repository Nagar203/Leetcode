class SegmentTree {
public:
    explicit SegmentTree(const vector<int>& values)
        : size(values.size()), tree(size * 4) {
        build(values, 0, 0, size - 1);
    }

    void update(int index, int newValue) {
        update(0, 0, size - 1, index, newValue);
    }

    int queryFirst(int target) {
        return queryFirst(0, 0, size - 1, target);
    }

private:
    const int size;
    vector<int> tree;

    void build(const vector<int>& values, int nodeIndex, int left, int right) {
        if (left == right) {
            tree[nodeIndex] = values[left];
            return;
        }
        int mid = (left + right) / 2;
        build(values, 2 * nodeIndex + 1, left, mid);
        build(values, 2 * nodeIndex + 2, mid + 1, right);
        tree[nodeIndex] = merge(tree[2 * nodeIndex + 1], tree[2 * nodeIndex + 2]);
    }

    void update(int nodeIndex, int left, int right, int index, int newValue) {
        if (left == right) {
            tree[nodeIndex] = newValue;
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid)
            update(2 * nodeIndex + 1, left, mid, index, newValue);
        else
            update(2 * nodeIndex + 2, mid + 1, right, index, newValue);
        tree[nodeIndex] = merge(tree[2 * nodeIndex + 1], tree[2 * nodeIndex + 2]);
    }

    int queryFirst(int nodeIndex, int left, int right, int target) {
        if (tree[nodeIndex] < target)
            return -1;
        if (left == right) {
            update(left, -1);  // Mark the basket as used
            return left;
        }
        int mid = (left + right) / 2;
        if (tree[2 * nodeIndex + 1] >= target)
            return queryFirst(2 * nodeIndex + 1, left, mid, target);
        return queryFirst(2 * nodeIndex + 2, mid + 1, right, target);
    }

    int merge(int leftValue, int rightValue) const {
        return max(leftValue, rightValue);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplacedCount = 0;
        SegmentTree segmentTree(baskets);

        for (const int fruitSize : fruits)
            if (segmentTree.queryFirst(fruitSize) == -1)
                ++unplacedCount;

        return unplacedCount;
    }
};
