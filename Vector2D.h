#ifndef VECTOR2D_VECTOR2D_H
#define VECTOR2D_VECTOR2D_H

#define _USE_MATH_DEFINES

#include <cmath>

template <typename T>
class Vector2D
{
private:
    T _posX;
    T _posY;
    T _size;
    T _angle;

public:
    Vector2D(T value1, T value2, bool _isPos);
    Vector2D(const Vector2D&);
    ~Vector2D();

    T get_posX() const;

    void set_posX(T _posX);

    T get_posY() const;

    void set_posY(T _posY);

    T get_size() const;

    void set_size(T _size);

    T get_angle() const;

    void set_angle(T _angle);

    Vector2D& operator=(const Vector2D& other);
    Vector2D& operator+(const Vector2D& other);
    Vector2D& operator*(const T& other);
    Vector2D& operator*(const Vector2D& other);

    T Norm();
    T Angle();

    void Normalize();

    bool IsParallel(const Vector2D& other);
    bool IsOpposed(const Vector2D& other);
    bool IsPerpendicular(const Vector2D& other);
    bool IsNull();
    bool IsNormalized(const Vector2D& other);
};

template <typename T>
Vector2D<T>::Vector2D(T value1, T value2, bool _isPos) {
    if(_isPos)
    {
        this->_posX = value1;
        this->_posY = value2;

        this->_size = sqrt(pow(_posX, 2) + pow(_posY, 2));
        this->_angle = atan(this->_posY / this->_posX);
    }
    else
        this->_size = value1;
        this->_angle = value2;

        this->_angle = this->_angle * M_PI / 180;

        this->_posX = _size * cos(_angle);
        this->_posY = _size * sin(_angle);
}

template <typename T>
Vector2D<T>::Vector2D(const Vector2D &) {

}

template <typename T>
Vector2D<T>::~Vector2D() {

}

template <typename T>
T Vector2D<T>::get_posX() const {
    return _posX;
}

template <typename T>
void Vector2D<T>::set_posX(T _posX) {
    this->_posX = _posX;
}

template <typename T>
T Vector2D<T>::get_posY() const {
    return _posY;
}

template <typename T>
void Vector2D<T>::set_posY(T _posY) {
    this->_posY = _posY;
}

template <typename T>
T Vector2D<T>::get_size() const {
    return _size;
}

template <typename T>
void Vector2D<T>::set_size(T _size) {
    this->_size = _size;
}

template <typename T>
T Vector2D<T>::get_angle() const {
    return _angle;
}

template <typename T>
void Vector2D<T>::set_angle(T _angle) {
    this->_angle = _angle;
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator=(const Vector2D &other) {
    this->_posX = other._posX;
    this->_posY = other._posY;

    return *this;
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator+(const Vector2D &other) {

    Vector2D v(other.get_posX() + this->_posX, other.get_posY() + this->_posY, true);

    return v;
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator*(const T &other) {
    this->_posX = other * this->_posX;
    this->_posY = other * this->_posY;

    return *this;
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator*(const Vector2D &other) {

    this->_posX * other.get_posX() + this->_posY * other.get_posY();

    return *this;
}

template <typename T>
T Vector2D<T>::Norm() {
    T size = sqrt(pow(this->_posX, 2) + pow(this->_posY, 2));

    return size;
}

template <typename T>
T Vector2D<T>::Angle() {
    T angle = this->_angle * M_PI / 180;

    this->_posX = this->_size * cos(angle);
    this->_posY = this->_size * sin(angle);

    return angle;
}

template <typename T>
void Vector2D<T>::Normalize() {
    this->_posX = this->_posX / this->_size;
    this->_posY = this->_posY / this->_size;
}

template <typename T>
bool Vector2D<T>::IsParallel(const Vector2D &other) {
    bool o = false;
    if(this->_posX == other.get_posX() && this->_posY == other.get_posY())
        o = true;
    return o;
}

template <typename T>
bool Vector2D<T>::IsOpposed(const Vector2D &other) {
    if((this->_posX * other.get_posX() + this->_posY * other.get_posY()) / (this->_size * other.get_size()) == -1)
        return true;
}

template <typename T>
bool Vector2D<T>::IsPerpendicular(const Vector2D &other) {
    if(this->_posX * other.get_posX() + this->_posY * other.get_posY() == 0)
        return true;
}

template <typename T>
bool Vector2D<T>::IsNull() {
    if(this->_posX && this->_posY == 0)
        return true;
}

template <typename T>
bool Vector2D<T>::IsNormalized(const Vector2D &other) {
    if(this->_size == 1)
        return true;
}

#endif //VECTOR2D_VECTOR2D_H