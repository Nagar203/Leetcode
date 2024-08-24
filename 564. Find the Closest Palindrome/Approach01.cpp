#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string number) {
        const auto& [previousPalindrome, nextPalindrome] = getClosestPalindromes(number);
        return abs(previousPalindrome - stol(number)) <= abs(nextPalindrome - stol(number))
                   ? to_string(previousPalindrome)
                   : to_string(nextPalindrome);
    }

private:
    // Returns the two closest palindromes to the given number.
    pair<long, long> getClosestPalindromes(const string& number) {
        const long originalNumber = stol(number);
        const int length = number.length();
        pair<long, long> closestPalindromes;
        const string halfNumber = number.substr(0, (length + 1) / 2);
        const string reversedHalfNumber = reverseString(halfNumber.substr(0, length / 2));
        const long candidatePalindrome = stol(halfNumber + reversedHalfNumber);

        if (candidatePalindrome < originalNumber) {
            closestPalindromes.first = candidatePalindrome;
        } else {
            const string previousHalf = to_string(stol(halfNumber) - 1);
            const string reversedPreviousHalf = reverseString(previousHalf.substr(0, length / 2));
            if (length % 2 == 0 && stol(previousHalf) == 0) {
                closestPalindromes.first = 9;
            } else if (length % 2 == 0 && previousHalf == "9") {
                closestPalindromes.first = stol(previousHalf + '9' + reversedPreviousHalf);
            } else {
                closestPalindromes.first = stol(previousHalf + reversedPreviousHalf);
            }
        }

        if (candidatePalindrome > originalNumber) {
            closestPalindromes.second = candidatePalindrome;
        } else {
            const string& nextHalf = to_string(stol(halfNumber) + 1);
            const string& reversedNextHalf = reverseString(nextHalf.substr(0, length / 2));
            closestPalindromes.second = stol(nextHalf + reversedNextHalf);
        }

        return closestPalindromes;
    }

    string reverseString(const string& str) {
        return {str.rbegin(), str.rend()};
    }
};