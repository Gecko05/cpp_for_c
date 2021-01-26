int gcd(int m, int n){
    static int fcn_calls = 1;
    fcn_calls++;
    if (m % n == 0){
        return n;
    }
    else{
        return gcd(n, m % n);
    }
}