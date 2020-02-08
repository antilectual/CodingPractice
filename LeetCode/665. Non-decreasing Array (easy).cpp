// LeetCode problem 665. Non-decreasing Array (easy)

// Algorithm: Iterate erray testing if the non-decreasing property holds. If it fails more than once, fail the test.
// When a number is found out of order, either it, or the number after it must change to restore order. If neither works, fail test.
// Side effect: nums will be modified in an array that is not non-decreasing when passed in.
// 
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 2;
        int numsSize = nums.size();
        for(int i = 0; i < numsSize - 1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                count--;
                if(i > 0)
                {
                    bool success;
                    int temp = nums[i+1];
                    nums[i+1] = nums[i];
                    success = testLocal(nums, max(0, i-1), min(numsSize, i+3));
                    if(!success)
                    {
                        nums[i+1] = temp;  // restore original before modifying next
                        temp = nums[i];
                        nums[i] = nums[i+1];
                        success = testLocal(nums, max(0, i-1), min(numsSize, i+3));
                        if(!success)
                        {
                            return false;
                        }
                    }
                    i--;
                }
            }
            if(count <= 0)
            {
                return false;
            }
        }
        return true;
    }
    
    // Tests the non-decreasing property of a section of a vector.
    bool testLocal(vector<int>& nums, int min, int max) {
        for(int i = min; i < max - 1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                return false;
            }
        }
        return true;
    }
};