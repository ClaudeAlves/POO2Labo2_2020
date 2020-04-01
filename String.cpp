/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 - classe String
 Fichier     : String.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 01.04.2020

 But         : Implémentation d'une classe String de notre crue

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "String.h"
#include <cstring>
#include <iostream>
#include <sstream>


String::String() {
    initialize("");
}

String::String(const String &other) {
    initialize(other.content);
}

String::String(const char *const &other) {
    initialize(other);
}

size_t String::size() const {
    return strlen(content);
}

char &String::at(size_t position) const {
    if (position >= size()) {
        throw std::out_of_range("illegal position");
    }
    return content[position];

}

char &String::operator[](size_t i) const {
    return at(i);
}

bool String::operator==(const String &other) const {
    return equal(other);
}

bool String::operator==(const char *const &other) const {
    return equal(other);
}

bool String::equal(const String &other) const {
    return equal(other.content);
}

bool String::equal(const char *const &other) const {
    return !strcmp(content, other);
}

String &String::operator=(const String &other) {
    return set(other);
}

String &String::operator=(const char *const &other) {
    return set(other);
}

String &String::set(const String &other) {
    return set(other.content);
}

String &String::set(const char *const &other) {
    if (!equal(other)) {
        erase();
        initialize(other);
    }
    return *this;
}

String &String::append(const String &other) {
    return append(other.content);
}

String &String::append(const char *const &other) {
    char *temp = new char[size() + strlen(other) + 1];

    strcpy(temp, content);
    strcat(temp, other);
    erase();
    initialize(temp);

    delete[] temp;

    return *this;
}

String &String::operator+=(const String &other) {
    return append(other);
}

String &String::operator+=(const char *const &other) {
    return append(other);
}

String String::subString(size_t begin, size_t end) const {
    if (begin > end) {
        throw std::invalid_argument("begin > end");
    }
    if (begin >= size() || end >= size()) {
        throw std::out_of_range(&"out of the String range which length is "[size()]);
    }
    size_t tempSize = end - begin + 1;
    char *substr = new char[tempSize];

    strncpy(substr, &content[begin], tempSize);
    substr[tempSize] = '\0';
    String toReturn(substr);

    delete[] substr;
    return toReturn;
}

std::ostream &operator<<(std::ostream &out, const String &rhs) {
    return out << rhs.content;
}

void String::initialize(const char *newContent) {
    if (newContent) {
        content = new char[strlen(newContent) + 1];
        strcpy(content, newContent);
    } else {
        content = new char[0];
    }
}

String::String(char c) {
    char buffer[2];
    buffer[0] = c;
    buffer[1] = '\0';
    initialize(buffer);
}

String::String(bool b) {
    if (b) {
        initialize("true");
    } else {
        initialize("false");
    }
}

String::String(int i) {
    numberToString(i);
}

String::String(double d) {
    numberToString(d);
}

String operator+(String lhs, const String &rhs) {
    lhs += rhs;
    return lhs;
}

String operator+(String lhs, const char *rhs) {
    lhs += rhs;
    return lhs;
}

String operator+(const char *lhs, const String &rhs) {
    String temp(lhs);
    temp += rhs;
    return temp;
}

std::istream &operator>>(std::istream &in, String &rhs) {
    rhs.erase();
    rhs.content = new char[String::READING_MAX];
    in.getline(rhs.content, String::READING_MAX);
    return in;
}

String::~String() {
    erase();
}

void String::erase() {
    delete[] content;
}

const char *String::getCString() const {
    return content;
}

void String::numberToString(double number) {
    std::ostringstream stream;
    stream << number;
    initialize(stream.str().c_str());
}
