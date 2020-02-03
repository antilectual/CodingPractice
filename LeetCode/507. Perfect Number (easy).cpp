// LeetCode Problem 507. Perfect Number (easy)
// Algorithm: Iterate integers finding pairs of factors and adds them to a sum. Stops iterating when either all factors are summed or when the number is found to be an abundant number (sum > itself). If the sum doesn't match the number, returns false, otherwise return true.
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num < 6) // 6 is first perfect number
        {
            return false;
        }
        
        unsigned int sum = 1;
        int i = 3; // start with divisors being odd 
        int maxVal = num / 3;

        if(num % 2 == 0) // case of even
        {
            sum += 2;
            sum += num / 2;
        }
        while(i <= maxVal && sum <= num)
        {
            if(num % i == 0)
            {
                // adds both divisors and max is the new higher divisor.
                sum += i;
                if(num / i != i)
                {
                    sum += num / i;    
                }
                maxVal = (num / i) - 1;
            }
            i++;
        }
        
        if(sum != num)
        {
            return false;
        }
        return true;
    }
};