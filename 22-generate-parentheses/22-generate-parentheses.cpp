class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        n*=2;
        int num_bit = (1<<n);
        
        //   1 -> set (
                     //    0 -> unset )
        
        vector<string>str;
        int num_0,num_1;
        
        for(int i=1;i<num_bit;i++)
        {
            num_0 =0;
            num_1 = 0;
            string ss = "";
            for(int j = 0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    num_1++;
                    ss.push_back('1');
                }
                else{
                    num_0++;
                    ss.push_back('0');
                }
            }   
            
            if(num_1!=num_0)
            {
                continue;
            }
            string s = "";
            int p=0,q =0;
            bool ck = true;
            for(int i=0;i<n;i++)
            {
                if(ss[i]=='0')
                {
                    q++;
                    s.push_back(')');
                }
                else{
                    p++;
                    s.push_back('(');
                }
                
                if(q>p)
                {
                    ck = false;
                }
            }
            
            if(ck==false)
            {
                continue;
            }
            else{
                str.push_back(s);
            }
        }
        
        return str;
    }
};