class Solution {
public:

    bool check(unordered_map<char,int> &freq)
    {
        for(auto i: freq)
        {
            if(i.second != 0)
            {
                return false;
            }
            
        }
        return true;

    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq;
        for(int i=0;i<s1.size();i++)
        {
            freq[s1[i]]++;
        }

        for(int i=0;i<s1.size();i++)
        {
            freq[s2[i]]--;
        }

        int l =0, r=s1.size()-1;
        for(r=s1.size()-1;r<s2.size();r++)
        {
            if(check(freq))
            {
                return true;
            }
            freq[s2[l]]++;
            l++;
            if(r+1<s2.size())
            {
                freq[s2[r+1]]--;
            }
        }
        return false;

    }
};
