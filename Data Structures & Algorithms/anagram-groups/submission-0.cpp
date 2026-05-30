class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mapping;

        int n= strs.size();

        for(int i=0;i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(mapping.find(s) == mapping.end())
            {
                mapping[s]={i};
            }
            else{
                mapping[s].push_back(i);
            }
        }
        vector<vector<string>> answer;
        for(auto i: mapping)
        {
            vector<string> temp;
            for(int j=0;j<i.second.size();j++)
            {
                temp.push_back(strs[i.second[j]]);
            }
            answer.push_back(temp);
        }

        return answer;
    }
};
