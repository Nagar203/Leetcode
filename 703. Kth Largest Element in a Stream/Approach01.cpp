#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    // Constructor to initialize the KthLargest object with the given k and elements.
    KthLargest(int k, vector<int>& nums) : kthLargest(k) {
        for (const int num : nums)
            addElementToHeap(num);  // Add each element from the initial list to the heap.
    }

    // Function to add a new element and return the kth largest element.
    int add(int value) {
        addElementToHeap(value);
        return minHeap.top();  // The top of the min-heap is the kth largest element.
    }

private:
    const int kthLargest;  // The 'k' value indicating which largest element to maintain.
    priority_queue<int, vector<int>, greater<>> minHeap;  // Min-heap to keep track of the k largest elements.

    // Helper function to maintain the size of the heap to be at most k elements.
    void addElementToHeap(int value) {
        minHeap.push(value);  // Add the new element to the heap.
        if (minHeap.size() > kthLargest)
            minHeap.pop();  // Remove the smallest element if the heap exceeds size k.
    }
};