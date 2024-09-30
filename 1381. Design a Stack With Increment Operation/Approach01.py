from typing import *

class CustomStack:
    def __init__(self, maxStackSize: int):
        self.maxStackSize = maxStackSize
        self.stack = []
        self.pendingIncrements = []

    def push(self, value: int) -> None:
        if len(self.stack) == self.maxStackSize:
            return
        self.stack.append(value)
        self.pendingIncrements.append(0)

    def pop(self) -> int:
        if not self.stack:
            return -1
        stackIndex = len(self.stack) - 1
        if stackIndex > 0:
            self.pendingIncrements[stackIndex - 1] += self.pendingIncrements[stackIndex]
        returnValue = self.stack.pop() + self.pendingIncrements.pop()
        return returnValue

    def increment(self, count: int, value: int) -> None:
        if not self.stack:
            return
        lastIndex = min(count - 1, len(self.stack) - 1)
        self.pendingIncrements[lastIndex] += value