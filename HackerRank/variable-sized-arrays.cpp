#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n, q, curLength, numDimensions, tempVal;
    numDimensions = 2;
    cin >> n >> q;
    vector<vector<int>> arrayList(n);
    vector<vector<int>> queryList(q);
    // Find all arrays
    for(int i = 0; i < n; i++)
    {  
        // get the length of the array
        cin >> curLength;
        arrayList[i].resize(curLength);
        // find curLength number of values for current array
        for(int j = 0; j < curLength; j++)
        {
            cin >> tempVal;
            arrayList[i][j] = tempVal;
        }
    }
    // Find all queries
    for(int i = 0; i < q; i++)
    {
        queryList[i].resize(numDimensions);
        for(int j = 0; j < numDimensions; j++)
        {
            cin >> tempVal;
            queryList[i][j] = tempVal;
        }

        // output query values
        cout << arrayList[queryList[i][0]][queryList[i][1]] << endl;

    }
    
    return 0;
}

