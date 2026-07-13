class Solution {
public:
    int digits(int n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    int firstSequential(int len) {
        int num = 0;
        for (int i = 1; i <= len; i++)
            num = num * 10 + i;
        return num;
    }

    int ones(int len) {
        int num = 0;
        while (len--)
            num = num * 10 + 1;
        return num;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int l = digits(low);
        int r = digits(high);

        for (int len = l; len <= r; len++) {
            int num = firstSequential(len);
            int add = ones(len);

            while (true) {
                if (num >= low && num <= high)
                    ans.push_back(num);
                if(num>high) break; 
                if (num % 10 == 9)
                    break;

                num += add;
            }
        }

        return ans;
    }
};
