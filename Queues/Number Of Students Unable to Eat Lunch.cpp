#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud, sand;
        int n = students.size();

        for(int i = 0; i < n; i++) {
            stud.push(students[i]);
            sand.push(sandwiches[i]);
        }

        int unableToEatCount = 0;  // Counter for students unable to eat

        while(!stud.empty()) {
            if(stud.front() == sand.front()) {
                stud.pop();
                sand.pop();
                unableToEatCount = 0;  // Reset the counter
            } else {
                int num = stud.front();
                stud.pop();
                stud.push(num);
                unableToEatCount++;

                // If all remaining students are unable to eat the current sandwich
                if(unableToEatCount == stud.size()) {
                    break;
                }
            }
        }

        return stud.size();
    }
};