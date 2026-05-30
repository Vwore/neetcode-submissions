class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elements;
        int n=nums.size(),ans=1;
        if(n==0) return 0;
        for(int i=0;i<n;i++)
        {
            elements.insert(nums[i]);
        }

        for(auto i: elements)
        {
            if(elements.find(i-1)!= elements.end()) continue;
            int curr=1,value=i;
            while(elements.find(value+1)!=elements.end()) 
            {
                curr++;
                value++;
            }
            ans=max(ans,curr);
        }

        return ans;
    }
};
