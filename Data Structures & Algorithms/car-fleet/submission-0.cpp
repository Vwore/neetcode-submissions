class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = position.size();
        for(int i=0;i<n;i++)
        {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());
        cout<<cars[n-1].first<<' '<<cars[n-1].second<<endl;
        vector<double> timeToTarget(n,-1);
        timeToTarget[n-1] = ((target -(double)cars[n-1].first))/((double)cars[n-1].second);
        // cout<<timeToTarget[n-1]<<endl;
        for(int i=n-2;i>=0;i--)
        {
            double directTime = (target -(double)cars[i].first)/((double)cars[i].second);
            if(directTime<timeToTarget[i+1])
            {
                timeToTarget[i]=timeToTarget[i+1];
            }
            else{
                timeToTarget[i] = directTime;
            }
            // cout<<timeToTarget[i]<<endl;
        }
        int i=0, ans=0;
        while(i<n)
        {
            ans++;
            while(i+1<n && timeToTarget[i+1] == timeToTarget[i] )         i++;
            i++;
        }
        return ans;
    }
};
