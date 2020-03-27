//
// Created by claudealves on 12.03.20.
//

#ifndef POO2LABO2_2020__STRING_H
#define POO2LABO2_2020__STRING_H


#include <cstdlib>
#include <string>

class _string {
public :
    _string();

    _string(const _string &other);

    _string(const char *const &other);

    _string(const std::string &other);

    size_t size() const;

    char &at(size_t i) const ;

    char &operator[](size_t i);

    bool operator==(const _string &other) const;

    bool operator==(const char *const &other) const;

    bool operator==(const std::string &other) const;

    bool equal(const _string &other) const;

    bool equal(const char *const &other) const;

    bool equal(const std::string &other) const;

    _string &operator=(const _string &other);

    _string &operator=(const char *const &other);

    _string &operator=(const std::string &other);

    void set(const _string &other);

    void set(const char *const &other);

    void set(const std::string &other);

    _string &append(const _string &other);

    _string &append(const char *const &other);

    _string &append(const std::string &other);

    _string &operator+=(const _string &other);

    _string &operator+=(const char *const &other);

    _string &operator+=(const std::string &other);

    _string &subString(int begin, int end) const;

    friend std::ostream &operator<<(std::ostream &out, const _string &_string);

private :
    char *content;
    size_t length;

};


#endif //POO2LABO2_2020__STRING_H
