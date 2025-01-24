class Solution {
public:
    string minWindow(string source, string target) {
    if (target.size() > source.size()) return "";

    unordered_map<char, int> targetCount, windowCount;
    for (char c : target) targetCount[c]++;

    int left = 0, right = 0;
    int matchedCharacters = 0;
    int minWindowLength = INT_MAX;
    int windowStart = 0;

    while (right < source.size()) {
        char currentChar = source[right];
        right++;

        // Update the window count for the current character
        if (targetCount.count(currentChar)) {
            windowCount[currentChar]++;
            if (windowCount[currentChar] == targetCount[currentChar]) {
                matchedCharacters++;
            }
        }

        // Shrink the window while it's valid
        while (matchedCharacters == targetCount.size()) {
            if (right - left < minWindowLength) {
                minWindowLength = right - left;
                windowStart = left;
            }

            char charToRemove = source[left];
            left++;

            // Update the window count and matched characters
            if (targetCount.count(charToRemove)) {
                if (windowCount[charToRemove] == targetCount[charToRemove]) {
                    matchedCharacters--;
                }
                windowCount[charToRemove]--;
            }
        }
    }

    return minWindowLength == INT_MAX ? "" : source.substr(windowStart, minWindowLength);
}

};