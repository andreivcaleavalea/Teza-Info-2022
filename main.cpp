#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "lista.h";
using namespace std;
ifstream fin("data.in");
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
lista a, b;

void AfisareListe() {
    //SetConsoleTextAttribute(hConsole, 1);
    //system("Color 08");
    system("CLS");
    SetConsoleTextAttribute(hConsole, 144);
    cout << "---------------------------------------------------------------------------\n";
    if(a.empty())
        cout << "||   A: nu exista in memorie                                             ||\n";
    else {
        cout << "||   A: " << a;
        for(int i=1; i<66-2*a.lg; ++i)
            cout << " ";
        cout << "||\n";
    }
    if(b.empty())
        cout << "||   B: nu exista in memorie                                             ||\n";
    else {
        cout << "||   B: " << b;
        for(int i=1; i<66-2*b.lg; ++i)
            cout << " ";
        cout << "||\n";
    }
    cout << "---------------------------------------------------------------------------\n";
    SetConsoleTextAttribute(hConsole, 7);
    //system("Color 07");
    //SetConsoleTextAttribute(hConsole, 0);
}
void About()
{
    SetConsoleTextAttribute(hConsole, 144);
    cout << "\n---------------------------------------------------------------------------\n";
    cout << "||                                                                       ||\n";
    cout << "||                 Proiect Realizat de Andrei Caleavalea                 ||\n";
    cout << "||                                                                       ||\n";
    cout << "---------------------------------------------------------------------------";
    SetConsoleTextAttribute(hConsole, 07);
    cout << '\n';

}
void Menu() {
    SetConsoleTextAttribute(hConsole, 245);
    cout << "\n---------------------------------------------------------------------------\n";
    cout << "||  Alegeti o optiune:                                                   ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    1. Creati o lista                                                  ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    2. Concatenati cele 2 liste                                        ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    3. Adaugare la finalul listei                                      ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    4. Adaugare la inceputul listei                                    ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    5. Stergere element din lista                                      ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    6. Verificare daca o lista este vida                               ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    7. Cautare element                                                 ||\n";
    cout << "||                                                                       ||\n";
    cout << "||    8. Iesire din program                                              ||\n";
    cout << "---------------------------------------------------------------------------\n";
    About();
}

void CreareLista() {
    char c;int n;
    system("CLS");
    AfisareListe();
    cout << "\n\nLista A sau B? (0 - pentru a reveni la meniu)\n";
    cin >> c;
    if(c == 'A') {
        cout << "Doriti sa cititi de la tastatura(1) sau din fisier (2)\n";
        cin >> n;
        if(n == 1) {
            cout << "Cate elemente are lista?\n";
            cin >> n;
            a.lg = n;
            cin >> a;
        } else {
            cout << "Cate elemente are lista?\n";
            fin >> n;
            a.lg = n;
            fin >> a;
        }

    }else if(c == 'B') {
        cout << "Doriti sa cititi de la tastatura(1) sau din fisier (2)\n";
        cin >> n;
        if (n == 1) {
            cout << "Cate elemente are lista?\n";
            cin >> n;
            b.lg = n;
            cin >> b;
        } else {
            cout << "Cate elemente are lista?\n";
            fin >> n;
            b.lg = n;
            fin >> b;
        }
    } else if(c != '0'){
        cout << "Nu ati introdus o lista valida, apasati orice tasta pentru a reveni\n";
        getch();
        CreareLista();
    }
}

void AdunareListe() {
    system("CLS");
    AfisareListe();
    if(a.empty() || b.empty()) {
        if(a.empty() && b.empty())
            cout << "Cele 2 liste sunt vide, creati-le inainte de a le concatena\n";
        else if(a.empty())
            cout << "Lista A este goala\n";
        else
            cout << "Lista B este goala\n";
        cout << "Apasati orice tasta pentru a reveni la meniul principal";
        getch();
    }
    else {
        cout << "Concatenarea celor 2 liste este: \n";
        lista t;
        t=a;
        t+=b;
        cout << t;
        getch();
    }
}

void AdaugareFinal() {
    char c; int x;
    system("CLS");
    AfisareListe();
    cout << "In ce lista doriti sa adaugati? (A/B/0 - pentru a reveni la meniu)\n";
    cin >> c;
    if(c == 'A') {
        cout << "Care este numarul?\n";
        cin >> x;
        a.AdaugaFinal(a.pr, x);
    } else if(c == 'B') {
        cout << "Care este numarul?\n";
        cin >> x;
        b.AdaugaFinal(b.pr, x);
    } else if(c != '0'){
        cout << "Nu ati introdus o lista valida, apasati orice tasta pentru a incerca dinou\n";
        getch();
        AdaugareFinal();
    }
}
void AdaugareInceput() {
    char c; int x;
    system("CLS");
    AfisareListe();
    cout << "In ce lista doriti sa adaugati? (A/B/0 - pentru a reveni la meniu)\n";
    cin >> c;
    if(c == 'A') {
        cout << "Care este numarul?\n";
        cin >> x;
        a.AdaugaInceput(a.pr, x);
    } else if(c == 'B') {
        cout << "Care este numarul?\n";
        cin >> x;
        b.AdaugaInceput(b.pr, x);
    } else if(c != '0'){
        cout << "Nu ati introdus o lista valida, apasati orice tasta pentru a incerca dinou\n";
        getch();
        AdaugareInceput();
    }
}

void Stergere() {
    char c; int x;
    system("CLS");
    AfisareListe();
    cout << "Din ce lista doriti sa stergeti? (A/B/0 - pentru a reveni la meniu)\n";
    cin >> c;
    if(c == 'A') {
        cout << "Ce element doriti sa stergeti?\n";
        cin >> x;
        a.DeleteOn(x);
    } else if(c == 'B') {
        cout << "Ce element doriti sa stergeti?\n";
        cin >> x;
        b.DeleteOn(x);
    } else if(c != '0'){
        cout << "Nu ati introdus o lista valida, apasati orice tasta pentru a incerca dinou\n";
        getch();
        Stergere();
    }
}

void VerificareVid() {
    system("CLS");
    AfisareListe();
    if(a.empty() && b.empty())
        cout << "Ambele liste sunt goale\n";
    else if(a.empty())
        cout << "Lista A este goala\n";
    else if(b.empty())
        cout << "Lista B este goala\n";
    else
        cout << "Niciuna din liste nu este goala\n";
    getch();
}

void Cautare() {
    char c;  int x;
    system("CLS");
    AfisareListe();
    cout << "In ce lista doriti sa cautati? (A/B/0 - pentru a reveni la meniu)\n";
    cin >> c;
    if(c == 'A') {
        cout << "Ce element doriti sa cautati?\n";
        cin >> x;
        int t = a.SearchFor(x);
        cout << "Elementul " << x << " se afla pe pozitia " << t << "\n";
        getch();
    } else if(c == 'B') {
        cout << "Ce element doriti sa cautati?\n";
        cin >> x;
        int t = b.SearchFor(x);
        cout << "Elementul " << x << " se afla pe pozitia " << t << "\n";
        getch();
    } else if(c != '0'){
        cout << "Nu ati introdus o lista valida, apasati orice tasta pentru a incerca dinou\n";
        getch();
        Cautare();
    }
}

int main()
{
    int c;
    system("CLS");
    system("Color 07");
    //SetConsoleTextAttribute(hConsole, 1);
    AfisareListe();
    Menu();
    cin >> c;
    while (c != 0) {
        switch (c) {
            case 1:
                CreareLista();
                break;
            case 2:
                AdunareListe();
                break;
            case 3:
                AdaugareFinal();
                break;
            case 4:
                AdaugareInceput();
                break;
            case 5:
                Stergere();
                break;
            case 6:
                VerificareVid();
                break;
            case 7:
                Cautare();
                break;
            case 8:
                c = 0;
            default:
                break;
        }
        system("CLS");
        AfisareListe();

        Menu();
        cin >> c;
        if(c == 8)
            c = 0;
    }
}