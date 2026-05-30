class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,bool> element;
        int n=nums.size(), ans=1;
        for(int i=0;i<n;i++)
        {
            element[nums[i]] =false;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int value = nums[i];
            if(element[nums[i]]) continue;
            int length =1;
            while(element.find(value+1) != element.end())
            {
                length++;
                value++;
                element[value]=true;
            }
            ans=max(ans,length);
        }

        return ans;
    }
};
