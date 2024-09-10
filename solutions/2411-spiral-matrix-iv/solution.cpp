/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        int x=0,y=1,dir=0;
        int i=0,j=0;
        vector<vector<int>> choice={{0,1},{1,0},{0,-1},{-1,0}};
        while(head!=NULL){
            res[i][j]=head->val;
            head=head->next;
            i+=x;
            j+=y;
            if(i>m-1 || i<0 || j<0 || j>n-1 || res[i][j]!=-1){
                dir=(dir+1)%4;
                i-=x;
                j-=y;
                x=choice[dir][0];
                y=choice[dir][1];
                i+=x;
                j+=y;
            }
        }
        return res;
    }
};
