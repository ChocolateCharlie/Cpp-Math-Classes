int abs(int n) {
    return(n > 0 ? n : n * (-1));
}

int gcd(int a, int b) {
    return(b ? gcd(b, a % b) : a);
}

int max(const int &a, const int &b) {
    return(a > b ? a : b);
}

int min(const int &a, const int &b) {
    return(a > b ? b : a);
}
