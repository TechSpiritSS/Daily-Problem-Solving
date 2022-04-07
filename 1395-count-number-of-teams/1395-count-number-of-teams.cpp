class Solution {
public:
    int numTeams(vector<int>& rating)
    {
        int n = rating.size();
        int pref_1[n+1],pref_2[n+1];
        int aa[n+1];
        for(int i=0;i<n;i++)
        {
            aa[i+1] = rating[i];
        }
        
        pref_1[n] = 0;    //  small
        pref_2[n] = 0;          //    big
        
        int big,small;
        for(int i=1;i<n;i++)
        {
            big= 0;
            small =0;
            for(int j = (i+1);j<=n;j++)
            {
                if(aa[j]>aa[i])
                {
                    big++;
                }
                else if(aa[j]<aa[i])
                {
                    small++;
                }
            }
            pref_1[i] = small;
            pref_2[i] = big;
        }
        
        int ans = 0;
        
        // for(int i = 1;i<=n;i++)
        // {
        //     cout<<pref_1[i]<<" "<<pref_2[i]<<"\n";
        // }
      
        for(int i=1;i<n-1;i++)
        {
            for(int j = (i+1);j<n;j++)
            {
                if(aa[j]>aa[i])
                {
                    ans += pref_2[j];
                }
                if(aa[j]<aa[i])
                {
                    ans += pref_1[j];
                }  
            }
        }
        
        return ans;
    }
};