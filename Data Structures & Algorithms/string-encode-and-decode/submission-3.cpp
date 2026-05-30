class Solution {
public:
    vector<int> sizes;
    string encode(vector<string>& strs) {
        string encoded ="";
        for(int i=0;i<strs.size(); i++)
        {
            encoded+=strs[i];
            sizes.push_back(strs[i].size());
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        int start = 0;
        for(int i=0;i<sizes.size();i++)
        {
            int j=start;
            string temp="";
            while(j<s.size() && j<start+sizes[i])
            {
                temp.push_back(s[j++]);
            }
            answer.push_back(temp);
            start = j;
        }
        return answer;
    }
};
