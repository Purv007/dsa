class NumberContainers {
public:
    unordered_map<int,int>idxToNo;
    unordered_map<int,set<int>>posi;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idxToNo.find(index)!=idxToNo.end()){
            int temp=idxToNo[index];
            posi[temp].erase(index);
            if(posi[temp].empty()){
                posi.erase(temp);
            }
        }
        idxToNo[index]=number;
        posi[number].insert(index);
    }
    
    int find(int number) {
        if(posi.find(number)!=posi.end())
            return *posi[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
