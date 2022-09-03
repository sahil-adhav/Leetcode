class Solution {
public:
    int numOfSub(int ind, int sum, vector<vector<int>> &dp, vector<int> &num){

    
    if(ind == 0){
        if(sum == 0 and num[0]==0) return 2;
        if(sum == 0 or sum == num[0])return 1;
        return 0;
    }
    
    if(dp[ind][sum] != -1){
        return dp[ind][sum];
    }
    
    int notPick = numOfSub(ind-1, sum, dp, num);
    int pick = 0;
    if(num[ind] <= sum){
        pick = numOfSub(ind-1, sum-num[ind], dp, num);
    }
    return dp[ind][sum] = (pick + notPick);
}

int findWays(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    return numOfSub(n-1, tar, dp, num);
}

// s1 and  s2
// s1 - s2 = d
//totalSum =sum(arr) ==> s1 + s2 = totalSum
//                   ==> s1 = totalSum - s2

// s1 - s2 = d
// totalSum - s2 - s2 = d
// totalSum - 2*s2 = d
// s2 = totalSum - d/ 2

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(auto it : arr) totalSum += it;
    
    if(totalSum - d < 0 or (totalSum-d)%2) return false;
    return findWays(arr, (totalSum-d)/2);
}
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};