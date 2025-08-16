class Solution {
public:
    int maximum69Number(int number) {
        string numberString = to_string(number);

        for (char& digit : numberString) {
            if (digit == '6') {
                digit = '9';
                break;
            }
        }

        return stoi(numberString);
    }
};
