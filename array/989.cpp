/* 989 Add to Array-Form of Integer 
 *
 * Idea
 * Because the give array can be huge, we cannot convert the array to interger first.
 * Instead, we add each digit from lower to higher as we do the addition manually.
 */
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        queue<int> q;
        stack<int> s;
        vector<int> ret;
        int tmp;
        int sum;
        int carry = 0;
        
        while (K) {
            q.push(K % 10);
            K /= 10;
        }
        
        int a_size = A.size();
        int k_size = q.size();
        int n = a_size > k_size ? a_size : k_size;
        
        int j = a_size - 1;
        for (int i = n - 1; i >= 0; i--) {
            
            if (!q.empty()) {
                tmp = q.front();
                q.pop();
            } else {
                tmp = 0;
            }
            
            if (j >= 0)
                sum =  A[j--] + tmp + carry;
            else
                sum = tmp + carry;
            
            if (sum / 10) 
                carry = 1;
            else
                carry = 0;
            
            s.push(sum % 10);
        }
        
        if (carry)
            s.push(1);
        
        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            ret.push_back(tmp);
        }
        
        return ret;
    }
};
