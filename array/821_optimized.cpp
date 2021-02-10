/* 821. Shortest path to char
 *
 * In the non-optimized version, we recompute all the distiance between current
 * char with other chars, which is a wasting of time because there has many
 * nonnecessary operations.
 *
 * Actually, with one iteration, we can get the shortest distance of each char
 * in the array in one direction (e.g., left to right)
 * We only need to traverse the array from another direction again and compare
 * the two distances from two directions.
 *
 * Time complexity: O(N)
 */

class Solution {
  public:
    vector<int> shortestToChar(string S, char C) {
      vector<int> ret(S.size(), 0);    

      int prev = -10000;  // index of previous specified char

      for (int i = 0; i < S.size(); i++) {
        if (S[i] == C) prev = i;
        ret[i] = i - prev;  // distance with the cloest C, left to right
      }

      prev = 20000;
      for (int i = 0; i < S.size(); i++) {
        if (S[i] == C) prev = i;
        ret[i] = min(ret[i], prev - i);  // distance, right to left
      }

      return ret;
    }
};
