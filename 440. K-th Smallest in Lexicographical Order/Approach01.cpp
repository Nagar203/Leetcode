class Solution {
 public:
  int findKthNumber(int totalNumbers, int k) {
    long currentNumber = 1;  // The number we are searching for

    // Iterate to find the kth number
    for (int currentPosition = 1; currentPosition < k;) {
      const long gap = calculateGap(currentNumber, currentNumber + 1, totalNumbers);
      
      // Check if the kth number is within this gap
      if (currentPosition + gap <= k) {
        currentPosition += gap;
        ++currentNumber;  // Move to the next number
      } else {
        ++currentPosition;
        currentNumber *= 10;  // Move to the next level in lexicographical order
      }
    }

    return currentNumber;
  }

 private:
  // Function to calculate the gap between two numbers in the lexicographical order
  long calculateGap(long start, long end, long maxNumber) {
    long gap = 0;
    
    // Calculate gap between 'start' and 'end' until 'maxNumber'
    while (start <= maxNumber) {
      gap += min(maxNumber + 1, end) - start;
      start *= 10;
      end *= 10;
    }

    return gap;
  };
};