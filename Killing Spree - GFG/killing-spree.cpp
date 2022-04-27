// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        // n * (n + 1) * (2n + 1) / 6
        
        long long int low = 1, high = sqrt(n), mid, curr;
        
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            curr = (mid * (mid + 1) * (2 * mid + 1)) / 6;
            if (curr == n)
                return mid;
            else if (curr < n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low - 1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends