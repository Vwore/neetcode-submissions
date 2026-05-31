class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> characters;
        int ans=0;
        int l=0,r=0;
        for(r=0;r<n;r++)
        {
            // characters.insert(s[r]);
            while(characters.find(s[r])!=characters.end() && l!=r)
            {
                characters.erase(s[l]);
                l++;
            }
            ans=max(ans,r-l+1);
            characters.insert(s[r]);
        }
        return ans;
    }
};
