#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

void menu(bool start, List_child &LC, List_parent &LP);
void option(List_child &LC, List_parent &LP);
List_parent LP;
List_child LC;
string password = "apakek";
int main()
{
    createList(LP);
    createList(LC);
    teater *satu;
    teater *dua;
    teater *tiga;


    satu = alokasi(1);
    dua = alokasi(2);
    tiga = alokasi(3);

    insertLast(LP, satu);
    insertLast(LP, dua);
    insertLast(LP, tiga);
    film rampage,avenger,deadpool;
    rampage.judul = "Rampage";
    rampage.genre = "Fantasy";
    rampage.rating = "PG-13";

    avenger.judul = "Avenger: Infinity War";
    avenger.genre = "Action";
    avenger.rating = "PG-13";

    deadpool.judul = "Deadpool";
    deadpool.genre = "Action";
    deadpool.rating = "R";

    insertLast(LC,alokasi(rampage));
    insertLast(LC,alokasi(avenger));
    insertLast(LC,alokasi(deadpool));

    bool start = true;
    while (start)
        menu(start, LC, LP);
}

void menu(bool start, List_child &LC, List_parent &LP)
{
    int pilihan;
    teater *pilih;

    if (first(child(first(LP))) == NULL)
        insertFirst(child(first(LP)), alokasi(findElm(LC, "Rampage")));

    cout<<"Welcome to YS Cinema"<<endl;
    cout<<"Silahkan pilih teater"<<endl;
    printInfo(LP);
    cout<<"Pilihan anda: ";
    cin>>pilihan;

    if (pilihan == 0)
    {
//        string pass;
//        cin>>pass;
//        if (pass == password)
            system ("CLS");
            option(LC,LP);
    }
    else
    {
        pilih = findElm(LP, pilihan);

        if (pilih == NULL)
        {
            cout<<"Teater tidak ditemukan"<<endl;
            system ("PAUSE");
            system ("CLS");
            return;
        }

        system ("CLS");
        cout<<"Film yang sedang tayang pada teater "<<pilih->info<<endl;
        printInfo(pilih->child);
        cout<<endl;
        cout<<"Ketik judul film yang anda inginkan: ";
        string jupil;
        cin>>jupil;
        cout<<endl;
        address_child fipil = findElm(LC, jupil);
        if (fipil == NULL)
            cout<<"Film tidak tersedia di teater ini"<<endl;
        else
        {
            cout<<"Judul : "<<info(fipil).judul<<endl;
            cout<<"Genre : "<<info(fipil).genre<<endl;
            cout<<"Rating: "<<info(fipil).rating<<endl;
            cout<<endl;
            cout<<"Jumlah tiket yang anda inginkan: ";
            int tiket;
            cin>>tiket;
            cout<<"Total harga: "<<"Rp"<<tiket*30000<<endl;

        }
        system ("PAUSE");
        system ("CLS");
    }

}

void option(List_child &LC, List_parent &LP)
{
    cout<<"1. Tambahkan Film Baru"<<endl;
    cout<<"2. Ganti Film"<<endl;
    cout<<"3. Bangun teater baru"<<endl;
    cout<<"4. Hapus film"<<endl;
    cout<<"5. Tambah film ke teater"<<endl;
    cout<<"6. Hancurkan teater"<<endl<<endl;
    int choice;
    cout<<"Masukkan pilihan anda: ";
    cin>>choice;
    cout<<endl;
    switch (choice)
    {
    case 1 :
        {
            film baru;
            cout<<"Judul : ";
            cin>>baru.judul;
            cout<<"Genre : ";
            cin>>baru.genre;
            cout<<"Rating: ";
            cin>>baru.rating;
            insertLast(LC, alokasi(baru));
            system("CLS");
            break;
        }
    case 2 :
        {
            cout<<"Pilih teater yang ingin diganti filmnya: "<<endl;
            printInfo(LP);
            cout<<"Teater pilihan anda: ";
            int tepil;
            cin>>tepil;
            cout<<endl;
            teater *tepill = findElm(LP, tepil);
            cout<<"Film yang tayang pada teater "<<tepil<<": "<<endl;
            printInfo(child(tepill));
//            if ((child(tepil)) == NULL)
//            {
//                break;
//            }
//            else {

                cout<<"Film yang tersedia :"<<endl;
                printInfo(LC);
                cout<<"Judul film yang ingin diganti: ";
                string juduldiganti;
                cin>>juduldiganti;
                address_child filmdiganti = findElm(LC, juduldiganti);
                address_relasi alamatfilm = findElm(child(tepill), filmdiganti);
                cout<<"Film baru: ";
                string judulpengganti;
                cin>>judulpengganti;
                address_child filmpengganti = findElm(LC, judulpengganti);
                alamatfilm->info = filmpengganti;
                printInfo(child(tepill));
                system("CLS");
                break;
           // }
        }
    case 3 :
        {
            int noteater;
            cout<<"Nomor teater baru: ";
            cin>>noteater;
            teater* newteater = alokasi(noteater);
            insertLast(LP, newteater);
            cout<<"Teater berhasil dibangun";
            system("PAUSE");
            system("CLS");
            break;
        }
    case 4 :
        {
            printInfo(LC);
            string judulfilm;
            cout<<"Judul film yang ingin dihapus: ";
            cin>>judulfilm;
            address_child erasedfilm = findElm(LC, judulfilm);
            address_child filmbuangan;
            teater* P = first(LP);
            do
            {
                address_relasi Q = first(child(P));
                address_relasi R;
                if ((Q!=NULL) && (info(first(child(P))) == erasedfilm))
                    deleteFirst(child(P), R);
                else if (Q!=NULL)
                {
                    while ((Q != NULL) && (next(Q) != NULL))
                    {
                        deleteAfter(Q, R);
                        delete R;
                    }
                    Q = next(Q);
                }
                printInfo(child(P));
                P = next(P);
            }
            while(P != first(LP));
            deleteAfter(prev(erasedfilm), filmbuangan);
            delete filmbuangan;
            system("CLS");
            break;
        }
    case 5 :
        {
            printInfo(LC);
            string judulfilm;
            int noteater;
            cout<<"Judul film yang ingin ditambahkan: ";
            cin>>judulfilm;
            printInfo(LP);
            cout<<"Teater yang diinginkan: ";
            cin>>noteater;
            address_child Q = findElm(LC, judulfilm);
            address_parent P= findElm(LP,noteater);
            insertFirst(child(P), alokasi(Q));
            printInfo(child(P));
            cout<<endl;
            cout<<"Film berhasil ditambahkan ke teater "<<noteater<<endl;
            system ("PAUSE");
            system("CLS");
            break;
        }
    case 6 :
        {
            cout<<"Teater yang tersedia: "<<endl;
            printInfo(LP);
            int tecur;
            cout<<"Teater yang ingin dihancurkan :";
            cin>>tecur;
            address_parent P = findElm(LP, tecur);
            address_parent R;
            address_parent S;
            address_relasi Q;
            if (P != NULL)
            {
                while (first(child(P)) != NULL)
                {
                    deleteFirst(child(P),Q);
                    delete Q;
                }
                if (P == first(LP))
                {
                    deleteFirst(LP,S);
                    cout<<"Teater berhasil dihancurkan"<<endl;
                }
                else
                {
                    R = first(LP);
                    while (next(R) != P)
                    {
                        R = next(R);
                    }
                    deleteAfter(LP,R,S);
                    cout<<"Teater berhasil dihancurkan"<<endl;
                }
                delete S;
                system ("PAUSE");
                system ("CLS");
                break;
            }
        }
    }
}
