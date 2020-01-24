// LeetCode problem 985. Sum of Even Numbers After Queries (easy)

// Initial "solution".  Recalculate full sum of even values in A for every query.
// O(A * queries).  Exceeds time limit.
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> answer; 
        for(int i = 0; i < queries.size(); i++)
        {
            int tempSum = 0;
            A[queries[i][1]] += queries[i][0];
            for(int j = 0; j < A.size(); j++)
            {
                if(A[j] % 2 == 0)
                {
                    tempSum += A[j];
                }
            }
            answer.push_back(tempSum);
        }
        return answer;
    }
};