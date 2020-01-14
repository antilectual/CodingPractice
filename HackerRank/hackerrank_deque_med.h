/* hackerrank Deque-STL 
	Not using deque!
*/
#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    int currentMax = arr[0];

    // Note: test n < k?

    // find initial max
    for(int i = 0; i < k; i++)
    {
        if(arr[i] > currentMax)
        {
            currentMax = arr[i];
        }
    }
    cout << currentMax;
    // only print space if it is not the last
    if (k < n)
    {
        cout << " ";
    }
	for(int i = k; i < n; i++)
    {
        // popped == max?
        if(arr[i-k] == currentMax)
        {
            // new >= last max: means new is new max
            if(arr[i] >= currentMax)
            {
                currentMax = arr[i];
            }
            // popped isn't max, last isn't max.. need to find max
            else
            {
                currentMax = 0;
                for(int j = i-k +1; j <= i; j++)
                {
                    if(arr[j] > currentMax)
                    {
                        currentMax = arr[j];
                    }
                }
            }
        }
        // else new is < or > max..
        else 
        {
            // test if it's > max
            if(arr[i] > currentMax)
            {
                currentMax = arr[i];
            }
        }
        cout << currentMax;
        if(i < n)
        {
            // only print space if it's not the last.
            cout << " ";
        }
    }
    cout << endl;
}

int main(){
    // speed up IO
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // 
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

