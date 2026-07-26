class KthLargest {
public:
    int kValue;
    vector<int> stream;
    KthLargest(int k, vector<int>& nums) {
        kValue = k;
        for(int i=0;i<nums.size();i++)
        {
            stream.push_back(nums[i]);
        }
        sort(stream.begin(),stream.end());
        // return stream[nums.size()-k];
    }
    
    int add(int val) {
        stream.push_back(val);
        sort(stream.begin(),stream.end());
        return stream[stream.size()-kValue];
    }
};
