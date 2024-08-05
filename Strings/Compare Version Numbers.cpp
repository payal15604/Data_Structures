#include <string>
#include <algorithm>

class Solution {
public:
    int compareVersion(const std::string& version1, const std::string& version2) {
        int i = 0, j = 0;
        int len1 = version1.size(), len2 = version2.size();

        while (i < len1 || j < len2) {
            int num1 = 0, num2 = 0;

            while (i < len1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                ++i;
            }

            while (j < len2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                ++j;
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            ++i; // Skip the '.' in version1
            ++j; // Skip the '.' in version2
        }

        return 0;
    }
};
