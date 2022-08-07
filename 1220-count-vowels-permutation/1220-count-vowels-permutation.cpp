/*
vowels = {'a', 'e', 'i', 'o', 'u'};
a - e
e - a / i
i - a / e / o / u
o - i / u
u - a

a = e + u + i
e = a + i
i = e + o
o = i
u = i + o

*/

class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = (1e9) + 7; 
        vector<long> p(5, 1);
        vector<long> c(5);

        int ans = 0;
        
        while (--n)
        {
            c[0] = (p[1] + p[2] + p[4]) % mod;
            c[1] = (p[0] + p[2]) % mod;
            c[2] = (p[1] + p[3]) % mod;
            c[3] = (p[2]) % mod;
            c[4] = (p[2] + p[3]) % mod;
            p = c;
        }
        
        for (int i = 0; i < 5; ++i)
            ans = (ans + p[i]) % mod;
        
        return ans % mod;
    }
};
