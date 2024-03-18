//
// Created by Standard on 18.03.2024.
//

#include "retezec.h"
#include <iostream>

retezec::retezec() {
    this->text = new char[1];
    this->text[0] = '\0';
    this->size = 0;
}

retezec::retezec(const char *input) {
    this->size = 0;
    while (input[size] != '\0') {
        this->size++;
    }
    this->text = new char[this->size + 1];
    for (int i = 0; i < this->size; i++) {
        this->text[i] = input[i];
    }
    this->text[this->size] = '\0';

}

retezec::retezec(const retezec &puvodni) {
    this->size = puvodni.size;
    this->text = new char[size + 1];
    for (int i = 0; i < this->size; ++i) {
        this->text[i] = puvodni[i];
    }
    text[size] = '\0';
}


char retezec::operator[](unsigned int index) const {
    if (index >= 0 && index < this->size) {
        return this->text[index];
    }
    throw "Index out of bound";
}

char &retezec::operator[](unsigned int index) {
    if (index >= 0 && index < this->size) {
        return this->text[index];
    }
    throw "Index out of bound";
}

void retezec::vypis() {
    std::cout << text << std::endl;
}

retezec::~retezec() {
    delete[]this->text;
    this->size = 0;
}

unsigned int retezec::getLength() const {
    return this->size;
}

retezec &retezec::operator=(const retezec &input) {
    if (this != &input) {
        delete[] this->text;
        kopirujPole(input);

    }
    return *this;
}

void retezec::kopirujPole(const retezec &input) {
    try {
        this->size = input.size;

        this->text = new char[this->size + 1];

        for (int i = 0; i < this->size; ++i) {
            this->text[i] = input.text[i];
        }
        this->text[this->size] = '\0';
    }
    catch (std::bad_alloc &ba) {
        std::cout << "bad_alloc caught: " << ba.what() << '\n';
    }
}


retezec &retezec::operator+=(const retezec &input) {
    try {
        char *pom = new char[this->size + input.getLength() + 1];
        for (int i = 0; i < this->size; ++i) {
            pom[i] = this->text[i];
        }
        for (int i = this->size; i < this->size + input.getLength(); i++) {
            pom[i] = input[i - this->size];
        }
        delete[]this->text;
        this->text = pom;
        this->text[this->size] = '\0';
        delete[]pom;
    }
    catch (std::bad_alloc &ba) {
        std::cout << "bad_alloc caught: " << ba.what() << '\n';
    }
    return *this;
}

void retezec::setRetezec(const char *input) {
    delete[]this->text;
    this->size = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        this->size++;
    }
    this->text = new char[this->size + 1];
    for (int i = 0; i < this->size; ++i) {
        this->text[i] = input[i];
    }
    this->text[this->size] = '\0';

}

retezec &retezec::operator+(const retezec &p) {
    retezec tmp(*this);
    tmp += p;
    return tmp;
}
