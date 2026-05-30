class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> frequency = {};
        for(int i=0;i<nums.size();i++)
        {
            int count=1;
            while(i+1<nums.size() && nums[i+1]==nums[i])    
            {
                i++;
                count++;
            }
            frequency.push_back(count);
        }
        sort(frequency.begin(),frequency.end());
        int minFreq= frequency[frequency.size()-k];
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int count=1;
            while(i+1<nums.size() && nums[i+1]==nums[i])    
            {
                i++;
                count++;
            }
            if(count>=minFreq) ans.push_back(nums[i]);
        }
        return ans;
    }
};
