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
        int l=0,r=0;
        freq[s[l]]++;
        while(l<n)
        {
            while(r>l && !check(freq,k))    
            {
                freq[s[r]]--;
                r--;
            }
            ans=max(ans,r-l+1);
            r++;
            if(r<n) freq[s[r]]++;
            while(r<n && check(freq,k) )
            {
                ans=max(ans,r-l+1);
                r++;
                if(r<n) freq[s[r]]++;
            }
            freq[s[l]]--;
            l++;
        }
        return ans;


    }
};
