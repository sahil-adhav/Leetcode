class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();

        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        unordered_map<char,int> mp1;
        for(int i=0;i<n;i++){
            mp1[t[i]]++;
        }

        int count=0;
        for(auto i:mp){
            char ch=i.first;
            if(mp1[ch]){
                if(mp1[ch]<i.second){
                    count=count+(i.second-mp1[ch]);
                }
            }
            else{
                count=count+i.second;
            }
        }
        return count;
    }
};