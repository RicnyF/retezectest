//
// Created by Standard on 18.03.2024.
//

#ifndef RETEZEC_RETEZEC_H
#define RETEZEC_RETEZEC_H


class retezec {
public:
    retezec();

    retezec(const char *);

    retezec(const retezec &);

    ~retezec();

    char operator[](unsigned int) const;

    char &operator[](unsigned int);

    void vypis();

    unsigned int getLength() const;

    void setRetezec(const char *);

    retezec &operator=(const retezec &);

    retezec &operator+=(const retezec &);

    retezec &operator+(const retezec &);

private:
    char *text;
    unsigned int size;

    void kopirujPole(const retezec &);

};


#endif //RETEZEC_RETEZEC_H
