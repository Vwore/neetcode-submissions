class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n=temperatures.size();
        vector<int> result(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty()) result[i] =0;
            while(!s.empty())
            {
                auto temp = s.top();
                if(temperatures[i]<temp.first)
                {
                    result[i] = temp.second - i;
                    break;
                }
                s.pop();
            }
            if(s.empty()) result[i] = 0;
            s.push({temperatures[i],i});
        }
        return result;
    }
};
