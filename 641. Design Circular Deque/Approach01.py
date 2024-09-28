from typing import *

class MyCircularDeque:

    def __init__(self, capacity: int):
        """Initialize your data structure here. Set the size of the deque to be capacity."""
        self.capacity = capacity
        self.dequeArray = [0] * capacity
        self.size = 0
        self.front = 0
        self.rear = capacity - 1

    def insertFront(self, value: int) -> bool:
        """Adds an item at the front of Deque. Return true if the operation is successful."""
        if self.isFull():
            return False
        self.front = (self.front - 1 + self.capacity) % self.capacity
        self.dequeArray[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        """Adds an item at the rear of Deque. Return true if the operation is successful."""
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.capacity
        self.dequeArray[self.rear] = value
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        """Deletes an item from the front of Deque. Return true if the operation is successful."""
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        """Deletes an item from the rear of Deque. Return true if the operation is successful."""
        if self.isEmpty():
            return False
        self.rear = (self.rear - 1 + self.capacity) % self.capacity
        self.size -= 1
        return True

    def getFront(self) -> int:
        """Get the front item from the deque."""
        return -1 if self.isEmpty() else self.dequeArray[self.front]

    def getRear(self) -> int:
        """Get the last item from the deque."""
        return -1 if self.isEmpty() else self.dequeArray[self.rear]

    def isEmpty(self) -> bool:
        """Checks whether the circular deque is empty or not."""
        return self.size == 0

    def isFull(self) -> bool:
        """Checks whether the circular deque is full or not."""
        return self.size == self.capacity