#include <vector>
using namespace std;

/* two pointers
 *
 * The problem can be converted to "What is the next member that I should put here?"
 * First, we need a pointer to iterate the array.
 * Then, we need another pointer to indicate current position that we want to put a new member into.
 */
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int size = nums.size();
            int i = 0;
            for (int j = 0; j < size; j++) {
                if (nums[j] != val) {
                    nums[i++] = nums[j];
                }
            }
            return i;
        }
};
