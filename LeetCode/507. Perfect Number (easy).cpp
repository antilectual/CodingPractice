// Leetcode Problem 507. Perfect Number (easy)
// Algorithm: The solution to all perfect numbers < 100,000,000 has already been found. Since it is only 5 values, make an array with these values and return if the value is found in the array. O(1) time, o(1) space. Array used rather than vector for minor optimization.
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int perfectNumbers[5] = {6, 28, 496, 8128, 33550336};
        for(int i = 0; i < 5; i++)
        {
            if (num == perfectNumbers[i])
                return true;
        }
        return false;
    }
};