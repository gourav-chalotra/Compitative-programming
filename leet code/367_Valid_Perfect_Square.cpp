// #367. Valid Perfect Squareclass Solution {
public:
    bool isPerfectSquare(int num) {
        double val = sqrt(num);
        if(val == (int)val)
            return true;
        return false;
    }
};