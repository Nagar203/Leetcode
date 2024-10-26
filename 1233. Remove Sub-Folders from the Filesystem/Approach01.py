class Solution:
    def removeSubfolders(self, folderPaths: list[str]) -> list[str]:
        result = []
        previousFolder = ""

        folderPaths.sort()

        for currentFolder in folderPaths:
            if previousFolder and currentFolder.startswith(previousFolder) and currentFolder[len(previousFolder)] == '/':
                continue
            result.append(currentFolder)
            previousFolder = currentFolder

        return result