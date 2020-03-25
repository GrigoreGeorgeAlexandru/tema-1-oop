#include "header.h"
#include <iostream>

using namespace std;

#include "header.h"
Nod::Nod(){
info=0;
prev=0;
next=0;

}

Nod::Nod(int info,Nod* prev,Nod* next){
this->info=info;
this->prev=prev;
this->next=next;

}

Nod::~Nod(){}


void Nod::SetInfo(int info){this->info=info;}
int Nod::GetInfo(){ return info;}
void Nod::SetPrev(Nod* prev){this->prev=prev;}
Nod* Nod::GetPrev(){return prev;}
void Nod::SetNext(Nod* next){this->next=next;}
Nod* Nod::GetNext(){return next;}


Lista_dublu_inlantuita::Lista_dublu_inlantuita(Nod* first,Nod* last){

this->first=first;
this->last=last;



};

int Lista_dublu_inlantuita::ListLength(){
Nod* curent=first;
int l=0;//cout<<curent<<endl;
while(curent)
{//cout<<curent<<endl;
curent =curent->GetNext();
    l++;
}

return l;
};
int Lista_dublu_inlantuita::IsEmpty(){if(first==0)return 1;else return 0;}
Nod* Lista_dublu_inlantuita::GetElementatpoz(int pozitie){

int i;
Nod* curent=first;
for(i=1;i<pozitie;i++)
curent =curent->GetNext();

return curent;

}

void Lista_dublu_inlantuita::AddElement(Nod nod,int pozitie){
if(IsEmpty()==1)
  {
      first=last=&nod;
     // cout<<"0 "<<first->GetInfo()<<":"<<first<<endl;
    //cout<<first->GetPrev()<<" "<<first<<" "<<first->GetNext()<<endl;
    }
else if(pozitie-1>ListLength())
    {cout<<"Lista nu contine destule elemente pentru a se putea adauga un element pe pozitia "<<pozitie<<endl;}


else if(pozitie==1)
{Nod* newnod=new Nod(nod.GetInfo(),0,0);//cout<<"1 "<<newnod->GetInfo()<<":"<<newnod<<endl;
    Nod* succ=GetElementatpoz(pozitie);//cout<<"2 "<<succ->GetInfo()<<":"<<succ<<endl;
newnod->SetNext(succ);
succ->SetPrev(newnod);
first=newnod;
}

else if(pozitie>ListLength())
{Nod* newnod=new Nod(nod.GetInfo(),0,0);//cout<<"3 "<<newnod->GetInfo()<<":"<<newnod<<endl;
    Nod* pred=GetElementatpoz(pozitie-1);//cout<<"4 "<<pred->GetInfo()<<":"<<pred<<endl;
    newnod->SetPrev(pred);
    pred->SetNext(newnod);
last=newnod;
}


else{
Nod* newnod=new Nod(nod.GetInfo(),0,0);//cout<<"5 "<<newnod->GetInfo()<<":"<<newnod<<endl;
//cout<<ListLength()<<endl;
//cout<<newnod->GetPrev()<<" "<<newnod->GetNext()<<endl;

Nod* pred=GetElementatpoz(pozitie-1);//cout<<pred->GetPrev()<<" "<<pred<<" "<<pred->GetNext()<<endl;
//cout<<pred->GetInfo()<<":"<<pred<<endl;
Nod* succ=GetElementatpoz(pozitie);//cout<<"6 "<<succ->GetInfo()<<":"<<succ<<endl;
newnod->SetNext(succ);
newnod->SetPrev(pred);
pred->SetNext(newnod);
succ->SetPrev(newnod);
//cout<<newnod->GetPrev()<<" "<<newnod<<" "<<newnod->GetNext()<<endl;
//cout<<pred->GetPrev()<<" "<<pred<<" "<<pred->GetNext()<<endl;
}
};
void Lista_dublu_inlantuita::DeleteElementatpoz(int pozitie){
if(pozitie>ListLength())
    {cout<<"Nu exista un element pe pozitia "<<pozitie<<endl;}
else{
Nod* oldnod=GetElementatpoz(pozitie);
if(pozitie<ListLength())
{(oldnod->GetNext())->SetPrev(oldnod->GetPrev());if(pozitie==1)first=oldnod->GetNext();}
if(pozitie>1)
{(oldnod->GetPrev())->SetNext(oldnod->GetNext());if(pozitie-1==ListLength())last=oldnod->GetPrev();}
delete oldnod;
}

};
int Lista_dublu_inlantuita::GetPozofElement(Nod* nod){

Nod* curent=first;
int poz=1;//cout<<nod<<endl;
while(curent!=nod)
{//cout<<curent<<endl;

curent =curent->GetNext();
poz++;


}

return poz ;



};

Nod* Lista_dublu_inlantuita::GetLast(){return last;}
Nod* Lista_dublu_inlantuita::GetFirst(){return first;}

istream& operator>>(istream& in,Lista_dublu_inlantuita& lista){
int l=0;int i;int poz;int nr=1;
cout<<"numarul de noduri care vor fi introduce=";in>>l;
while(l>0){
  cout<<"Nodul #" <<nr<<":"<<endl;nr++;
cout<<"valoarea nodului=";in>>i;
cout<<"pozitia nodului=";in>>poz;
//cout<<poz1->GetInfo()<<endl;
//int poz=lista.GetPozofElement(lista.GetLast());
lista.AddElement(Nod(i),poz);l--;}
return in;
};

ostream& operator<<(ostream& out,Lista_dublu_inlantuita& lista){
Nod* curent=lista.GetFirst();
out<<"lista de la cap la coada:"<<endl;
while(curent!=0)
{out<<curent->GetInfo()<<" ";
curent=curent->GetNext();
}
out<<endl;
out<<"lista de la coada la cap:"<<endl;

curent=lista.GetLast();
while(curent!=0)
{out<<curent->GetInfo()<<" ";
curent=curent->GetPrev();
}

out<<endl;
return out;
};
Lista_dublu_inlantuita operator+(Lista_dublu_inlantuita& lista1,Lista_dublu_inlantuita& lista2){
Lista_dublu_inlantuita* a=new Lista_dublu_inlantuita(0,0);
*a=lista1;
Lista_dublu_inlantuita b=lista2;
//cout<<a<<endl;
//cout<<b<<endl;
Nod* curent=b.GetFirst();
int l=b.ListLength();
while(l>0){
a->AddElement(Nod(curent->GetInfo()),a->ListLength()+1);
//cout<<curent<<endl;
curent=curent->GetNext();l--;
}

//cout<<*a<<endl;
return *a;
};

Lista_dublu_inlantuita* Read_N_elements(int n){
    int i;
    Lista_dublu_inlantuita* v=new Lista_dublu_inlantuita[n];

for(i=0;i<n;i++)
    cin>>v[i];
 /*
for(i=0;i<n;i++)
cout<<v[i].GetLast()<<endl;
    cout<<v[i]<<endl;
*/

    return v;
};


int main()
{ /*Nod nod(1);
Lista_dublu_inlantuita lista;
cout<<lista.ListLength()<<endl;
lista.AddElement(Nod(10),1);
cout<<lista.ListLength()<<endl;
lista.AddElement(Nod(20),2);
cout<<lista.ListLength()<<endl;
lista.AddElement(Nod(30),3);
cout<<lista.ListLength()<<endl;
lista.AddElement(Nod(4),1);
cout<<lista.ListLength()<<endl;
lista.AddElement(Nod(5),3);
cout<<lista.ListLength()<<endl;
lista.AddElement(Nod(6),6);
cout<<lista.ListLength()<<endl;
lista.DeleteElementatpoz(1);
cout<<lista.ListLength()<<endl;
lista.DeleteElementatpoz(5);
cout<<lista.ListLength()<<endl;
lista.DeleteElementatpoz(2);
cout<<lista.ListLength()<<endl;
Lista_dublu_inlantuita lista2;
cout<<lista2.ListLength()<<endl;
lista2.AddElement(Nod(1),1);
cout<<lista2.ListLength()<<endl;
lista2.AddElement(Nod(2),2);
cout<<lista2.ListLength()<<endl;
lista2.AddElement(Nod(3),3);
cout<<lista2.ListLength()<<endl;
lista2.AddElement(Nod(4),1);
cout<<lista2.ListLength()<<endl;
lista2.AddElement(Nod(5),3);
cout<<lista2.ListLength()<<endl;
lista2.AddElement(Nod(6),6);
cout<<lista2.ListLength()<<endl;
lista2.DeleteElementatpoz(1);
cout<<lista2.ListLength()<<endl;
lista2.DeleteElementatpoz(5);
cout<<lista2.ListLength()<<endl;
lista2.DeleteElementatpoz(2);
cout<<lista2.ListLength()<<endl;


cin>>lista2;
cout<<lista2.ListLength()<<endl;
cout<<lista<<endl;
cout<<lista2<<endl;

Lista_dublu_inlantuita lista3;
lista3=lista+lista2;
cout<<lista3<<endl;
Lista_dublu_inlantuita lista4;
lista4=lista3+lista3;
cout<<lista4<<endl;

Lista_dublu_inlantuita* listav;
cout<<"numarul de liste care vor fi citie="<<endl;
int n;
cin>>n;
listav=Read_N_elements(n);*/


}
