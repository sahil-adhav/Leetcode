class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp1;
        for(auto it: arr){
            mp1[it]++;
        }
        vector<int> v;
        for(auto it: mp1){
            v.push_back(it.second);     
        }
        sort(v.begin(), v.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==v[i+1]){
                return false;
            }
        }
        return true;
    }
};