#ifndef BASIC_H_INCLUDED
#define BASIC_H_INCLUDED

template<typename T>

class Basic {
    public:

    static T abs(const T &n);
    static T gcd(T a, T b);
    static T max(const T &a, const T &b);
    static T min(const T &a, const T &b);
};

#endif // BASIC_H_INCLUDED

/* ---------- TEMPLATES ---------- */

template<typename T>
T Basic<T>::abs(const T &n) {
    return(n > 0 ? n : n * (T)(-1));
}

template<typename T>
T Basic<T>::gcd(T a, T b) {
    return(b ? gcd(b, a % b) : a);
}

template<typename T>
T Basic<T>::max(const T &a, const T &b) {
    return(a > b ? a : b);
}

template<typename T>
T Basic<T>::min(const T &a, const T &b) {
    return(a > b ? b : a);
}
