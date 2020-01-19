// LeetCode 1323. Maximum 69 Number (easy)

// Algorithm:  - Finds the most significant 6 digit and changes it to a 9.
class Solution {
public:
    int maximum69Number (int num) {
        int tempNum = num;
        int digitPlace = 0;
        int lastSixPlace = -1;
        while(tempNum > 0)
        {
            if(tempNum % 10 == 6)
            {
                lastSixPlace = digitPlace;
            }
            digitPlace++;
            tempNum /= 10;
        }
        num += 3 * pow(10, lastSixPlace);
        return num;
    }
};