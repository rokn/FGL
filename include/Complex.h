//
// Created by rokner on 2/17/18.
//

#ifndef FGL_COMPLEX_H
#define FGL_COMPLEX_H


template <class T>
class Complex {
public:
    Complex(T real, T imaginary);
    Complex<T> squared() const;
    Complex<T> operator+(Complex<T> rhs) const;
    Complex<T> operator-(Complex<T> rhs) const;
    Complex<T> operator*(Complex<T> rhs) const;
    Complex<T> operator*(T scalar) const;

    T re() const;
    T im() const;

private:
    T _re;
    T _im;
};

template<class T>
Complex<T>::Complex(T real, T imaginary)
:_re(real), _im(imaginary) { }

template<class T>
Complex<T> Complex<T>::squared() const {
    return *this * *this;
}

template<class T>
Complex<T> Complex<T>::operator+(Complex<T> rhs) const {
    T newRe = _re + rhs._re;
    T newIm = _im + rhs._im;
    return Complex<T>(newRe, newIm);
}

template<class T>
Complex<T> Complex<T>::operator-(Complex<T> rhs) const {
    return *this + (rhs*(-1));
}

template<class T>
Complex<T> Complex<T>::operator*(Complex<T> rhs) const {
    T newRe = _re*rhs._re - _im*rhs._im;
    T newIm = _im*rhs._re + _re*rhs._im;
    return Complex<T>(newRe, newIm);
}

template<class T>
Complex<T> Complex<T>::operator*(T scalar) const {
    T newRe = _re * scalar;
    T newIm = _im * scalar;
    return Complex<T>(newRe, newIm);
}

template<class T>
T Complex<T>::re() const {
    return _re;
}

template<class T>
T Complex<T>::im() const {
    return _im;
}


#endif //FGL_COMPLEX_H
