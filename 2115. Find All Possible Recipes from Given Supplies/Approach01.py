from collections import deque
from typing import List

class Solution:
    def findAllRecipes(self, recipes: List[str],  ingredients: List[List[str]],  supplies: List[str]) -> List[str]:
        result = []
        availableSupplies = set(supplies)
        dependencyGraph = {}
        ingredientCount = {}
        recipeQueue = deque()

        for i in range(len(recipes)):
            for ingredient in ingredients[i]:
                if ingredient not in availableSupplies:
                    dependencyGraph.setdefault(ingredient, []).append(recipes[i])
                    ingredientCount[recipes[i]] = ingredientCount.get(recipes[i], 0) + 1

        for recipe in recipes:
            if recipe not in ingredientCount:
                recipeQueue.append(recipe)

        while recipeQueue:
            currentRecipe = recipeQueue.popleft()
            result.append(currentRecipe)

            if currentRecipe not in dependencyGraph:
                continue

            for dependentRecipe in dependencyGraph[currentRecipe]:
                ingredientCount[dependentRecipe] -= 1
                if ingredientCount[dependentRecipe] == 0:
                    recipeQueue.append(dependentRecipe)

        return result
