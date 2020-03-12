//
// Created by claudealves on 12.03.20.
//

#include "_string.h"

_string::_string() {

}

_string::_string(const _string &other) {

}

_string::_string(const char *const &other) {

}

_string::_string(const std::string &other) {

}

size_t _string::size() const {
    return 0;
}

char &_string::at(size_t i) {
    return <#initializer#>;
}

char &_string::operator()(size_t i) {
    return <#initializer#>;
}

bool _string::operator==(const _string &other) const {
    return false;
}

bool _string::operator==(const char *const &other) const {
    return false;
}

bool _string::operator==(const std::string &other) const {
    return false;
}

bool _string::equal(const _string &other) const {
    return false;
}

bool _string::equal(const char *const &other) const {
    return false;
}

bool _string::equal(const std::string &other) const {
    return false;
}

_string &_string::operator=(const _string &other) {
    return <#initializer#>;
}

_string &_string::operator=(const char *const &other) {
    return <#initializer#>;
}

_string &_string::operator=(const std::string &other) {
    return <#initializer#>;
}

_string &_string::set(const _string &other) {
    return <#initializer#>;
}

_string &_string::set(const char *const &other) {
    return <#initializer#>;
}

_string &_string::set(const std::string &other) {
    return <#initializer#>;
}

_string &_string::append(const _string &other) {
    return <#initializer#>;
}

_string &_string::append(const char *const &other) {
    return <#initializer#>;
}

_string &_string::append(const std::string &other) {
    return <#initializer#>;
}

_string &_string::operator+=(const _string &other) {
    return <#initializer#>;
}

_string &_string::operator+=(const char *const &other) {
    return <#initializer#>;
}

_string &_string::operator+=(const std::string &other) {
    return <#initializer#>;
}

_string &_string::subString(int begin, int end) const {
    return <#initializer#>;
}

std::ostream &operator<<(std::ostream &out, const _string &_string) {
    return <#initializer#>;
}
