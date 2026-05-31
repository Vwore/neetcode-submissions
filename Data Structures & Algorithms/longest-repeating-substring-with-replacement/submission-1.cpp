class Solution {
public:

    bool check(unordered_map<int,int> &freq,int k)
    {
        int total=0, highestFreq=-1;
        for(auto i : freq)
        {
            total+=i.second;
            if(freq[highestFreq] <i.second)
            {
                highestFreq = i.first;
            }
        }
        return (total - freq[highestFreq])<=k;
    }
    // AAABABB
    int characterReplacement(string s, int k) {
        int n = s.size(),ans=1;
        unordered_map<int,int> freq;
        if(n==0) return 0;
        int l=0,r=0,maxFreq=0;
        
        for(r=0;r<n;r++)
        {
            freq[s[r]]++;
            maxFreq = max(maxFreq,freq[s[r]]);
            while((r-l+1)-maxFreq>k)
            {
                freq[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        
        return ans;


    }
};
