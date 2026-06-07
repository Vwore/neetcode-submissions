class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int> result;

        for(int i=0; i< n; i++)
        {
            int value = temperatures[i];
            for(int j=i+1;j<n;j++)
            {
                if(value<temperatures[j])
                {
                    result.push_back(j-i);
                    break;
                }
            }
            if(result.size()!=i+1) result.push_back(0);
        }
        return result;
    }
};
