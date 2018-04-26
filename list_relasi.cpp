#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_child C) {
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    if (first(L) == NULL)
        cout<<"Belum ada film"<<endl;
    while(P !=NULL) {
        cout<<"-> "<<info(info(P)).judul<<endl;
        P = next(P);
    }
}

void deleteFirst(List_relasi &L, address_relasi &P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteAfter(address_relasi Prec, address_relasi& P)
{
    if (next(Prec) != NULL)
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
        delete P;
    }
}


address_relasi findElm(List_relasi L, address_child C) {
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(P)== C) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

