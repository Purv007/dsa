class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change_5=0;
        int change_10=0;
        int change_20=0;
        for(auto i:bills){
            if(i==5){
                change_5++;
            }
            else if(i==10){
                if(change_5<1){
                    return false;
                }
                change_10++;
                change_5--;
            }
            else if(i==20){
                if(change_10>0){
                    if(change_5<1 || change_10<1){
                        return false;
                    }
                    change_20++;
                    change_10--;
                    change_5--;
                }
                else{
                    if(change_5<3) return false;
                    change_20++;
                    change_5-=3;
                }
            }
        }
        return true;
    }
};
