#pragma once


template<class T>
class Singleton {
protected:
    Singleton() {}// Disallow instantiation outside of the class.
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static T& Get() {
        static T ins;
        return ins;
    }
};
