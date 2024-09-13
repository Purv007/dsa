class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>res(queries.size(),0);
        int count=0;
        for(auto i:queries){
            int xor_value=0;
            for(int k=i[0];k<=i[1];k++){
                xor_value^=arr[k];
            }
            res[count]=xor_value;
            count++;
        }
        return res;
    }
};
