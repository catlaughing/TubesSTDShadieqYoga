#include "list_parent.h"

void createList(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertLast(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else if(findElm(L, info(P)) == NULL) {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        first(L) = P;
        next(Q) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    if (next(Prec) == first(L))
        insertLast(L,P);
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void InsertAndSort(List_parent &L, address_parent P)
{
    if (first(L) == NULL || info(P) < info(first(L)))
        insertFirst(L,P);
    else if(findElm(L,info(P)) == NULL)
    {
        address_parent Q = first(L);
        do
        {
            Q = next(Q);
        }while (next(Q) != first(L) && info(next(Q)) < info(P));
        insertAfter(L,Q,P);
    }
    else
        cout<<"Duplicate"<<endl;
}


void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<"Teater "<<info(P)<<endl;
            P = next(P);
        } while((P)!=first(L));
    }
}

address_parent findElm(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P) {
    P = next(Prec);
    next(Prec)= next(P);
    next(P)= NULL;
}

void deleteFirst(List_parent &L, address_parent &P) {
    if(first(L) != NULL) {
        P = first(L);
        address_parent Q = first(L);
        do
        {
            Q = next(Q);
        }while(next(Q) != first(L));
        next(Q) = next(P);
        first(L) = next(Q);
        next(P) = NULL;

    }
}

