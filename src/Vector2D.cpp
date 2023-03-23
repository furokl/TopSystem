#include "Vector2D.h"

Vector2D Vector2D::operator-() const {
    return Vector2D(-m_x, -m_y);
}
Vector2D Vector2D::operator+() const {
    return *this;
}
Vector2D operator- (const Vector2D &left, const Vector2D &right) {
    return Vector2D(left.m_x - right.m_x, left.m_y - right.m_y);
}
Vector2D operator+ (const Vector2D &left, const Vector2D &right) {
    return Vector2D(left.m_x + right.m_x, left.m_y + right.m_y);
}
Vector2D operator* (const Vector2D &left, const Vector2D &right) {
    return Vector2D(left.m_x * right.m_x, left.m_y * right.m_y);
}
Vector2D operator* (const Vector2D &left, float right) {
    return Vector2D(Vector2D(right, right) * left);
}
Vector2D operator* (float left, const Vector2D &right) {
    return Vector2D(right * left);
}
Vector2D operator/ (const Vector2D &left, const Vector2D &right) {
    return Vector2D(left.m_x / right.m_x, left.m_y / right.m_y);
}
Vector2D operator/ (const Vector2D &left, float right) {
    return Vector2D(Vector2D(right, right) / left);
}
Vector2D operator/ (float left, const Vector2D &right) {
    return Vector2D(right / left);
}
bool operator== (const Vector2D &left, const Vector2D &right) {
	return (left.m_x == right.m_x && left.m_y == right.m_y);
}
bool operator== (const Vector2D &left, const float right) {
	return (left.m_x == right && left.m_y == right);
}
bool operator== (const float left, const Vector2D &right) {
	return (right == left);
}
bool operator!= (const Vector2D &left, const Vector2D &right) {
	return (!(left == right));
}
bool operator!= (const Vector2D &left, const float right) {
	return (!(left == right));
}
bool operator!= (const float left, const Vector2D &right) {
	return (right != left);
}
Vector2D &Vector2D::operator+=(Vector2D right)
{
    m_x += right.m_x;
    m_y += right.m_y;
    return *this;
}
Vector2D &Vector2D::operator-=(Vector2D right)
{
    m_x -= right.m_x;
    m_y -= right.m_y;
    return *this;
}
Vector2D &Vector2D::operator*=(Vector2D right)
{
    m_x *= right.m_x;
    m_y *= right.m_y;
    return *this;
}
Vector2D &Vector2D::operator/=(Vector2D right)
{
    m_x /= right.m_x;
    m_y /= right.m_y;
    return *this;
}