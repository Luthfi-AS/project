#include "../include/Lagu.hpp"

void createLagu(ptrLagu &newLagu) // membuat node lagu baru taro di header lagu
{
    newLagu = new Lagu;
    cout << "Masukkan id lagu: ";
    cin >> newLagu->idLagu;
    cout << "Masukkan judul lagu: ";
    cin >> newLagu->judulLagu;
    cout << "Masukkan genre lagu: ";
    cin >> newLagu->genre;
    cout << "Masukkan durasi lagu: ";
    cin >> newLagu->durasi;
    newLagu->nextLagu = nullptr;
    newLagu->prevLagu = nullptr;
}

bool deleteLaguWithNumber(ptrAlbum pBantuAlbum, ptrLagu &ptrLaguPrev, ptrLagu &ptrLagu, int pilihLagu)
{
    ptrLagu = pBantuAlbum->firstLagu;
    ptrLaguPrev = nullptr;
    while (ptrLagu != nullptr)
    {
        if (pilihLagu == 1)
        {
            return true;
        }
        else
        {
            ptrLaguPrev = ptrLagu;
            ptrLagu = ptrLagu->nextLagu;
            pilihLagu--;
        }
    }
    return false;
}

void outputMenuLagu(ptrLagu pBantu) // menampilkan lagu yang di pilih di luar playlist taro di header lagu
{
    cout << "\njudul lagu : ";
    cout << pBantu->judulLagu;
    cout << "\ngenre lagu : ";
    cout << pBantu->judulLagu;
    cout << "\ndurasi lagu : ";
    cout << pBantu->durasi;
}

void menuLagu(ptrLagu pBantu) // tampilan menu lagu di luar playlist taro di header lagu
{
    ptrStack newLagu;
    int pilih;
    outputMenuLagu(pBantu);
    createNodeStackForOutsidePlaylist(newLagu, pBantu);
    pushSong(top, newLagu);
    while (pilih != 5)
    {

        cout << "\n1. next lagu\n"
             << "2. prev lagu\n"
             << "3. Masukan ke playlist\n"
             << "4. Undo\n"
             << "5. Stop\n"
             << "Masukan pilihan : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            if (pBantu->nextLagu != nullptr)
            {
                pBantu = pBantu->nextLagu;
                outputMenuLagu(pBantu);
                createNodeStackForOutsidePlaylist(newLagu, pBantu);
                pushSong(top, newLagu);
            }
            else
            {
                cout << "tidak ada lagu selanjutnya \n";
                outputMenuLagu(pBantu);
            }
            break;
        case 2:
            if (pBantu->prevLagu != nullptr)
            {
                pBantu = pBantu->prevLagu;
                createNodeStackForOutsidePlaylist(newLagu, pBantu);
                pushSong(top, newLagu);
                outputMenuLagu(pBantu);
            }
            else
            {
                cout << "tidak ada lagu sebelumnya \n";
                outputMenuLagu(pBantu);
            }
            break;
        case 3:
            int pilihPlaylist;
            ptrLaguPlaylist newLaguPlaylist;
            cout << "1. buat playlist baru" << endl;
            cout << "2. masukan playlist yang sudah ada" << endl;
            cout << "Masukan Pilihan : ";
            cin >> pilihPlaylist;
            if (pilihPlaylist == 1)
            {
                ptrPlaylist newPlaylist;
                createNodePlayList(newPlaylist);
                insertLastPlaylist(headPlaylist, newPlaylist);
                createElementLaguPlayList(newLaguPlaylist, pBantu);
                enqueue(newPlaylist, newLaguPlaylist);
                cout << "playlist berhasil dibuat";
            }
            else if (pilihPlaylist == 2)
            {
                int insertPlaylist;
                ptrPlaylist pBantuPlaylist;
                traversalPlaylist(headPlaylist);
                createElementLaguPlayList(newLaguPlaylist, pBantu);
                cout << "Masukan Playlist Ke Berapa ? ";
                cin >> insertPlaylist;
                pickPlaylistToInsert(headPlaylist, pBantuPlaylist, insertPlaylist);
                enqueue(pBantuPlaylist, newLaguPlaylist);
            }
            outputMenuLagu(pBantu);
            break;
        case 4:
            popSong(top);
            break;
        case 5:
            return;
            break;
        default:
            pilih = 5;
            break;
        }
    }
}

void traversalLagu(ptrAlbum pBantuAlbum) // menampilkan lagu dari album pertama dari artis tertentu taro di header lagu
{
    int no = 1;
    ptrLagu pBantu = pBantuAlbum->firstLagu;
    if (pBantu == nullptr)
    {
        cout << "kosong";
        return;
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->judulLagu << " ID " << pBantu->idLagu << endl;
            no++;
            pBantu = pBantu->nextLagu;
        }
    }
}
void traversalLaguFromAlbum(ptrAlbum pAlbum) // menampilkan lagu dari album tertentu diluar playlist taro di header
{
    int no = 1;
    ptrLagu pBantu = pAlbum->firstLagu;
    if (pBantu == nullptr)
    {
        cout << "kosong";
        return;
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->judulLagu << endl;
            no++;
            pBantu = pBantu->nextLagu;
        }
    }
}

void pickLaguFromAlbum(ptrAlbum pBantuAlbum, int pilihLagu) // memilih lagu dari album diluar playlist masukin ke header lagu
{
    ptrLagu pBantu = pBantuAlbum->firstLagu;
    while (pBantu != nullptr)
    {
        if (pilihLagu != 1)
        {
            pilihLagu--;
            pBantu = pBantu->nextLagu;
        }
        else if (pilihLagu == 1)
        {
            cout << "masuk menu lagu";
            menuLagu(pBantu);
            return;
        }
    }
}


bool searchLagu(ptrAlbum pCariAlbum, ptrLagu &pCariLagu, ptrLagu &pCariLaguPrev, const string key) // mencari lagu tertentu dengan id masukin ke header lagu
{
    pCariLagu = pCariAlbum->firstLagu;
    pCariLaguPrev = nullptr;
    bool found = false;
    while (!found && pCariLagu != nullptr)
    {
        if (pCariLagu->idLagu == key)
        {
            found = true;
        }
        else
        {
            pCariLaguPrev = pCariLagu;
            pCariLagu = pCariLagu->nextLagu;
        }
    }
    return found;
}

void traversalLaguByKey(first head, string key)
{
    ptrArtis pBantuArtis = head;
    int no = 1;
    bool found = false;
    while (pBantuArtis != nullptr)
    {
        ptrAlbum pBantuAlbum = pBantuArtis->firstAlbum;
        while (pBantuAlbum != nullptr)
        {
            ptrLagu pBantuLagu = pBantuAlbum->firstLagu;
            while (pBantuLagu != nullptr)
            {
                if (pBantuLagu->judulLagu == key)
                {
                    found = true;
                    cout << no << ". " << pBantuLagu->judulLagu << " by " << pBantuArtis->namaArtis << endl;
                    no++;
                    pBantuLagu = pBantuLagu->nextLagu;
                }
                else
                {
                    pBantuLagu = pBantuLagu->nextLagu;
                }
            }
            pBantuAlbum = pBantuAlbum->nextAlbum;
        }
        pBantuArtis = pBantuArtis->nextArtis;
    }
    if (found == false)
    {
        cout << "Tidak ditemukan lagu dengan judul tersebut" << endl;
    }
}

void pickLaguFromList(first head, string key, int pilihLagu) // memilih album dari banyaknya list album yang dicari
{
    ptrArtis pBantuArtis = head;
    while (pBantuArtis != nullptr)
    {
        ptrAlbum pBantuAlbum = pBantuArtis->firstAlbum;
        while (pBantuAlbum != nullptr)
        {
            ptrLagu pBantuLagu = pBantuAlbum->firstLagu;
            while (pBantuLagu != nullptr)
            {
                if (pBantuLagu->judulLagu == key)
                {
                    if (pilihLagu == 1)
                    {
                        menuLagu(pBantuLagu);
                    }
                    else
                    {
                        pilihLagu--;
                    }
                }
                pBantuLagu = pBantuLagu->nextLagu;
            }
            pBantuAlbum = pBantuAlbum->nextAlbum;
        }
        pBantuArtis = pBantuArtis->nextArtis;
    }
}

void traversalSearchLagu(first head, string key) // mencari lagu tertentu  masukin ke header lagu
{
    int pilihLagu;
    bool pilih = true;
    while (pilih == true)
    {
        traversalLaguByKey(head, key);
        cout << "Mau Pilih Lagu ke berapa? (0 untuk keluar)";
        cin >> pilihLagu;
        if (pilihLagu == 0)
        {
            pilih = false;
        }
        else
        {
            pickLaguFromList(head, key, pilihLagu);
        }
    }
}

void insertFirstLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum) // operasi insert first lagu masukin ke header lagu
{
    if (pCariAlbum->firstLagu == nullptr)
    {
        pCariAlbum->firstLagu = newLagu;
    }
    else
    {
        newLagu->nextLagu = pCariAlbum->firstLagu;
        pCariAlbum->firstLagu->prevLagu = newLagu;
        pCariAlbum->firstLagu = newLagu;
    }
    pCariAlbum->jumlahLagu++;
}

void insertLastLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum) // operasi insert last lagu masukin ke header lagu
{
    ptrLagu pBantu = pCariAlbum->firstLagu;

    if (pCariAlbum->firstLagu == nullptr)
    {
        pCariAlbum->firstLagu = newLagu;
    }
    else
    {
        while (pBantu->nextLagu != nullptr)
        {

            pBantu = pBantu->nextLagu;
        }
        pBantu->nextLagu = newLagu;
        newLagu->prevLagu = pBantu;
    }
    pCariAlbum->jumlahLagu++;
}

void deleteFirstLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus) // operasi delete first lagu masukin ke header lagu
{
    if (pCariAlbum == nullptr || pCariAlbum->firstLagu == nullptr)
    {
        cout << "Tidak ada lagu untuk dihapus" << endl;
    }
    else if (pCariAlbum->firstLagu->nextLagu == nullptr && pCariAlbum->firstLagu->prevLagu == nullptr)
    {
        pHapus = pCariAlbum->firstLagu;
    }
    else
    {
        pHapus = pCariAlbum->firstLagu;
        pCariAlbum->firstLagu = pCariAlbum->firstLagu->nextLagu;
        pHapus->nextLagu->prevLagu == nullptr;
        pHapus->nextLagu == nullptr;
    }
    pCariAlbum->jumlahLagu--;
}

void deleteLastLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus) // operasi delet last lagu masukin ke header lagu
{
    ptrLagu prevLagu = nullptr;
    pHapus = pCariAlbum->firstLagu;

    if (pCariAlbum == nullptr || pCariAlbum->firstLagu == nullptr)
    {
        cout << "Tidak ada lagu untuk dihapus" << endl;
    }
    while (pHapus->nextLagu != nullptr)
    {
        prevLagu = pHapus;
        pHapus = pHapus->nextLagu;
    }

    if (prevLagu == nullptr) // 1 data
    {
        pCariAlbum->firstLagu = nullptr;
    }
    else // banyak data
    {
        pHapus->prevLagu->nextLagu = nullptr;
        pHapus->prevLagu = nullptr;
    }

    pCariAlbum->jumlahLagu--;
}

void deletePcariLagu(ptrAlbum pCariAlbum, ptrLagu pCariLaguPrev, ptrLagu pCariLagu, first &head, ptrLagu &pHapus) // operasi menghapus lagu tertentu yang dicari masukin ke header lagu
{
    if (pCariLagu->nextLagu == nullptr && pCariLaguPrev != nullptr)
    {
        cout << "delete last";
        deleteLastLagu(pCariAlbum, pHapus);
    }
    else if (pCariLaguPrev == nullptr && pCariLagu->nextLagu != nullptr)
    {
        cout << "delete first";
        deleteFirstLagu(pCariAlbum, pHapus);
    }
    else if (pCariLaguPrev != nullptr && pCariLagu->nextLagu != nullptr)
    {
        cout << "masuk mas";
        pCariLaguPrev->nextLagu = pCariLagu->nextLagu;
        pCariLagu->nextLagu->prevLagu = pCariLaguPrev;
        pCariLagu->nextLagu = nullptr;
        pCariLagu->prevLagu = nullptr;
        pHapus = pCariLagu;
    }
}

void labelMenu() {
    cout << "============================================================================================" << endl;
    cout << left << setw(20) << "ARTIS" << "| " << setw(25) << "ALBUM" << "| " << setw(20) << "LAGU" << endl;
    cout << "============================================================================================" << endl;
    cout << left << setw(20) << "ID     Nama" << "| " << setw(25) << "ID   Judul Album" << "| " << setw(20) << "ID   Judul Lagu" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
}

void traversal(ptrArtis head) {
    ptrArtis pBantuArtis = head;
    ptrAlbum pBantuAlbum;
    ptrLagu pBantuLagu;

    if (head == nullptr) {
        cout << "List kosong" << endl;
    } else {
        labelMenu(); 

        while (pBantuArtis != nullptr) {
            bool artisDitampilkan = false; // buat mastiin artis cmn nampil sekali

            pBantuAlbum = pBantuArtis->firstAlbum;

            while (pBantuAlbum != nullptr) {
                bool albumDitampilkan = false; // buat mastiin album cmn nampil sekali

                pBantuLagu = pBantuAlbum->firstLagu;

                while (pBantuLagu != nullptr) {
                    if (!artisDitampilkan) {
                        cout << left << setw(20) << (pBantuArtis->idArtis + "   " + pBantuArtis->namaArtis);
                        artisDitampilkan = true;
                    } else {
                        cout << left << setw(20) << " ";
                    }

                    if (!albumDitampilkan) {
                        cout << "| " << left << setw(25) << (pBantuAlbum->idAlbum + "   " + pBantuAlbum->judulAlbum);
                        albumDitampilkan = true;
                    } else {
                        cout << "| " << left << setw(25) << " ";
                    }

                    cout << "| " << left << setw(30) << (pBantuLagu->idLagu + "   " + pBantuLagu->judulLagu 
                         + " (" + pBantuLagu->genre + ", " + to_string(pBantuLagu->durasi) + ")") << endl;

                    pBantuLagu = pBantuLagu->nextLagu;
                }

                if (!albumDitampilkan) {
                    if (!artisDitampilkan) {
                        cout << left << setw(20) << (pBantuArtis->idArtis + "   " + pBantuArtis->namaArtis);
                        artisDitampilkan = true;
                    } else {
                        cout << left << setw(20) << " ";
                    }

                    cout << "| " << left << setw(25) << (pBantuAlbum->idAlbum + "   " + pBantuAlbum->judulAlbum) << "| " << endl;
                }

                pBantuAlbum = pBantuAlbum->nextAlbum;
            }

            if (!artisDitampilkan) {
                cout << left << setw(20) << (pBantuArtis->idArtis + "   " + pBantuArtis->namaArtis) << "| " << "| " << endl;
            }
            cout <<"-----------------------------------------------------------------------------------------------"<< endl;
            pBantuArtis = pBantuArtis->nextArtis;
        }
    }
}