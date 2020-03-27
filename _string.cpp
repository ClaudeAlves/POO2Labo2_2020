//
// Created by claudealves on 12.03.20.
//

#include "_string.h"
#include <cstring>
#include <iostream>


_string::_string() {
    content= nullptr;
    length =0;
}

_string::_string(const _string &other) {
    length = other.size();
    if (length==0)
        content= nullptr;
    else
    {
        content = new char [length+1];
        strcpy(content, other.content);
    }

}

_string::_string(const char *const &other) {
    length = strlen(other);
    if (length==0)
        content= nullptr;
    else{
        content = new char[length+1];
        strcpy(content, other);
    }
}

_string::_string(const std::string &other) {
    length = other.size();
    if (length==0)
        content= nullptr;
    else
    {
        content = new char [length+1];
        for(int i=0; i<length; i++ ){
            content[i] = other[i];
        }
        content[length]='\0';
    }

}

size_t _string::size() const {
    return strlen(content);
}

char &_string::at(size_t position) const {
    if(position >= length)
        throw "illegal position";
    return content[position];

}


char &_string::operator[](size_t i) {
    return at(i);
}

bool _string::operator==(const _string &other) const {
    return equal(other);
}

bool _string::operator==(const char *const &other) const {
    return equal(other);
}

bool _string::operator==(const std::string &other) const {
    return equal(other);
}

bool _string::equal(const _string &other) const {
    return strcmp(content, other.content)==0;
}

bool _string::equal(const char *const &other) const {
    return strcmp(content, other)==0;;
}

bool _string::equal(const std::string &other) const {
    bool result = false;
    if (length!=other.size())
        return result;
    else {
        for (int i = 0; i < other.size(); i++) {
            if (content[i] != other.at(i))
                return result;

        }
        result = true;
    }
    return result;
}

_string &_string::operator=(const _string &other) {
    set(other);
    return *this;
}

_string &_string::operator=(const char *const &other) {
    set(other);
    return *this;
}

_string &_string::operator=(const std::string &other) {
    set(other);
    return *this;
}

void _string::set(const _string &other) {
    if(content!= nullptr)
        delete content;
    length = other.size();
    content = new char[length+1];
    strcpy(content, other.content);
}

void _string::set(const char *const &other) {
    if(content!= nullptr)
        delete content;
    length = strlen(other);
    content = new char[length+1];
    strcpy(content, other);
}

void _string::set(const std::string &other) {
    if(content!= nullptr)
        delete content;
    length = other.size();
    content = new char[length];
    for(int i=0; i<length; i++){
        content[i]=other.at(i);
    }
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
