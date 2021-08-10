int gcd(int a, int b) {
    return(b ? gcd(b, a % b) : a);
}

int max(const int &a, const int &b) {
    return(a > b ? a : b);
}

int min(const int &a, const int &b) {
    return(a > b ? b : a);
}
