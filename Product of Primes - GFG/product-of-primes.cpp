// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long primeProduct(long long L, long long R){
       // code here
       long long mul = 1;
       long long p = 1e9 + 7;
       for (int i = L; i <= R; ++i)
       {
           bool x = 1;
           for (int j = 2; j <= sqrt(i); ++j)
           {
               if(i % j == 0)
               {
                   x = 0;
                   break;
               }
           }
           if (x)
             mul = (mul * i) % p;  
       }
       return mul;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends