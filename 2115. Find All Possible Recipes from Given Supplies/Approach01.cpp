class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> result;
        unordered_set<string> availableSupplies(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> dependencyGraph;
        unordered_map<string, int> ingredientCount;
        queue<string> recipeQueue;

        for (int i = 0; i < recipes.size(); ++i) {
            for (const string& ingredient : ingredients[i]) {
                if (!availableSupplies.contains(ingredient)) {
                    dependencyGraph[ingredient].push_back(recipes[i]);
                    ++ingredientCount[recipes[i]];
                }
            }
        }

        for (const string& recipe : recipes) {
            if (!ingredientCount.contains(recipe))
                recipeQueue.push(recipe);
        }

        while (!recipeQueue.empty()) {
            const string currentRecipe = recipeQueue.front();
            recipeQueue.pop();
            result.push_back(currentRecipe);

            if (!dependencyGraph.contains(currentRecipe))
                continue;

            for (const string& dependentRecipe : dependencyGraph[currentRecipe]) {
                if (--ingredientCount[dependentRecipe] == 0)
                    recipeQueue.push(dependentRecipe);
            }
        }

        return result;
    }
};
