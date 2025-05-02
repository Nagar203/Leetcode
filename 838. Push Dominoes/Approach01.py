class Solution:
  def pushDominoes(self, dominoes: str) -> str:
    result = list(dominoes)
    lastLeft = -1
    lastRight = -1

    for index in range(len(dominoes) + 1):
      if index == len(dominoes) or dominoes[index] == 'R':
        if lastLeft < lastRight:
          while lastRight < index:
            result[lastRight] = 'R'
            lastRight += 1
        lastRight = index

      elif dominoes[index] == 'L':
        if lastRight < lastLeft or (lastLeft, lastRight) == (-1, -1):
          if (lastLeft, lastRight) == (-1, -1):
            lastLeft += 1
          while lastLeft < index:
            result[lastLeft] = 'L'
            lastLeft += 1
        else:
          leftPointer = lastRight + 1
          rightPointer = index - 1
          while leftPointer < rightPointer:
            result[leftPointer] = 'R'
            result[rightPointer] = 'L'
            leftPointer += 1
            rightPointer -= 1
        lastLeft = index

    return ''.join(result)
