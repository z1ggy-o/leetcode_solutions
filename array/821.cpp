/* 821. Shortest distance to a character
 *
 * Idea:
 * Go through the array, and see if the current character is the specified one.
 * If it is, we recompute the distance of all the other chars with it.
 *
 * Time complexity: O(N^2)
 *
 * We can optimize the time complexity to O(N).
 */
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ret(S.length(), 10000);
        int tmp;
        int start = 0;
        
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C) {
                for (int j = 0; j < S.length(); j++) {
                    tmp = abs(i - j);
                    if (tmp < ret[j])
                        ret[j] = tmp;
                }
            }
        }
        
        return ret;
    }
};
