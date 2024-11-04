class Solution {
public:
    string compressedString(string word) {
        string res="";
        char c=word[0];
        int count=1;
        for(long long i=1;i<word.size();i++){
            if(count==9){
                res+=to_string(count)+c;
                c=word[i];
                count=0;
            }
            if(word[i]==c){
                count++;
            }else{
                res+=to_string(count)+c;
                c=word[i];
                count=1;
            }
        }
        res+=to_string(count)+c;
        return res;
    }
};
// class Solution {
// public:
//     string compressedString(string word) {
//         string comp = "";

//         // pos tracks our position in the input string
//         int pos = 0;

//         // Process until we reach end of string
//         while (pos < word.length()) {
//             int consecutiveCount = 0;

//             char currentChar = word[pos];

//             // Count consecutive occurrences (maximum 9)
//             while (pos < word.length() && consecutiveCount < 9 &&
//                    word[pos] == currentChar) {
//                 consecutiveCount++;
//                 pos++;
//             }

//             // Append count followed by character to result
//             comp += to_string(consecutiveCount) + currentChar;
//         }

//         return comp;
//     }
// };
