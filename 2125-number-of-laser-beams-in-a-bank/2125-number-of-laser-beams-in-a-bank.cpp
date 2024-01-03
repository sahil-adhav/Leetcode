class Solution {
public:
template <typename InputIt, typename T>
int countOwn(InputIt first, InputIt last, const T& value) {
    int count = 0;
    for (InputIt it = first; it != last; ++it) {
        if (*it == value) {
            ++count;
        }
    }
    return count;
}
    
    int numberOfBeams(vector<string>& bank) {
        int len = bank.size();
        int previous = 0, current = 0, totalLines = 0;
        
        for(int i=0; i<len; i++){
            current = countOwn(bank[i].begin(), bank[i].end(), '1');
            if(current > 0){
                totalLines += current * previous;
                previous = current;
            }
        }
        return totalLines;
    }
};