#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int length;

public:
    String(const char* s = "") {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;
        delete[] str;

        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
        return *this;
    }

    String operator+(const String& other) const {
        int newLength = length + other.length;
        char* newStr = new char[newLength + 1];

        std::strcpy(newStr, str);
        std::strcat(newStr, other.str);

        String result(newStr);
        delete[] newStr;
        return result;
    }

    ~String() {
        delete[] str;
    }

    void print() const {
        std::cout << str << std::endl;
    }
};
