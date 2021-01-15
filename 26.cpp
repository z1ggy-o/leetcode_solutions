#include <vector>
using namespace std;

/* two pointers
 *
 * Because the array has already been sorted, if there is any duplicate members
 * they must be placed together. There are only two situation:
 * 1. Current one and the following one is same
 * 2. Current one and the following one is not same
 */
class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      int it1, it2;

      // handle edge case (empty array)
      if (size == 0) return size;

      for (it1 = 0, it2 =1; it2 < size; it2++) {
        if (nums[it1] != nums[it2]) {
          nums[++it1] = nums[it2];
        }
      }

      return (it1 + 1);
    }
};
