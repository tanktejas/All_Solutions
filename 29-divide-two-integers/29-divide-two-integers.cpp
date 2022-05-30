class Solution {
public:
public:
    int divide(int d, int di) {
          if (d == -2147483648 && di == -1 ){
        return 2147483647;
    }
    return d / di;
    } 
};