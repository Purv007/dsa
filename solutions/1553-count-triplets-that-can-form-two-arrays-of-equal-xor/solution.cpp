class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int a=0;
                for(int k=i;k<j;k++){
                    a^=arr[k];
                }
                int b=0;
                for(int k=j;k<arr.size();k++){
                    b^=arr[k];
                if(a==b){
                    count++;  
                }      
                }
            }
        }
        return count;
    }
};
// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         int res = 0;
//         for (int start = 0; start < arr.size() - 1; start++) {
//             int xor_first_arr = 0; // from start XOR for every subarray is 0
//             for (int second_start = start + 1; second_start < arr.size(); second_start++) {
//                 xor_first_arr ^= arr[second_start - 1]; // count last character to previous XOR
//                 int xor_second_arr = 0; // from start XOR for every subarray is 0
//                 for (int end = second_start; end < arr.size(); end++) {
//                     xor_second_arr ^= arr[end]; // count character before end to previous XOR
//                     if (xor_first_arr == xor_second_arr) { // if XORes are equal
//                         res++;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };
