#pragma once

#include <vector>
#include <initializer_list>
#include <iostream>

template <class T, std::size_t N = 2>
class Vec
{
private:
    std::vector<T> v;
    std::size_t size;

public:
    Vec()
    {
        v = std::vector<T>(N);
        size = N;
    }

    Vec(std::initializer_list<T> args)
    {
        v = std::vector<T>(N);
        size = N;
        for (std::size_t i = 0; i < N; i++)
        {
            v[i] = *(args.begin() + i);
        }
    }

    Vec(const Vec &other) : v(other.v), size(other.size) {}

    Vec(Vec &&other) : v(std::other.v), size(other.size) {}

    Vec &operator=(const Vec &other)
    {
        if (this == &other)
            return *this;
        v = std::vector<T>(other.v);
        size = v.size();
        return *this;
    }

    Vec &operator=(Vec &&other) noexcept
    {
        if (this == &other)
            return *this;
        v = std::move(other.v);
        size = v.size();
        return *this;
    }

    Vec operator+=(const Vec &other)
    {
        if (other.size != size)
        {
            throw std::runtime_error("Unmatched length");
        }
        for (int i = 0; i < size; ++i)
        {
            v[i] += other.v[i];
        }
        return *this;
    }

    Vec operator-()
    {
        Vec ret(*this);
        for (T &i : ret)
        {
            i = -i;
        }
        return ret;
    }

    Vec operator-=(const Vec &other)
    {
        return operator+=(-other);
    }

    Vec operator==(const Vec &other)
    {
        if (size != other.size)
            return false;
        for (size_t i = 0; i < size; i++)
        {
            if (v[i] != other.v[i])
            {
                return false;
            }
        }
        return true;
    }

    friend Vec operator-(Vec &l, const Vec &r)
    {
        l -= r;
        return
    }

    friend Vec operator+(Vec &l, const Vec &other)
    {
        l += other;
        return l;
    }

    friend std::ostream &operator<<(std::ostream &os, const Vec &obj)
    {
        os << "Vec(";
        for (T i : obj.v)
        {
            os << i << ", ";
        }
        os << ")";
        return os;
    }
};
