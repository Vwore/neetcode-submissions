class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> st;
        int n = nums.size();
        for(int i=0;i<k-1;i++)
        {
            st[nums[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<n-k+1;i++)
        {
            st[nums[i+k-1]]++;
            auto maxele = st.rbegin();
            ans.push_back(maxele->first);
            st[nums[i]]--;
            if(st[nums[i]]==0) st.erase(nums[i]);
        }

        return ans;
    }
};
