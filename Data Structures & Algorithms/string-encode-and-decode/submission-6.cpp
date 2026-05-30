class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(int i=0;i<strs.size();i++)
        {
            encoded+= to_string(strs[i].size()) + "#" + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        int i=0;
        while(i<s.size())
        {
            int j=i;
            while(s[j] !='#')
            {
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            string tempStr= s.substr(j+1,length);
            answer.push_back(tempStr);
            i=j+1+length;
        }

        return answer;
    }
};
