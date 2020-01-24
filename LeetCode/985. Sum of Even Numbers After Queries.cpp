// LeetCode problem 985. Sum of Even Numbers After Queries (easy)

// Initial "solution".  Recalculate full sum of even values in A for every query.
// O(A * queries).  Exceeds time limit.

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> answer(queries.size()); 
        int sumA = 0;
        // find the initial SUM of evens
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] % 2 == 0)
            {
                sumA += A[i];
            }
        }
        
        //iterate the queries modifying values in A modifying A's sum of evens result (sumA)
        for(int i = 0; i < queries.size(); i++)
        {
            // subtract even values from the current index
            if((A[queries[i][1]]) % 2 == 0)
            {
                sumA -= A[queries[i][1]];
            }
            
            // modify the appropriate index to the appropriate value (adding)
            A[queries[i][1]] += queries[i][0];
            
            // if the current index is modified to be even, add it to the sum
            if(A[queries[i][1]] % 2 == 0)
            {
                sumA += A[queries[i][1]];
            }
            
            answer[i] = sumA;
        }
        return answer;
    }
};