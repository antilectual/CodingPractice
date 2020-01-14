//1281. Subtract the Product and Sum of Digits of an Integer
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