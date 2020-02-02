// LeetCode problem 852. Peak Index in a Mountain Array (easy)
// Algorithm: special case binary-search for peak value;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = (A.size() - 1) / 2;
		int max = A.size() - 1;
		int min = 0;
        while(true)
        {
			if(i > 0 && i < A.size() - 1)
			{
				if(A[i] > A[i + 1] && A[i] > A[i-1]) // case: peak is found
				{
					break;
				}
				else if(A[i] > A[i-1]) // case: we need to traverse right
				{
					min = i;
					i = (i + max) / 2;
                    if(i == min) // case: getting i + 0.5
                    {
                        i++;
                    }
				}
				else // case: we need to traverse left
				{
					max = i;
					i = (i + min) / 2;
                    if(i == max) // case: getting i - 0.5
                    {
                        i--;
                    }
				}
			}
			else // case: top of the mountain is start/end
			{
				break;
			}
        }
        return i;
    }
};