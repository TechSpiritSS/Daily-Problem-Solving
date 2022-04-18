// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long int pow(long long int a, long long int b, long long int p) {
    	long long int res = 1;
    	a %= p;
    	while (b) 
    	{
    		if (b & 1)
    		    res = (res * a) % p;
    		b = b >> 1;
    		a = (a * a) % p;
    	}
    	return res;
    }
    
    long long karyTree(int k, int m) {
        return pow(k, m, 1e9 + 7);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends