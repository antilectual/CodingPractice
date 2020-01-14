//1281. Subtract the Product and Sum of Digits of an Integer
// Note:Question states "Given an integer number n, return the difference between the product of its digits and the sum of its digits.".
// However, submission requires the subtraction and not the absolute difference, so absolute value is not used in this solution.
class Solution {
public:
    int subtractProductAndSum(int n) {
        int tempNum = n, sum = 0, product = 1, current=0;
        while(tempNum > 0)
        {
            current = tempNum%10;     
            sum += current;
            product *= current;
            tempNum = tempNum/10;
        }
        return product-sum;
    }
};