class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }

        vector<int> freqArray;
        for(auto i:freq)
        {
            freqArray.push_back(i.second);
        }
        sort(freqArray.begin(),freqArray.end());
        // if(freqArray.size()==k)
        // {

        // }
        int minFreq = freqArray.size()==k? 0:freqArray[freqArray.size()-k-1];
        vector<int> ans;
        for(auto i: freq)
        {
            if(i.second>minFreq) 
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};
