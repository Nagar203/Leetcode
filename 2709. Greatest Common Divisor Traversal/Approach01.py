from typing import *

class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1] * n
        self.number_of_components = n
    
    def find(self, x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        x_parent = self.find(x)
        y_parent = self.find(y)
        
        if x_parent == y_parent:
            return
        
        if self.size[x_parent] > self.size[y_parent]:
            self.parent[y_parent] = x_parent
            self.size[x_parent] += self.size[y_parent]
        elif self.size[x_parent] < self.size[y_parent]:
            self.parent[x_parent] = y_parent
            self.size[y_parent] += self.size[x_parent]
        else:
            self.parent[x_parent] = y_parent
            self.size[y_parent] += self.size[x_parent]
        
        self.number_of_components -= 1
    
    def max_size(self):
        return self.number_of_components


class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        dsu = DSU(n)
        
        m = max(nums)
        first = [-1] * (m + 1)

        for i in range(n):
            for prime in range(2, int(nums[i] ** 0.5) + 1):
                if nums[i] % prime != 0:
                    continue
                
                if first[prime] != -1:
                    dsu.union(first[prime], i)
                else:
                    first[prime] = i
                
                while nums[i] % prime == 0:
                    nums[i] //= prime
            
            if nums[i] > 1:
                if first[nums[i]] != -1:
                    dsu.union(first[nums[i]], i)
                else:
                    first[nums[i]] = i
        
        return dsu.max_size() == 1
