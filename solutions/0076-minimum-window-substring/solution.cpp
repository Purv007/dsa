class Solution {
public:
bool check(vector<int>&a,vector<int>&b){
    for(int i=0;i<128;i++){
        if(a[i]<b[i]) return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        vector<int> a(128, 0), b(128, 0);

        if(m > n) return "";

        // string res="";
        int start=-1,len=INT_MAX;

        for (char c : t) b[c ]++;
        for(int i=0;i<m;i++) a[s[i]]++;

        int r=m-1;

        for(int l=0;l<n;l++){
            while(r<n-1 && !check(a,b)){
                r++;
                a[s[r]]++;
            }
            if(!check(a,b)) break;
            if(r-l+1 < len){
                start=l;
                len=r-l+1;
            }
            a[s[l]]--;

        }
        
        if (start == -1) return "";
        return s.substr(start, len);
    }
};
