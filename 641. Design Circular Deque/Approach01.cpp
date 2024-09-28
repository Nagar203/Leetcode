class MyCircularDeque {
 public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int capacity) : capacity(capacity), dequeArray(capacity), rear(capacity - 1) {}

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value) {
    if (isFull())
      return false;

    front = (--front + capacity) % capacity;
    dequeArray[front] = value;
    ++currentSize;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value) {
    if (isFull())
      return false;

    rear = ++rear % capacity;
    dequeArray[rear] = value;
    ++currentSize;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront() {
    if (isEmpty())
      return false;

    front = ++front % capacity;
    --currentSize;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast() {
    if (isEmpty())
      return false;

    rear = (--rear + capacity) % capacity;
    --currentSize;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    return isEmpty() ? -1 : dequeArray[front];
  }

  /** Get the last item from the deque. */
  int getRear() {
    return isEmpty() ? -1 : dequeArray[rear];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() {
    return currentSize == 0;
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull() {
    return currentSize == capacity;
  }

 private:
  const int capacity;                // Capacity of the deque
  vector<int> dequeArray;            // Array to store deque elements
  int currentSize = 0;               // Number of elements in the deque
  int front = 0;                     // Index of the front element
  int rear;                          // Index of the rear element
};