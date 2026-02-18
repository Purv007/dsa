class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find('*');

        string left = p.substr(0, star);
        string right = p.substr(star + 1);

        int pos = s.find(left);
        if (pos == string::npos) return false;

        pos += left.size();

        return s.find(right, pos) != string::npos;
    }
};
