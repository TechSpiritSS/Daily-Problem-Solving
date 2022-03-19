// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    long long factorial(int n)
    {
        long long fact = 1;
        for (int i = 2; i <= n; ++i)
            fact *= i;
        
        return fact;
    }
  public:
    long long findRank(string str) {
        //code here
        int n = str.size();
        long long ans = 0;
        
        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = i + 1; j < n; ++j)
                if (str[i] > str[j])
                    ++count;
            
            ans += count * factorial(n - (i + 1));
        }
        
        return (ans + 1);
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends