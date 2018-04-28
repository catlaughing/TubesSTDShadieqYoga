#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "Tubes.h"

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

    avenger.judul = "Avenger";
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

    cout<<"Welcome to YS Cinema"<<endl<<endl;
    cout<<"Silahkan pilih teater"<<endl;
    printInfo(LP);
    cout<<endl;
    cout<<"(Tekan 99 untuk rekomendasi film berdasarkan genre)"<<endl;
    cout<<"(Tekan 0 untuk menjadi administrator)"<<endl;
    cout<<"Pilihan anda: ";
    cin>>pilihan;

    if (pilihan == 0)
    {
        cout<<"Masukkan kata sandi: ";
        string pass;
        cin>>pass;
        if (pass == password)
        {
            system ("CLS");
            option(LC,LP);
        }
        else
        {
            cout<<"Kata sandi salah"<<endl;
            system("PAUSE");
            system("CLS");
        }
    }
    else if (pilihan == 99)
    {
        RekomedasiGenre(LC,LP);
    }
    else //Beli tiket case functionality
    /**
Nama : Yoga Ajitama
NIM : 1301170471
**/
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
        if (first(child(pilih)) == NULL)
        {
            printInfo(child(pilih));
        }

        else
        {
            cout<<"Film yang sedang tayang pada teater "<<pilih->info<<endl<<endl;
            printInfo(pilih->child);
            cout<<endl;
            cout<<"Ketik judul film yang anda inginkan: ";
            string jupil;
            cin.ignore();
            getline(cin,jupil);
            address_relasi repil = findElm(child(pilih),findElm(LC,jupil));
            system ("CLS");
            if (repil == NULL)
                cout<<"Film tidak tersedia di teater ini"<<endl;
            else
            {
                cout<<"Judul: "<<info(info(repil)).judul<<endl;
                cout<<"Genre: "<<info(info(repil)).genre<<endl;
                cout<<"Rating: "<<info(info(repil)).rating<<endl;
                cout<<"Jumlah tiket yang anda inginkan: ";
                int tiket;
                cin>>tiket;
                cout<<"Total harga: "<<"Rp"<<tiket*30000<<endl;
                cout<<"Konfirmasi Pembelian [Y/N]: ";
                string jawab;
                cin>>jawab;
                if (jawab == "Y")
                    cout<<"Selamat Menikmati Film Anda !"<<endl;
                else
                    cout<<"Silahkan memilih film yang lain !"<<endl;
            }
        }
    }
    system ("PAUSE");
    system ("CLS");
}


void option(List_child &LC, List_parent &LP)
{
    cout<<"MENU"<<endl<<endl;
    cout<<"1.  Tambahkan film baru ke database"<<endl;
    cout<<"2.  Tambah film ke teater"<<endl;
    cout<<"3.  Ganti film di teater"<<endl;
    cout<<"4.  Hapus film"<<endl;
    cout<<"5.  Bangun teater baru"<<endl;
    cout<<"6.  Hancurkan teater"<<endl;
    cout<<"7.  Lihat semua teater dan filmnya"<<endl;
    cout<<"8.  Cek Relasi"<<endl;
    cout<<"9.  Hapus Film dari Teater"<<endl;
    cout<<"10. Lihat daftar film di database"<<endl;
    cout<<"11. Lihat teater yang tersedia"<<endl;
    cout<<"12. Lihat film dari suatu teater"<<endl<<endl;
    int choice;
    cout<<"Masukkan pilihan anda: ";
    cin>>choice;
    cout<<endl;
    switch (choice)
    {
    case 1 :
    {
        InsertNewFilm(LC,LP);
        break;
    }
    case 2 :
    {
        FilmToTeater(LC,LP);
        break;
    }
    case 3 :
    {
        ChangeFilm(LC,LP);
        break;
    }
    case 4 :
    {
        DeleteFilm(LC,LP);
        break;
    }
    case 5 :
    {
        NewTeater(LP);
        break;
    }
    case 6 :
    {
        DelTeater(LC,LP);
        break;
    }
    case 7 :
    {
        printAll(LP);
        break;
    }
    case 8 :
    {
        cekRelasi(LC,LP);
        break;
    }
    case 9 :
        {
            HapusFilmDariTeater(LP,LC);
            break;
        }
    case 10 :
        {
            displayChild(LC);
        }
    case 11 :
        {
            displayParent(LP);
        }
    case 12 :
        {
            displayChildofParent(LP);
        }
    }
}
