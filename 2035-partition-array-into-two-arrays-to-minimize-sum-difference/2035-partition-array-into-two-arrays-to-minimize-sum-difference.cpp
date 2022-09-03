class Solution {
public:
   // This function will generate  2-D vector where vec[i] will store sum of subsequnce of size i 

    void fun( int ind, int limit, int count, int sum, vector<int> &nums, vector<vector<int>> &part){
        if( ind == limit ){
            part[count].push_back(sum);
            return ;
        }
        
        fun(ind + 1, limit, count, sum, nums, part);
        fun(ind + 1, limit, count + 1, sum + nums[ind], nums, part);
    }
    
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        
        n = n/2;
        
        vector<int> first, last;
        for(int i = 0; i < 2 * n; i++){
            
            if( i < n/2)first.push_back(nums[i]);
            else last.push_back(nums[i]);
            
            sum += nums[i];
        }
        // cout<<sum;
        vector<vector<int>> part1(n+1, vector<int>()), part2(n+1, vector<int> ());
        
        fun(0, n, 0, 0, nums, part1);
        fun(n,2*n, 0, 0, nums, part2);
//         for(auto&v:part1){
//             for(int a:v)cout<<a<<" ";cout<<endl;
//         }
        
        
        for(auto &v:part2)sort(v.begin(), v.end());
        int halfSum = sum / 2;
        int ans = INT_MAX;
        for(int i = 0; i <= n; i++ ){
            for(int j = 0; j < part1[i].size(); j++){
                int currSum = part1[i][j];
                int index = lower_bound(part2[n - i].begin(), part2[n - i].end(), halfSum - currSum) - part2[n - i].begin();
                if(index == part2[n - i].size()) index--;
                
                int sumOfFirstSubset = currSum + part2[n - i][index];
                int sumOfSecondSubset = sum - sumOfFirstSubset;
                ans = min( ans, abs( sumOfFirstSubset - sumOfSecondSubset ));
            }
        }
        return ans;
    }
};