#ifndef TEZA2_LISTA_H
#define TEZA2_LISTA_H
#include <iostream>
using namespace std;
struct nod{
    int value;
    nod* next;
};
class lista {
public:
    nod *pr, *ul;
    int lg;

    lista(int n=0);
    lista(lista &ls);
    ~lista();

    int SearchFor(int x);
    void DeleteOn(int x);
    bool empty() {
        return pr == NULL;
    }
    void AdaugaFinal(nod *&p, int x);
    void AdaugaInceput(nod *&p, int x);


    friend istream& operator>>(istream &is, lista &l);
    friend ostream& operator<<(ostream &os, lista &l);

    friend lista operator+=(lista &ls1, lista &ls2);
    friend lista operator+(lista ls1, lista ls2);
};


#endif //TEZA2_LISTA_H
