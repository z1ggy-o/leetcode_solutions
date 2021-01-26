/* 415 - Add Strings
 * 
 * Given two non-negative intefers represented as string.
 * Return the sum of these two integers also by string.
 *
 * Because the length of the input string can over 5000, we cannot convert
 * them to int. (And we also do not need to)
 * Instead, we do the addition like we do it using a pen.
 * From the lower digit to higher digit, we add the each digit of two number
 * and also the carry. 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int sum = 0;
        string ret;
        
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {  // current bit
                sum += num1[i--] - '0';
            }
            if (j >= 0) {
                sum += num2[j--] - '0';
            }
            sum += carry;
            
            if (sum / 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            
            ret = (char)(sum % 10 + '0') + ret;  // sum of current bit
            
            sum = 0;
        }
        return ret;
    }
};
