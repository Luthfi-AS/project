#include "../include/Artis.hpp"

void createDataList(first &list) // membuat list baru untuk artis taro di header artis
{
    list = nullptr;
}

void createArtis(ptrArtis &newArtis) // membuat node artis baru taro di header artis
{
    newArtis = new Artis;
    cout << "Masukkan id artis: ";
    cin >> newArtis->idArtis;
    cout << "Masukkan nama artis: ";
    cin >> newArtis->namaArtis;
    newArtis->nextArtis = nullptr;
    newArtis->firstAlbum = nullptr;
}

void traversalArtis(first head) // menampilkan semua artis di luar playlist taro di header artis
{
    int no = 1;
    ptrArtis pBantu = head;
    if (head == nullptr)
    {
        cout << "kosong";
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->namaArtis << " ID " << pBantu->idArtis << endl;
            no++;
            pBantu = pBantu->nextArtis;
        }
    }
}

void pickArtisFromList(first head, string key, int pilihArtis) // memilih artis dari banyaknya artis dengan nama artis yang di cari diluar playlist masukin ke header artis
{
    ptrArtis pBantu = head;
    while (pBantu != nullptr)
    {
        if (pBantu->namaArtis == key)
        {
            if (pilihArtis == 1)
            {
                traversalAlbum(pBantu);
                cout << "Mau Pilih Album ke berapa? ";
                int pilihAlbum;
                cin >> pilihAlbum;
                pickAlbumFromArtis(pBantu, pilihAlbum);
                break;
            }
            else
            {
                pilihArtis--;
            }
        }
        pBantu = pBantu->nextArtis;
    }
}

bool deleteArtisWithNumber(first head, ptrArtis &ptrArtisPrev, ptrArtis &pBantuArtis, int pilihArtis)
{
    pBantuArtis = head;
    ptrArtisPrev = nullptr;
    while (pBantuArtis != nullptr)
    {
        if (pilihArtis == 1)
        {
            return true;
        }
        else
        {
            ptrArtisPrev = pBantuArtis;
            pBantuArtis = pBantuArtis->nextArtis;
            pilihArtis--;
        }
    }
    return false;
}

void traversalArtisByKey(first head, string key)
{
    bool found = false;
    ptrArtis pBantu = head;
    int no = 1;
    while (pBantu != nullptr)
    {
        if (pBantu->namaArtis == key)
        {
            found = true;
            cout << no << ". " << pBantu->namaArtis << endl;
            no++;
            pBantu = pBantu->nextArtis;
        }
        else
        {
            pBantu = pBantu->nextArtis;
        }
    }
    if (found == false)
    {
        cout << "Nama artis tidak ditemukan" << endl;
    }
}

void traversalSearchArtis(first head, string key) // mencari artis dengan nama artis masukin ke header artis
{
    ptrArtis pBantu = head;
    int no = 1;
    int pilihArtis; // artis ke berapa yang mau diliat albumnya
    while (pBantu != nullptr)
    {
        if (pBantu->namaArtis == key)
        {
            cout << no << ". " << pBantu->namaArtis << endl;
            no++;
            pBantu = pBantu->nextArtis;
        }
        else
        {
            pBantu = pBantu->nextArtis;
        }
    }
    bool pilihAlbum = true;
    while (pilihAlbum == true)
    {
        cout << "Pilih artis ke berapa (0 untuk keluar): ";
        cin >> pilihArtis;
        if (pilihArtis == 0)
        {
            pilihAlbum = false;
        }
        else
        {
            pickArtisFromList(head, key, pilihArtis);
        }
    }
}


void fungsiMemilihArtis(first head, string key) // mencari artis dengan nama artis masukin ke header artis
{

    int pilihArtis; // artis ke berapa yang mau diliat albumnya

    bool pilihAlbum = true;
    while (pilihAlbum == true)
    {
        traversalArtisByKey(head, key);
        cout << "Pilih artis ke berapa (0 untuk keluar): ";
        cin >> pilihArtis;
        if (pilihArtis == 0)
        {
            pilihAlbum = false;
        }
        else
        {
            pickArtisFromList(head, key, pilihArtis);
        }
    }
}


bool searchArtis(first head, ptrArtis &pCariArtis, ptrArtis &pCariArtisPrev, const string key) // mencari artis tertentu diluar playlilst masukin ke header artis
{
    pCariArtis = head;
    pCariArtisPrev = nullptr;
    bool found = false;
    while (!found && pCariArtis != nullptr)
    {
        if (pCariArtis->idArtis == key)
        {
            found = true;
        }
        else
        {
            pCariArtisPrev = pCariArtis;
            pCariArtis = pCariArtis->nextArtis;
        }
    }
    return found;
}

void insertFirstArtis(ptrArtis &newArtis, first &head) // operasi insert first artis masukin ke header artis
{
    if (head == nullptr)
    {
        head = newArtis;
    }
    else
    {
        newArtis->nextArtis = head;
        head = newArtis;
    }
}

void insertLastArtis(ptrArtis &newArtis, first &head) // operasi insert last artis masukin ke header artis
{
    ptrArtis pBantu = head;
    if (head == nullptr)
    {
        head = newArtis;
    }
    else
    {
        while (pBantu->nextArtis != nullptr)
        {
            pBantu = pBantu->nextArtis;
        }
        pBantu->nextArtis = newArtis;
    }
}

void deleteFirstArtis(first &head, ptrArtis &pHapus) // operasi delete first artis masukin ke header artis
{
    if (head == nullptr)
    {
        cout << "Tidak ada artis untuk dihapus" << endl;
    }
    else
    {
        pHapus = head;
        head = head->nextArtis;
        pHapus->nextArtis = nullptr;
    }
}

void deleteLastArtis(first &head, ptrArtis &pHapus) // operasi delete last  artis masukin ke header artis
{
    if (head == nullptr)
    {
        cout << "Tidak ada artis untuk dihapus" << endl;
    }
    else if (head->nextArtis == nullptr) // 1 data doang
    {
        pHapus = head;
        head = nullptr;
    }
    else
    {
        ptrArtis prevArtis = nullptr;
        pHapus = head;
        while (pHapus->nextArtis != nullptr)
        {
            prevArtis = pHapus;
            pHapus = pHapus->nextArtis;
        }
        prevArtis->nextArtis = nullptr;
    }
}

void deletePcariArtis(ptrArtis pCariArtis, ptrArtis pCariArtisPrev, first &head, ptrArtis &pHapus) // operasi menghapus artis tertentu yang dicari masukin ke header artis
{
    if (head == nullptr)
    {
        cout << "Tambahin artis dlu";
    }
    else if (pCariArtis->nextArtis == nullptr && pCariArtisPrev != nullptr)
    {
        cout << "berhasil dihapus" << endl;
        deleteLastArtis(head, pHapus);
    }
    else if (pCariArtisPrev == nullptr)
    {
        cout << " berhasil dihapus " << endl;
        deleteFirstArtis(head, pHapus);
    }
    else if (pCariArtisPrev != nullptr && pCariArtis->nextArtis != nullptr)
    {
        pCariArtisPrev->nextArtis = pCariArtis->nextArtis;
        pHapus = pCariArtis;
    }
}