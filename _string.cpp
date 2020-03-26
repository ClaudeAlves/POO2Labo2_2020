//
// Created by claudealves on 12.03.20.
//

#include "_string.h"

_string::_string() {
    content= nullptr;
    length =0;
}

_string::_string(const _string &other) {
    length = other.length;
    if (length==0)
        content= nullptr;
    else
    {
        content = new char [length];
        for(int i=0; i<length; i++ ){
            content[i] = other.content[i];
        }
    }

}

_string::_string(const char *const &other) {
    length=0;
    while (other[length]!='\0'){
        length++;
    }
    content = new char[length];
    for(int i= 0; i<length; i++){
        content[i]= other[i];
    }

}

_string::_string(const std::string &other) {

}

size_t _string::size() const {
    return length;
}

char &_string::at(size_t position) const {
    if(position >= length)
        throw "illegal position";
    return content[position];

}


char &_string::operator()(size_t i) {
    return <#initializer#>;
}

bool _string::operator==(const _string &other) const {
    bool result = false;
    if (length!=other.length)
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

bool _string::operator==(const char *const &other) const {
    int lengthOther = 0;
    bool result = false;
    while (other[lengthOther]!='\0'){
        lengthOther++;
    }
    if (length!=lengthOther)
        return result;
    else {
        for (int i = 0; i < length; i++) {
            if (content[i] != other[i])
                return result;

        }
        result = true;
    }
    return result;
}

bool _string::operator==(const std::string &other) const {
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
    if(content!= nullptr)
        delete content;
    length = other.size();
    content = new char[length];
    for(int i=0; i<length; i++){
        content[i]=other.at(i);
    }
    return *this;
}

_string &_string::operator=(const char *const &other) {
    int lengthOther = 0;
    while (other[lengthOther]!='\0'){
        lengthOther++;
    }
    if(content!= nullptr)
        delete content;
    length = lengthOther;
    content = new char[length];
    for(int i=0; i<length; i++){
        content[i]=other[i];
    }
    return *this;
}

_string &_string::operator=(const std::string &other) {
    if(content!= nullptr)
        delete content;
    length = other.size();
    content = new char[length];
    for(int i=0; i<length; i++){
        content[i]=other.at(i);
    }
    return *this;
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
