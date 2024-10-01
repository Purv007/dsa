class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>freq(k);
        // unordered_map<int,bool> visited;
        for(auto x:arr){
            int fre= ((x % k) + k) % k;
            freq[fre]++;
        }
        for(auto i:arr){
            // if(!visited[i]){
                int rem=((i % k) + k) % k;
                if(rem==0){
                    if(freq[rem]%2==1) return false;
                    else continue;
                }
                if(freq[rem]==freq[k-rem]){
                    continue;
                }
                else{
                    return false;
                }
            // }
        }
        return true;
    }
};
