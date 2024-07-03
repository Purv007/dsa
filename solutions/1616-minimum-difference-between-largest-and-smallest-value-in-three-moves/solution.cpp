class Solution {
public:
    static int minDifference(vector<int>& nums) {
        const int n=nums.size();
        if (n<=4) return 0;
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>> big;
        for (int x :nums){
            if (small.size()>3){
                if (x<small.top()){
                    small.pop();
                    small.push(x);
                }
            }
            else small.push(x);
            if (big.size()>3){
                if (x>big.top()){
                    big.pop();
                    big.push(x);
                }
            }
            else big.push(x);
        }
        
        int Big[4];
        for(int i=3; i>=0; i--){
            Big[i]=big.top();
            big.pop();
        }

        // difference by considering 4 scenarios
        int min_diff=INT_MAX;
        for (int i=0; i<=3; i++){ 
            int Small=small.top();
            small.pop();
            min_diff=min(min_diff, Big[i]-Small);
        }

        return min_diff;
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
