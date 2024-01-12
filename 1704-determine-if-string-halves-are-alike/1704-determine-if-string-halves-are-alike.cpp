class Solution {
public:
    bool halvesAreAlike(string s) {
          int count1=0,count2=0;
        
        set<char>f={'a','e','i','o','u','A','E','I','O','U'};
        
        
        int mid= s.size()/2;  
        int second=mid;
        int first=0;
        
        
        while(first<mid){
            auto it=f.find(s[first]);
            if(it!=f.end()){
                count1++;
            }
            
            auto itt=f.find(s[second]);
            
            if(itt!=f.end()){
                count2++;
            }
          
            first++;
            second++;
            
        }
            
      
        return count1==count2;
    }
};