class Solution {
public:
    void func(vector<char>& c,int& d,int count,int l){
        while(count!=0){
            int a=count%10;
            count/=10;
            c[d+l]=a+'0';
            l--;
        }
    }
    int compress(vector<char>& chars) {
        int res=0;
        char c=chars[0];
        int count=0;
        for(auto i:chars){
            if(i==c){
                count++;
            }
            else{
                chars[res++]=c;
                if(count>1){
                    string s=to_string(count);
                    for(auto a:s){
                        chars[res++]=a;
                    }
                }
                c=i;
                count=1;
            }
        }
        chars[res++]=c;
        if(count>1){
            string s=to_string(count);
            for(auto a:s){
                chars[res++]=a;
            }
        }

        return res;
    }
};
