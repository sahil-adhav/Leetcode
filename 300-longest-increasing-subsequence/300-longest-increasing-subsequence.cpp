class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIdx = 0;

        for(int curr=0; curr<n; curr++){
            hash[curr] = curr;
            for(int prevInd=0; prevInd<curr; prevInd++){
                if(nums[prevInd] < nums[curr] && 1+dp[prevInd] > dp[curr]){
                    dp[curr] = 1 + dp[prevInd];
                    hash[curr] = prevInd;
                }
            }
            if(dp[curr] > maxi){
                maxi = dp[curr];
                lastIdx = curr;
            }
        }
        
        vector<int> list;
        list.push_back(nums[lastIdx]);
        
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            list.push_back(nums[lastIdx]);
        }
        
        reverse(list.begin(), list.end());
        
        for(auto it : list){
            cout << it << " ";
        }
        cout << endl;
        
        return maxi;
    }
};