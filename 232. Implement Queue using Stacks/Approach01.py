from typing import *
import collections

class MyQueue:
    def __init__(self):
        self.input_st = []
        self.output_st = []
        self.first_element = 1
        
    def push(self, x: int) -> None:
        if not self.input_st:
            self.first_element = x
        self.input_st.append(x)        

    def pop(self) -> int:
        if not self.output_st:
            length = len(self.input_st)
            while(length):
                self.output_st.append(self.input_st.pop())
                length -= 1
        
        val = self.output_st.pop()
        return val

    def peek(self) -> int:
        if not self.output_st:
            return self.first_element
        peek_val = self.output_st[-1]
        return peek_val

    def empty(self) -> bool:
        if(not self.input_st) and (not self.output_st):
            return True
        return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()