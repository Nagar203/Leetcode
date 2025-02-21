class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.result=set()
        self.dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.result
    
    def dfs(self, root: TreeNode | None, value: int)->None:
        if(root is None):
            return
        
        root.val = value
        self.result.add(value)
        self.dfs(root.left, root.val*2+1)
        self.dfs(root.right, root.val*2+2)