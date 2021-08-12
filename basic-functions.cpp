#include "basic-functions.h"

int Basic::abs(const int &n) {
    return(n > 0 ? n : n * (-1));
}

int Basic::gcd(int a, int b) {
    return(b ? gcd(b, a % b) : a);
}

int Basic::max(const int &a, const int &b) {
    return(a > b ? a : b);
}

int Basic::min(const int &a, const int &b) {
    return(a > b ? b : a);
}
