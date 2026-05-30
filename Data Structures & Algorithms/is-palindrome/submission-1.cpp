class Solution {
public:
    bool alphaNumeric(char c)
    {
        if(c-'a'>=0 && c-'a'<26) return true;
        if(c-'A'>=0 && c-'A'<26) return true;
        if(c-'0'>=0 && c-'0'<10) return true;
        return false;
    }
    bool isPalindrome(string s) {
        string newStr="";
        for(int i=0;i<s.size();i++)
        {
            if(alphaNumeric(s[i]))
            {
                newStr.push_back(s[i]);
            }
        }
        // cout<<newStr;
        int l=0,r=newStr.size()-1;
        while(l<=r)
        {
            if(tolower(newStr[l])!=tolower(newStr[r]))
            {
                return false;
            }
            l++;
            r--;
        }
        return true;

    }
};
