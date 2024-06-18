#include "../include/Album.hpp"

void createAlbum(ptrAlbum &newAlbum) // membuat node album baru taro di header album
{
    newAlbum = new Album;
    cout << "Masukkan id album: ";
    cin >> newAlbum->idAlbum;
    cout << "Masukkan judul album: ";
    cin >> newAlbum->judulAlbum;
    newAlbum->nextAlbum = nullptr;
    newAlbum->firstLagu = nullptr;
}

bool deleteAlbumWithNumber(ptrArtis pBantuArtis, ptrAlbum &ptrAlbumPrev, ptrAlbum &pBantuAlbum, int pilihAlbum)
{
    pBantuAlbum = pBantuArtis->firstAlbum;
    ptrAlbumPrev = nullptr;
    while (pBantuAlbum != nullptr)
    {
        if (pilihAlbum == 1)
        {
            return true;
        }
        else
        {
            ptrAlbumPrev = pBantuAlbum;
            pBantuAlbum = pBantuAlbum->nextAlbum;
            pilihAlbum--;
        }
    }
    return false;
}


void traversalAlbum(ptrArtis pBantuArtis) // menampilkan semua album dari artis tertentu di luar playlist taro di header album
{
    int no = 1;
    ptrAlbum pBantu = pBantuArtis->firstAlbum;
    if (pBantu == nullptr)
    {
        cout << "kosong";
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->judulAlbum << " ID " << pBantu->idAlbum << endl;
            no++;
            pBantu = pBantu->nextAlbum;
        }
    }
}

void pickAlbumFromArtis(ptrArtis pBantuArtis, int pilihAlbum) // memilih album dari artis diluar playlist masukin ke header album
{
    ptrAlbum pBantu = pBantuArtis->firstAlbum;
    while (pBantu != nullptr)
    {
        if (pilihAlbum != 1)
        {
            pilihAlbum--;
            pBantu = pBantu->nextAlbum;
        }
        else if (pilihAlbum == 1)
        {
            traversalLaguFromAlbum(pBantu);
            cout << "Mau Pilih Lagu ke berapa? ";
            int pilihLagu;
            cin >> pilihLagu;
            pickLaguFromAlbum(pBantu, pilihLagu);
            break;
            return;
        }
    }
}

void pickAlbumFromList(first head, string key, int pilihAlbum) // memilih album dari banyaknya list album yang dicari
{
    int pilihLagu;
    ptrArtis pBantuArtis = head;
    while (pBantuArtis != nullptr)
    {
        ptrAlbum pBantuAlbum = pBantuArtis->firstAlbum;
        while (pBantuAlbum != nullptr)
        {
            if (pBantuAlbum->judulAlbum == key)
            {
                if (pilihAlbum == 1)
                {
                    traversalLaguFromAlbum(pBantuAlbum);
                    cout << "Mau Pilih Lagu ke berapa?";
                    cin >> pilihLagu;
                    pickLaguFromAlbum(pBantuAlbum, pilihLagu);
                    return;
                }
                else
                {
                    pilihAlbum--;
                }
            }
            pBantuAlbum = pBantuAlbum->nextAlbum;
        }
        pBantuArtis = pBantuArtis->nextArtis;
    }
}

void traversalAlbumByKey(first head, string key)
{
    ptrArtis pBantuArtis = head;
    int no = 1;
    bool found = false;
    while (pBantuArtis != nullptr)
    {
        ptrAlbum pBantuAlbum = pBantuArtis->firstAlbum;
        while (pBantuAlbum != nullptr)
        {
            if (pBantuAlbum->judulAlbum == key)
            {
                found = true;
                cout << no << ". " << pBantuAlbum->judulAlbum << " by " << pBantuArtis->namaArtis << endl;
                no++;
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
            else
            {
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
        }
        pBantuArtis = pBantuArtis->nextArtis;
    }
    if (found == false)
    {
        cout << "Judul Album tidak ditemukan" << endl;
    }
}

void fungsiMemilihAlbum(first head, string key) // mencari album tertentu yang ingin dilihat lagunya masukin ke header album
{

    int pilihAlbum; // album ke berapa yang mau diliat lagunya
    bool pilihLagu = true;
    while (pilihLagu == true)
    {
        traversalAlbumByKey(head, key);
        cout << "Pilih album ke berapa (0 untuk keluar): ";
        cin >> pilihAlbum;
        if (pilihAlbum == 0)
        {
            pilihLagu = false;
        }
        else
        {
            pickAlbumFromList(head, key, pilihAlbum);
        }
    }
}
void traversalSearchAlbum(first head, string key) // mencari album tertentu yang ingin dilihat lagunya masukin ke header album
{
    ptrArtis pBantuArtis = head;
    int no = 1;
    int pilihAlbum; // album ke berapa yang mau diliat lagunya
    while (pBantuArtis != nullptr)
    {
        ptrAlbum pBantuAlbum = pBantuArtis->firstAlbum;
        while (pBantuAlbum != nullptr)
        {
            if (pBantuAlbum->judulAlbum == key)
            {
                cout << no << ". " << pBantuAlbum->judulAlbum << endl;
                no++;
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
            else
            {
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
        }
        pBantuArtis = pBantuArtis->nextArtis;
    }
    bool pilihLagu = true;
    while (pilihLagu == true)
    {
        cout << "Pilih album ke berapa (0 untuk keluar): ";
        cin >> pilihAlbum;
        if (pilihAlbum == 0)
        {
            pilihLagu = false;
        }
        else
        {
            pickAlbumFromList(head, key, pilihAlbum);
        }
    }
}

bool searchAlbuminArtis(ptrArtis pCariArtis, ptrAlbum &pCariAlbum, ptrAlbum &pCariAlbumPrev, const string key) // mencari album dari artis tertentu masukin ke header album
{
    pCariAlbum = pCariArtis->firstAlbum;
    pCariAlbumPrev = nullptr;
    bool found = false;
    while (pCariAlbum != nullptr && found == false)
    {
        if (pCariAlbum->idAlbum == key)
        {
            found = true;
        }
        else
        {
            pCariAlbumPrev = pCariAlbum;
            pCariAlbum = pCariAlbum->nextAlbum;
        }
    }
    return found;
}

void insertFirstAlbum(ptrAlbum &newAlbum, ptrArtis pCariArtis) // operasi insert first album masukin ke header album
{
    if (pCariArtis->firstAlbum == nullptr)
    {
        pCariArtis->firstAlbum = newAlbum;
    }
    else
    {
        newAlbum->nextAlbum = pCariArtis->firstAlbum;
        pCariArtis->firstAlbum = newAlbum;
    }
    pCariArtis->jumlahAlbum++;
}

void insertLastAlbum(ptrAlbum &newAlbum, ptrArtis pCariArtis) // operasi insert last album masukin ke header album
{
    ptrAlbum pBantu = pCariArtis->firstAlbum;
    if (pCariArtis->firstAlbum == nullptr)
    {
        pCariArtis->firstAlbum = newAlbum;
    }
    else
    {
        while (pBantu->nextAlbum != nullptr)
        {
            pBantu = pBantu->nextAlbum;
        }
        pBantu->nextAlbum = newAlbum;
    }
    pCariArtis->jumlahAlbum++;
}

void deleteFirstAlbum(ptrArtis pCariArtis, ptrAlbum &pHapus) // operasi delete first album masukin ke header album
{
    if (pCariArtis == nullptr || pCariArtis->firstAlbum == nullptr)
    {
        cout << "Tidak ada album untuk dihapus" << endl;
    }
    else if (pCariArtis->firstAlbum->nextAlbum == nullptr && pCariArtis->firstAlbum != nullptr)
    {
        pHapus = pCariArtis->firstAlbum;
        pCariArtis->firstAlbum = nullptr;
    }
    else
    {

        pHapus = pCariArtis->firstAlbum;
        pCariArtis->firstAlbum = pHapus->nextAlbum;
        pHapus->nextAlbum = nullptr;
    }
    pCariArtis->jumlahAlbum--;
}

void deleteLastAlbum(ptrArtis pCariArtis, ptrAlbum &pHapus) // operasi delete last album masukin ke header album
{
    ptrAlbum prevAlbum = nullptr;
    pHapus = pCariArtis->firstAlbum;
    if (pCariArtis == nullptr || pCariArtis->firstAlbum == nullptr)
    {
        cout << "Tidak ada album untuk dihapus" << endl;
    }
    while (pHapus->nextAlbum != nullptr)
    {
        prevAlbum = pHapus;
        pHapus = pHapus->nextAlbum;
    }
    if (prevAlbum == nullptr)
    {
        pHapus = pHapus->nextAlbum;
    }

    prevAlbum->nextAlbum = nullptr;
    pCariArtis->jumlahAlbum--;
}

void deletePcariAlbum(ptrArtis pCariArtis, ptrAlbum pCariAlbumPrev, ptrAlbum pCariAlbum, first &head, ptrAlbum &pHapus) // operasi menghapus album tertentu yang di search masukin ke header album
{
    if (head->firstAlbum == nullptr)
    {
        cout << "Tambahin album dlu";
    }
    else if (pCariAlbum->nextAlbum == nullptr && pCariAlbumPrev != nullptr)
    {
        cout << "delete last" << endl;
        deleteLastAlbum(pCariArtis, pHapus);
    }
    else if (pCariAlbumPrev == nullptr)
    {
        cout << "delete first" << endl;
        deleteFirstAlbum(pCariArtis, pHapus);
    }
    else if (pCariAlbumPrev != nullptr && pCariAlbum->nextAlbum != nullptr)
    {
        pCariAlbumPrev->nextAlbum = pCariAlbum->nextAlbum;
        pHapus = pCariAlbum;
    }
}
