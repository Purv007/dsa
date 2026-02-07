class KthLargest {
    multiset<int> bst;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int x : nums) {
            bst.insert(x);
            if (bst.size() > k)
                bst.erase(bst.begin());
        }
    }

    int add(int val) {
        bst.insert(val);

        if (bst.size() > k)
            bst.erase(bst.begin());

        return *bst.begin();
    }
};

