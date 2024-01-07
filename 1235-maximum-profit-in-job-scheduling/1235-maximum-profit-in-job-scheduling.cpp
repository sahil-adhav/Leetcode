struct Project {
    int start;
    int end;
    int profit;

    Project(int s, int e, int p) : start{s}, end{e}, profit{p} {}

    bool operator<(const Project& other) const {
        return start < other.start;
    }

    bool operator<(int time) const {
        return start < time;
    }
};

class Solution {
public:

    int knapsack(const vector<Project>& projects, int idx, vector<int>& dp) {
        if (idx >= projects.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        int currprofit;
        // do not choose this project.
        currprofit = knapsack(projects, idx+1, dp);

        // choose this project.
        // find next available project. their start_time must be >= this end_time.
        auto it = lower_bound(projects.begin() + idx, projects.end(), projects[idx].end);
        if (it == projects.end()) {
            // no more projects available. Compare against current profit only.
            currprofit = max(currprofit, projects[idx].profit);
        } else {
            currprofit = max(currprofit, projects[idx].profit + knapsack(projects, it - projects.begin(), dp));
        }

        return dp[idx] = currprofit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        /* strat

        Sort by start time.
        Evaluate profit of taking each next eligible project.
        Use DP to cache the maximum profit from taking a project + later.
        */

        vector<Project> projects;
        for (int i=0;i<startTime.size();++i){
            projects.emplace_back(startTime[i], endTime[i], profit[i]);
        }

        sort(projects.begin(), projects.end());
        vector<int> dp(projects.size(), -1);

        // knapsack - either choose to take a project or skip it.
        // if take project, fast forward to next eligible project via binary search.
        knapsack(projects, 0, dp);

        return dp[0];
    }
};
