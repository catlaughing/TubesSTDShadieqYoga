#include "list_child.h"

/**
Nama : Nuurshadieq
NIM : 1301171087
**/

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child X) {
    address_child P = new elmlist_child;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        last(L)->next = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<endl;
        cout<<"Judul: "<<info(P).judul<<endl;
        cout<<"Genre: "<<info(P).genre<<endl;
        cout<<"Rating: "<<info(P).rating<<endl;
        cout<<"---------------"<<endl;
        P = next(P);
    }
}

void printGenre(List_child L) {
    address_child P = first(L);
    int i = 0;
    int k = 0;
    bool found;
    string genres[100];
    while(P !=NULL) {
        found = false;
        for (int j = 0; j < i; j++)
        {
            if (genres[j] == info(P).genre)
                found = true;
        }
        if (!found)
        {
            cout<<k+1<<". "<<info(P).genre<<endl;
            k++;
        }
        genres[i] = info(P).genre;
        P = next(P);
        i++;
    }
}

void findGenre(List_child L, string genre)
{
    address_child P = first(L);
    while(P !=NULL) {
        if (info(P).genre == genre)
            cout<<"-> "<<info(P).judul<<endl;
        P = next(P);
    }
}

address_child findElm(List_child L, string judul) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).judul==judul) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteLast(List_child &L, address_child &P)
{
    P = last(L);
    last(L) = prev(P);
    next(last(L)) = NULL;
    prev(P) = NULL;
}

void deleteAfter(address_child Prec, address_child &P)
{
    if (Prec != NULL && next(Prec) != NULL)
    {
        P = next(Prec);
        next(Prec) =  next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteFirst(List_child &L, address_child &P)
{
    if (next(first(L)) == NULL)
    {
        P = first(L);
        first(L) = NULL;
    }

    else
    {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
    }
    next(P) = NULL;
    prev(P) = NULL;
}
