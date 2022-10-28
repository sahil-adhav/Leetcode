class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> bigMp;
        vector<vector<string>> ans;
        
        for(auto str : strs)
        {
            string tmp = str;
            sort(str.begin(), str.end());
            bigMp[str].emplace_back(tmp);            
        }
        
        for(auto x : bigMp)
        {
            vector<string> tmp = x.second;
            ans.emplace_back(tmp);
        }
        return ans;
    }
};