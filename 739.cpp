/* 739. Daily temperatures
 *
 * Modeling:
 *   String. Find first number that bigger than the current one.
 *
 * Complexity:
 *   O(N^3). One pointer iterates the whole list, another iterates the remaining entries.
 *
 * Cannot pass. The time complexity is high.
 */
#include <vector>
using namespace std;

class SlowSolution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size(), 0);

        for (int i = 0; i < T.size(); i++) {
            for (int j = i + 1; j < T.size(); j++) {
                if (T[j] > T[i]) {
                    ret[i] = j - i;
                    break;
                }
            }
        }
        return ret;
    }
};

/*
 * To reduce the time complxity, we need to store the middle values. Thus, we do not
 * need to go through remaining list every iteration.
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size(), 0);
        stack<int> s;

        for (int i = 0; i < T.size(); i++) {
            while (!s.empty() && T[i] > T[s.top()]) {  // smallest one on top of stack
                int idx = s.top();
                s.pop();
                ret[idx] = i - idx;
            }
            s.push(i);  // there is no temp lower than ith anymore, put i into the stack
        }
        return ret;
    }
};
