class Solution {
public:
    double Pow(double x, long long n){
        if(n == 1) return x;
        double part = Pow(x,n/2);
        if(n%2 == 0){
            return part*part;
        }
        return part*Pow(x,n/2+1);
    }

    double myPow(double x, int n) {
        long long newN = n;
        if(newN == 0 || x == 1) return 1;
        if(newN < 0) {
            isNegative = true;
            newN *= (-1);
        }
        double ans;
        if(isNegative) ans = 1/Pow(x,newN);
        else ans = Pow(x,newN);
        return ans;
    }
private:
    bool isNegative = false;
};