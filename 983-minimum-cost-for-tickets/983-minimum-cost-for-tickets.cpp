class Solution {
public:
    
    int minCost(int ind, vector<int> &dp, vector<int>& days, vector<int>& costs){
        //Base Case
        if(ind >= days.size()){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        //Choice 1
        int choice_1 = costs[0] + minCost(ind+1, dp, days, costs);
        
        
        //Choice 2
        int currInd = ind;
        while(currInd < days.size() && days[currInd] < days[ind]+7){
            currInd++;
        }
                                   
        int choice_2 = costs[1] + minCost(currInd, dp, days, costs);
        
        //Choice 3
        while(currInd < days.size() && days[currInd] < days[ind]+30){
            currInd++;
        }
        
        int choice_3 = costs[2] + minCost(currInd, dp, days, costs);
        
        return dp[ind] = min({choice_1, choice_2, choice_3});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d = days.size();
        vector<int> dp(d+1, -1);
        return minCost(0, dp, days, costs);
    }
};