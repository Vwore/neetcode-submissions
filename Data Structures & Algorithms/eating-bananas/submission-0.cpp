class Solution {
public:

    int check(vector<int> &piles,int speed)
    {
        int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            int value = piles[i];
            ans+=value/speed;
            if(value%speed != 0) ans+=1;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1, r=1000000000,ans=1000000000;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(piles,mid)<=h)
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
