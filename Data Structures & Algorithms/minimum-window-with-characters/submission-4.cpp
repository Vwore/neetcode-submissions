class Solution {
public:

    bool check(unordered_map<char,int> &freq,unordered_map<char,int> &freqT)
    {
        for(auto i: freqT)
        {
            if(freq[i.first]<i.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> freq, freqT;
        pair<int,int> minStr = {0,INT_MAX};
        int n = s.size(),m=t.size();
        if(m>n) return "";

        for(int i=0;i<m;i++)
        {
            freqT[t[i]]++;
        }

        int l =0;

        for(int r=0;r<n;r++)
        {
            // cout<<l<<" "<<r<<endl;
            freq[s[r]]++;
            while(check(freq,freqT))
            {
                // cout<<l<<' '<<r<<endl;
                if((minStr.second - minStr.first)> r-l)
                {
                    // cout<<"condition match"<<l<<' '<<r<<endl;
                    minStr= {l,r};
                }
                freq[s[l]]--;
                l++;
            }
        }
        if(((minStr.second-minStr.first)+1)>n)
        {
             return "";
        }
        string ans = s.substr(minStr.first,(minStr.second- minStr.first+1));
        return ans;
    }
};
