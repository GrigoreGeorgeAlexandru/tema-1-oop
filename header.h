#include <iostream>
using namespace std;
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class Nod{
private:
int info;
Nod* prev;
Nod* next;
public:
Nod();
Nod(int info,Nod* prev=0,Nod* next=0);
~Nod();
void SetInfo(int info);
int GetInfo();
void SetPrev(Nod* prev);
Nod* GetPrev();
void SetNext(Nod* next);
Nod* GetNext();
};

class Lista_dublu_inlantuita{

private:
Nod* first;
Nod* last;

public:
Lista_dublu_inlantuita(Nod* first=0,Nod* last=0);
void AddElement(Nod nod,int pozitie);
int ListLength();
Nod* GetElementatpoz(int pozitie);
int GetPozofElement(Nod* nod);
int IsEmpty();
void DeleteElementatpoz(int pozitie);
Nod* GetLast();
Nod* GetFirst();
friend istream& operator >>(istream& in,Lista_dublu_inlantuita& lista);
friend ostream& operator<<(ostream& out,Lista_dublu_inlantuita& lista);
friend Lista_dublu_inlantuita operator+(Lista_dublu_inlantuita& lista1,Lista_dublu_inlantuita& lista2);
friend Lista_dublu_inlantuita* Read_N_elements(int n);

};


#endif // HEADER_H_INCLUDED
