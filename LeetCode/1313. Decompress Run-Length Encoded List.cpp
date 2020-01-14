//1313. Decompress Run-Length Encoded List
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> decompressedRLEL;
        int tempCount;
        for(int i = 0; i < nums.size();i++)
        {
            if(i%2 == 0)
            {
                tempCount = nums[i];   
            }
            else
            {
                for(int j = 0; j < tempCount; j++)
                {
                    decompressedRLEL.push_back(nums[i]);
                }
            }
        }
        return decompressedRLEL;
    }
};