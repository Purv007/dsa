class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());

        double a=sides[0];
        double b=sides[1];
        double c=sides[2];

        if(a+b<=c) return {};

        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));
        A= (180*A)/M_PI;
        B= (180*B)/M_PI;
        C= (180*C)/M_PI;
        vector<double>res={A,B,C};
        sort(res.begin(),res.end());
        return res;
    }
};
