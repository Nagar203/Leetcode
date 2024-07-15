class Solution:
    def countOfAtoms(self, formula: str) -> str:
        index = 0
        # Parse the formula and build the result string
        element_count, _ = self.parse(formula, index)
        result = ''
        for element, frequency in sorted(element_count.items()):
            result += element
            if frequency > 1:
                result += str(frequency)
        return result

    def parse(self, formula: str, index: int) -> tuple:
        element_count = {}

        while index < len(formula):
            if formula[index] == '(':
                # If we encounter '(', we parse the inside and merge the results
                index += 1
                nested_count, index = self.parse(formula, index)
                for element, frequency in nested_count.items():
                    element_count[element] = element_count.get(element, 0) + frequency
            elif formula[index] == ')':
                # If we encounter ')', we get the multiplier and return the count
                index += 1
                multiplier, index = self.get_number(formula, index)
                for element in element_count:
                    element_count[element] *= multiplier
                return element_count, index  # Return back to the previous scope.
            else:
                # If it's an element, parse it and its frequency
                element, index = self.get_element(formula, index)
                frequency, index = self.get_number(formula, index)
                element_count[element] = element_count.get(element, 0) + frequency
        
        return element_count, index

    def get_element(self, formula: str, index: int) -> tuple:
        element_start = index  # `formula[element_start]` is uppercased.
        index += 1
        while index < len(formula) and formula[index].islower():
            index += 1
        return formula[element_start:index], index

    def get_number(self, formula: str, index: int) -> tuple:
        number_start = index
        while index < len(formula) and formula[index].isdigit():
            index += 1
        number_string = formula[number_start:index]
        return (int(number_string) if number_string else 1), index