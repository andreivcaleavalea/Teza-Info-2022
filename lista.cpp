#include "lista.h"

istream  &operator>>(istream &is, lista &l) {
    int x;
    for(int i=1; i<=l.lg; ++i) {
        is>>x;
        l.AdaugaFinal(l.pr, x);
    }
    return is;
}

ostream  &operator<<(ostream &os, lista &l) {
    nod *t = l.pr;
    while (t != NULL) {
        os<<t->value << ' ';
        t=t->next;
    }
    return os;
}

void lista::AdaugaFinal(nod *&p, int x) {
    nod *q  =new nod;
    q->value = x;
    q->next = NULL;
    if(p == NULL) {
        p = q;
    } else  {
        nod *t = p;
        while (t->next != NULL)
            t=t->next;
        t->next = q;
    }
}
lista::lista(int n) {
    pr = NULL;
    ul = NULL;
    lg = n;
}
void lista::AdaugaInceput(nod *&p, int x) {
    nod *t = new nod;
    t->value = x;
    t->next = p;
    p = t;
}

lista operator+=(lista &ls1, lista &ls2) {
    nod *a, *b;
    lista c;
    a = ls1.pr;
    b = ls2.pr;
    while (a!=NULL) {
        c.AdaugaFinal(c.pr, a->value);
        a=a->next;
    }
    while (b!=NULL) {
        c.AdaugaFinal(c.pr, b->value);
        b=b->next;
    }
    ls1 = c;
}

lista operator+(lista ls1, lista ls2) {
    ls1.ul->next = ls2.pr;
    ls1.lg = ls1.lg + ls2.lg;
    return ls1;
}

lista::lista(lista &ls) {
    lg = ls.lg;
    pr = ls.pr;
    ul = ls.pr;
}

lista::~lista() {
    nod *x = pr;
    while (x != NULL) {
        x = pr->next;
        delete pr;
        pr = x;
    }
    delete x;
    pr = NULL;
}

int lista::SearchFor(int x) {
    int nr=1;
    nod *p, *u;
    p = pr;
    u = ul;
    while (p != NULL) {
        if(p->value == x)
            return nr;
        nr++;
        p = p->next;
    }
}

void lista::DeleteOn(int x) {
    if(pr->value == x) {
        pr = pr->next;
    } else {
        nod *p, *r;
        p = pr;
        r = pr->next;
        while (r->value != x)
        {
            p = p->next;
            r = r->next;
        }
        //delete p->next;
        p->next = r->next;
        lg--;
    }
}




