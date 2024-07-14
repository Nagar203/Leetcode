#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        string result;
        int index = 0;

        // Parse the formula and build the result string
        for (const auto& [element, frequency] : parse(formula, index)) {
            result += element;
            if (frequency > 1)
                result += to_string(frequency);
        }

        return result;
    }

private:
    // Parse the formula and return a map of elements with their frequencies
    map<string, int> parse(const string& formula, int& index) {
        map<string, int> elementCount;

        while (index < formula.length()) {
            if (formula[index] == '(') {
                // If we encounter '(', we parse the inside and merge the
                // results
                for (const auto& [element, frequency] : parse(formula, ++index))
                    elementCount[element] += frequency;
            } else if (formula[index] == ')') {
                // If we encounter ')', we get the multiplier and return the
                // count
                const int multiplier = getNumber(formula, ++index);
                for (auto&& [_, frequency] : elementCount)
                    frequency *= multiplier;
                return elementCount; // Return back to the previous scope.
            } else { // If it's an element, parse it and its frequency
                const string& element = getElement(formula, index);
                const int frequency = getNumber(formula, index);
                elementCount[element] += frequency;
            }
        }

        return elementCount;
    }

    // Get the element name starting from index
    string getElement(const string& formula, int& index) {
        const int elementStart =
            index++; // `formula[elementStart]` is uppercased.
        while (index < formula.length() && islower(formula[index]))
            ++index;
        return formula.substr(elementStart, index - elementStart);
    }

    // Get the number following an element or parenthesis starting from index
    int getNumber(const string& formula, int& index) {
        const int numberStart = index;
        while (index < formula.length() && isdigit(formula[index]))
            ++index;
        const string& numberString =
            formula.substr(numberStart, index - numberStart);
        return numberString.empty() ? 1 : stoi(numberString);
    }
};
