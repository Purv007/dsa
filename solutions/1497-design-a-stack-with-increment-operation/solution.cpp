class CustomStack {
public:
int top,n;
vector<int>stack;

    CustomStack(int maxSize) {
        n=maxSize;
        stack=vector<int>(n);
        top=-1;
    }
    
    void push(int input){
        if (top == n-1){}
            // cout<<"Stack Overflow"<<endl;
        else {
            top++;
            stack[top]=input;
        }
    }
    
    int pop(){
        if (top==-1) {
            return -1;
        }
        else {
            int temp=top;
            top--;
            return stack[temp];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(n,k);i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
