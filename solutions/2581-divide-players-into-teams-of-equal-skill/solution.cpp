class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum=0;
        int n=skill.size();
        if(n==2) return skill[0]*skill[1];
        for(auto i: skill){
            sum+=i;
        }
        if(sum % (n / 2) != 0) return -1;
        long long skills=(2*sum)/n;
        long long res=0;
        sort(skill.begin(),skill.end());
        int j=n-1;
        for(int i=0;i<n/2;i++){
            if(skill[i]+skill[j]==skills){
                res+=(long long)skill[i] *(long long)skill[j];
            }
            else return -1;
            j--;
        }
        return res;
    }
};

// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {
//         long long sum = 0;
//         int n = skill.size();
        
//         // Calculate total sum of skills
//         for(auto i: skill) {
//             sum += i;
//         }
        
//         // Calculate expected skill per pair
//         if(sum % (n / 2) != 0) return -1;  // If the total skill can't be divided equally
//         long long skills = sum / (n / 2);
//         cout<<skills<<endl;
//         unordered_map<int, int> visit;
//         vector<pair<int, int>> pairs(n / 2);
//         int count_pair = 0;
//         long long res = 0;
        
//         for(auto i : skill) {
//             long long rem = skills - i;
            
//             if(visit[i] > 0) {
//                 visit[i]--;
//             } else if(visit[rem] > 0) {
//                 pairs[count_pair++] = {i, rem};
//                 visit[rem]--;
//             } else {
//                 visit[i]++;
//             }
//         }
        
//         // Calculate the result from the pairs
//         for(int i = 0; i < n / 2; i++) {
//             cout<<pairs[i].first<<" "<<pairs[i].second<<endl;
//             res += pairs[i].first * pairs[i].second;
//         }
        
//         return res;
//     }
// };

