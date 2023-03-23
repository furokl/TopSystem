#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "Point2D.h"

class Vector2D
{
private:
    float m_x, m_y;

public:
    explicit Vector2D(float x = 0, float y = 0)
        : m_x(x), m_y(y)
    {
    }
    ~Vector2D()
    {
    }

    friend Point2D& Point2D::moveByVector(const Vector2D &v);
    float get_x() const { return m_x; }
    float get_y() const { return m_y; }
    void set_x(float x) { m_x = x; }
    void set_y(float y) { m_y = y; }

    Vector2D operator- () const;
    Vector2D operator+ () const;
    friend Vector2D operator- (const Vector2D &left, const Vector2D &right);
    friend Vector2D operator+ (const Vector2D &left, const Vector2D &right);
    friend Vector2D operator* (const Vector2D &left, const Vector2D &right);
    friend Vector2D operator* (const Vector2D &left, float right);
    friend Vector2D operator* (const float left, const Vector2D &right);
    friend Vector2D operator/ (const Vector2D &left, const Vector2D &right);
    friend Vector2D operator/ (const Vector2D &left, const float right);
    friend Vector2D operator/ (const float left, const Vector2D &right);
    friend bool operator== (const Vector2D &left, const Vector2D &right);
    friend bool operator== (const Vector2D &left, const float right);
    friend bool operator== (const float left, const Vector2D &right);
    friend bool operator!= (const Vector2D &left, const Vector2D &right);
    friend bool operator!= (const Vector2D &left, const float right);
    friend bool operator!= (const float left, const Vector2D &right);
    Vector2D &operator+=(Vector2D right);
    Vector2D &operator-=(Vector2D right);
    Vector2D &operator*=(Vector2D right);
    Vector2D &operator/=(Vector2D right);
};

#endif // !VECTOR2D_H