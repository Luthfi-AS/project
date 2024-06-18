#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Lagu
{
    string idLagu;
    string judulLagu;
    string genre;
    int durasi;
    Lagu *nextLagu;
    Lagu *prevLagu;
};

struct Album
{
    string idalbum;
    string judulAlbum;
    int jumlahLagu;
    Lagu *firstLagu;
    Album *nextAlbum;
};

struct Artis
{
    string idArtis;
    string namaArtis;
    int jumlahAlbum;
    Album *firstAlbum;
    Artis *nextArtis;
};

struct LaguPlaylist
{
    string judulLagu;
    string genre;
    int durasi;
    LaguPlaylist *nextLagu;
    LaguPlaylist *prevLagu;
};

typedef LaguPlaylist *ptrLaguPlaylist;

struct Queue
{
    ptrLaguPlaylist head;
    ptrLaguPlaylist tail;
};

struct playlist
{
    string namaPlaylist;
    string jumlahLagu;
    playlist *next;
    Queue laguQueue;
};

struct historyLagu
{
    string judulLagu;
    string genre;
    int durasi;
};

struct stackHistoryOutPlaylist
{
    historyLagu lagu;
    stackHistoryOutPlaylist *nextLagu;
    stackHistoryOutPlaylist *prevLagu;
};

struct stackHistoryInPlaylist
{
    historyLagu lagu;
    stackHistoryInPlaylist *nextLagu;
    stackHistoryInPlaylist *prevLagu;
};

typedef stackHistoryOutPlaylist *ptrStack;
typedef stackHistoryInPlaylist *ptrStackS;
typedef ptrStack topStack;
typedef ptrStackS topStackS;
typedef Lagu *ptrLagu;
typedef Album *ptrAlbum;
typedef Artis *ptrArtis;
typedef playlist *ptrPlaylist;
typedef ptrArtis first;
typedef ptrPlaylist firstPlaylist;

firstPlaylist headPlaylist;
topStack top;
topStackS topS;

void peek(topStack top)
{
    cout << "Playing : " << top->lagu.judulLagu << " " << top->lagu.durasi << endl;
}

void peekS(topStackS topS)
{
    cout << "Playing : " << topS->lagu.judulLagu << " " << topS->lagu.durasi << endl;
}

void pushSong(topStack &top, ptrStack &newLagu)
{
    if (top == nullptr)
    {
        top = newLagu;
    }
    else
    {
        top->nextLagu = newLagu;
        newLagu->prevLagu = top;
        top = newLagu;
    }
}

void pushSongS(topStackS &topS, ptrStackS &newLagu)
{
    if (topS == nullptr)
    {
        topS = newLagu;
    }
    else
    {
        topS->nextLagu = newLagu;
        newLagu->prevLagu = topS;
        topS = newLagu;
    }
}

void popSongS(topStackS &topS)
{
    if (topS == nullptr)
    {
        cout << "History Kosong" << endl;
    }
    else if (topS->prevLagu == nullptr)
    {
        // Hanya ada satu elemen di stack
        cout << "Tidak ada lagu sebelumnya yang diputar" << endl;
        peekS(topS); // Menampilkan elemen tersebut tanpa mempop
    }
    else
    {
        // Ada lebih dari satu elemen di stack
        topStackS temp = topS;
        topS = topS->prevLagu;
        topS->nextLagu = nullptr;
        peekS(topS); // Menampilkan elemen baru di puncak stack
    }
}

void popSong(topStack &top)
{
    if (top == nullptr)
    {
        cout << "History Kosong" << endl;
    }
    else if (top->prevLagu == nullptr)
    {
        // Hanya ada satu elemen di stack
        cout << "Tidak ada lagu sebelumnya yang diputar" << endl;
        peek(top); // Menampilkan elemen tersebut tanpa mempop
    }
    else
    {
        // Ada lebih dari satu elemen di stack
        topStack temp = top;
        top = top->prevLagu;
        top->nextLagu = nullptr;
        peek(top); // Menampilkan elemen baru di puncak stack
    }
}

void tabel() // untuk tabel menu pada awal program dijalankan
{
    for (int i = 0; i < 20; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void createDataList(first &list) // V membuat list baru untuk artis taro di header artis
{
    list = nullptr;
}

void createPlayList(firstPlaylist &headPlaylist) // V membuat playlist Baru taro di header playlist
{
    headPlaylist = nullptr;
}

void createStack(topStack &top) 
{
    top = nullptr;
}

void createQueue(Queue &Q)
{ // membuat queue baru untuk di dalam playlist taro di header playlist
    Q.head = nullptr;
    Q.tail = nullptr;
}

void createNodePlayList(ptrPlaylist &newPlaylist) // membuat node playlist baru taro di header playlist
{
    newPlaylist = new playlist;
    newPlaylist->next = nullptr;
    createQueue(newPlaylist->laguQueue);
    cout << "masukan nama playlist : ";
    cin >> newPlaylist->namaPlaylist;
}

void createNodeStackForOutsidePlaylist(ptrStack &newHistory, ptrLagu pBantuLagu)
{
    newHistory = new stackHistoryOutPlaylist;
    newHistory->lagu.judulLagu = pBantuLagu->judulLagu;
    newHistory->lagu.durasi = pBantuLagu->durasi;
    newHistory->lagu.genre = pBantuLagu->genre;
    newHistory->nextLagu = nullptr;
}

void createNodeStackForInsidePlaylist(ptrStackS &newHistory, ptrLaguPlaylist pBantuLagu)
{
    newHistory = new stackHistoryInPlaylist;
    newHistory->lagu.judulLagu = pBantuLagu->judulLagu;
    newHistory->lagu.durasi = pBantuLagu->durasi;
    newHistory->lagu.genre = pBantuLagu->genre;
    newHistory->nextLagu = nullptr;
}

void createElementLaguPlayList(ptrLaguPlaylist &newLaguPlaylist, ptrLagu pBantu) // membuat node lagu baru dalam playlist
{
    newLaguPlaylist = new LaguPlaylist;
    newLaguPlaylist->nextLagu = nullptr;
    newLaguPlaylist->judulLagu = pBantu->judulLagu;
    newLaguPlaylist->genre = pBantu->genre;
    newLaguPlaylist->durasi = pBantu->durasi;
}

void traversalPlaylist(firstPlaylist headPlaylist)
{ // menampilkan semua playlist yang dimiliki user simpen di playlist
    ptrPlaylist pBantu = headPlaylist;
    int no = 1;
    if (pBantu == nullptr)
    {
        cout << "tidak ada playlist" << endl;
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->namaPlaylist << endl;
            no++;
            pBantu = pBantu->next;
        }
    }
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

void createAlbum(ptrAlbum &newAlbum) // membuat node album baru taro di header album
{
    newAlbum = new Album;
    cout << "Masukkan id album: ";
    cin >> newAlbum->idalbum;
    cout << "Masukkan judul album: ";
    cin >> newAlbum->judulAlbum;
    newAlbum->nextAlbum = nullptr;
    newAlbum->firstLagu = nullptr;
}

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

void insertFirstPlaylist(firstPlaylist &headPlaylist, ptrPlaylist &newPlaylist)
{
    if (headPlaylist == nullptr)
    {
        headPlaylist = newPlaylist;
    }
    else
    {
        newPlaylist->next = headPlaylist;
        headPlaylist = newPlaylist;
    }
}

void insertLastPlaylist(firstPlaylist &headPlaylist, ptrPlaylist &newPlaylist)
{
    ptrPlaylist pBantu = headPlaylist;
    if (headPlaylist == nullptr)
    {
        insertFirstPlaylist(headPlaylist, newPlaylist);
    }
    else
    {
        while (pBantu->next != nullptr)
        {
            pBantu = pBantu->next;
        }
        pBantu->next = newPlaylist;
    }
}

void enqueue(ptrPlaylist &pBantuPlaylist, ptrLaguPlaylist &newSong) // memasukkan lagu ke dalam playlist taro di header playlist
{
    if (pBantuPlaylist->laguQueue.head == nullptr && pBantuPlaylist->laguQueue.tail == nullptr)
    {
        pBantuPlaylist->laguQueue.head = newSong;
        pBantuPlaylist->laguQueue.tail = newSong;
    }
    else if (pBantuPlaylist->laguQueue.head == pBantuPlaylist->laguQueue.tail || pBantuPlaylist->laguQueue.head != nullptr)
    {
        pBantuPlaylist->laguQueue.tail->nextLagu = newSong;
        newSong->prevLagu = pBantuPlaylist->laguQueue.tail;
        pBantuPlaylist->laguQueue.tail = newSong;
    }
}

void dequeue(ptrPlaylist &pPlaylist, ptrLaguPlaylist &playedSong) // menghapus lagu dalam playlist taro di header playlist
{
    if (pPlaylist->laguQueue.head == nullptr && pPlaylist->laguQueue.tail == nullptr)
    {
        cout << "Playlistmu kosong";
    }
    else if (pPlaylist->laguQueue.head->nextLagu == nullptr)
    {
        playedSong = pPlaylist->laguQueue.head;
        pPlaylist->laguQueue.head = nullptr;
    }
    else
    {
        playedSong = pPlaylist->laguQueue.head;
        pPlaylist->laguQueue.head = pPlaylist->laguQueue.head->nextLagu;
        pPlaylist->laguQueue.head->prevLagu = nullptr;
        playedSong->nextLagu = nullptr;
    }
}

void pickPlaylistToInsert(firstPlaylist headPlaylist, ptrPlaylist &pBantuPlaylist, int pilihPlaylist)
{
    pBantuPlaylist = headPlaylist;
    while (pBantuPlaylist != nullptr)
    {
        if (pilihPlaylist = 1)
        {
            return;
        }
        else
        {
            pBantuPlaylist = pBantuPlaylist->next;
            pilihPlaylist--;
        }
    }
}

void outputMenuLaguDalamPLaylist(ptrLaguPlaylist pBantuLaguPlaylist) // menampilkan judul genre dan durasi dari lagu yang dipilih di dalam playlist taro di header playlist
{
    cout << "\njudul lagu : ";
    cout << pBantuLaguPlaylist->judulLagu;
    cout << "\ngenre lagu : ";
    cout << pBantuLaguPlaylist->genre;
    cout << "\ndurasi lagu : ";
    cout << pBantuLaguPlaylist->durasi;
}

void outputMenuLagu(ptrLagu pBantu) // menampilkan lagu yang di pilih di luar playlist taro di header lagu
{
    cout << "\njudul lagu : ";
    cout << pBantu->judulLagu;
    cout << "\ngenre lagu : ";
    cout << pBantu->genre;
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
void deleteLaguFromPlaylist(ptrLaguPlaylist &pBantuLaguPlaylist, ptrPlaylist &pBantuPlaylist)
{
    if (pBantuLaguPlaylist->prevLagu == nullptr)
    {
        pBantuPlaylist->laguQueue.head = pBantuPlaylist->laguQueue.head->nextLagu;
        pBantuPlaylist->laguQueue.head->prevLagu->nextLagu = nullptr;
        pBantuPlaylist->laguQueue.head->prevLagu = nullptr;
    }
    else if (pBantuLaguPlaylist->prevLagu != nullptr && pBantuLaguPlaylist->nextLagu == nullptr)
    {
        pBantuPlaylist->laguQueue.tail = pBantuLaguPlaylist->prevLagu;
        pBantuLaguPlaylist->prevLagu->nextLagu = nullptr;
        pBantuLaguPlaylist->prevLagu = nullptr;
    }
    else
    {
        pBantuLaguPlaylist->prevLagu->nextLagu = pBantuLaguPlaylist->nextLagu;
        pBantuLaguPlaylist->nextLagu->prevLagu = pBantuLaguPlaylist->prevLagu;
        pBantuLaguPlaylist->prevLagu = nullptr;
        pBantuLaguPlaylist->nextLagu = nullptr;
    }
}

void menuLaguDalamPlaylist(ptrPlaylist pBantuPlaylist, ptrLaguPlaylist pBantuLaguDalamPlaylist) // tampilan menu lagu di dalam playlist taro di header playllist (new)
{
    int pilih;
    ptrStackS newLagu;
    outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
    createNodeStackForInsidePlaylist(newLagu, pBantuLaguDalamPlaylist);
    pushSongS(topS, newLagu);
    while (pilih != 5)
    {

        cout << "\n1. next lagu\n"
             << "2. prev lagu\n"
             << "3. Hapus dari playlist\n"
             << "4. Undo\n"
             << "5. Stop\n"
             << "Masukan pilihan : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            if (pBantuLaguDalamPlaylist->nextLagu != nullptr)
            {
                pBantuLaguDalamPlaylist = pBantuLaguDalamPlaylist->nextLagu;
                outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
                createNodeStackForInsidePlaylist(newLagu, pBantuLaguDalamPlaylist);
                pushSongS(topS, newLagu);
            }
            else
            {
                cout << "tidak ada lagu selanjutnya \n";
                outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
            }
            break;
        case 2:
            if (pBantuLaguDalamPlaylist->prevLagu != nullptr)
            {
                pBantuLaguDalamPlaylist = pBantuLaguDalamPlaylist->prevLagu;
                createNodeStackForInsidePlaylist(newLagu, pBantuLaguDalamPlaylist);
                pushSongS(topS, newLagu);
                outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
            }
            else
            {
                cout << "tidak ada lagu sebelumnya \n";
                outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
            }
            break;
        case 3:
            deleteLaguFromPlaylist(pBantuLaguDalamPlaylist, pBantuPlaylist);
            cout << "Lagu dihapus dari playlist" << endl;
            return;
            break;
        case 4:
            popSongS(topS);
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
            cout << no << ". " << pBantu->judulAlbum << " ID " << pBantu->idalbum << endl;
            no++;
            pBantu = pBantu->nextAlbum;
        }
    }
}

void traversalLaguDalamPlaylist(ptrPlaylist pBantuPlaylist)
{ // menampilkan semua lagu dalam playlist yang sudah dipilih taro di header playlist
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;
    int no = 1;
    if (pBantuPlaylist->laguQueue.head == nullptr)
    {
        cout << "Playlist Kosong, Coba masukan lagu ke dalam playlist" << endl;
    }
    else
    {
        while (pBantuLaguPlaylist != nullptr)
        {
            cout << no << ". " << pBantuLaguPlaylist->judulLagu << endl;
            no++;
            pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
        }
    }
}

void playingByQueueInPlaylist(ptrPlaylist pBantuPlaylist)
{
    ptrStackS newLagu;
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;
    if (pBantuPlaylist->laguQueue.head == nullptr)
    {
        cout << "Queue Kosong, Coba masukan lagu ke dalam playlist" << endl;
    }
    else
    {
        while (pBantuLaguPlaylist != nullptr)
        {
            cout << "Playing :  " << pBantuLaguPlaylist->judulLagu << endl;
            createNodeStackForInsidePlaylist(newLagu, pBantuLaguPlaylist);
            pushSongS(topS, newLagu);
            pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
        }
        cout << "Anda mencapai lagu terakhir" << endl;
        char pilih;
        cout << "Masukan I untuk keluar : ";
        cin >> pilih;
        if (pilih == 'I' || pilih == 'i')
        {
            return;
        }
        else
        {
            cout << "Kalo ga keluar mau ngapain?";
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

void pickLaguFromPlaylist(ptrPlaylist pBantuPlaylist, int pilihLagu)
{
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;
    while (pBantuLaguPlaylist != nullptr)
    {
        if (pilihLagu != 1)
        {
            pilihLagu--;
            pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
        }
        else if (pilihLagu == 1)
        {
            cout << "masuk menu lagu";
            menuLaguDalamPlaylist(pBantuPlaylist, pBantuLaguPlaylist);
            return;
        }
    }
}

void pickRandomLaguFromPlaylist(ptrPlaylist pBantuPlaylist)
{
    int jumlahLagu = 0;
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;

    while (pBantuLaguPlaylist != nullptr)
    {
        jumlahLagu += 1;
        pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
    }

    if (jumlahLagu > 0)
    {
        int pilihLagu = rand() % jumlahLagu;
        pickLaguFromPlaylist(pBantuPlaylist, pilihLagu);
    }
}

void pickPlaylistFromList(firstPlaylist headPlaylist, int pilihPlaylist)
{ // memilih playlist yang ingin ditampilkan lagunya
    ptrPlaylist pBantuPlaylist = headPlaylist;
    while (pBantuPlaylist != nullptr)
    {
        if (pilihPlaylist == 1)
        {
            cout << "Masukan 'X' untuk putar berdasarkan queue" << endl;
            cout << "masukan 'O' untuk putar secara acak" << endl;
            cout << "masukan 'F' untuk back" << endl;
            cout << "Masukan angka lagu jika ingin memutar lagu tertentu" << endl;

            traversalLaguDalamPlaylist(pBantuPlaylist);
            cout << "Masukan : ";
            string input;
            cin >> input;

            if (input == "X" || input == "x")
            {
                playingByQueueInPlaylist(pBantuPlaylist);
            }
            else if (input == "O" || input == "o")
            {
                pickRandomLaguFromPlaylist(pBantuPlaylist);
            }
            else if (input == "F" || input == "f")
            {
                return;
            }
            else
            {
                int pilihLagu = stoi(input);
                pickLaguFromPlaylist(pBantuPlaylist, pilihLagu);
            }
        }
        else
        {
            pilihPlaylist--;
        }
        pBantuPlaylist = pBantuPlaylist->next;
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

void putarLaguBerdasarkanQueuePlaylist(ptrPlaylist pBantuPlaylist)
{ // memutar seluruh lagu yang ada di playlist tertentu masukin ke header playlist
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;
    while (pBantuLaguPlaylist != nullptr)
    {
        cout << pBantuLaguPlaylist->judulLagu << endl;
        cout << pBantuLaguPlaylist->durasi << endl;
        pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
    }
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

bool searchAlbuminArtis(ptrArtis pCariArtis, ptrAlbum &pCariAlbum, ptrAlbum &pCariAlbumPrev, const string key) // mencari album dari artis tertentu masukin ke header album
{
    pCariAlbum = pCariArtis->firstAlbum;
    pCariAlbumPrev = nullptr;
    bool found = false;
    while (pCariAlbum != nullptr && found == false)
    {
        if (pCariAlbum->idalbum == key)
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

void traversal(first head) // operasi traversal semua artis dengan album dan lagunya bebas simpen dmn
{
    ptrArtis pBantuArtis = head;
    ptrAlbum pBantuAlbum;
    ptrLagu pBantuLagu;
    if (head == nullptr)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        while (pBantuArtis != nullptr)
        {

            cout << "Artis: " << pBantuArtis->idArtis << "    " << pBantuArtis->namaArtis << endl;
            pBantuAlbum = pBantuArtis->firstAlbum;
            while (pBantuAlbum != nullptr)
            {
                cout << "  Album: " << pBantuAlbum->idalbum << "    " << pBantuAlbum->judulAlbum << endl;
                pBantuLagu = pBantuAlbum->firstLagu;
                while (pBantuLagu != nullptr)
                {
                    cout << "    id: " << pBantuLagu->idLagu << "    Lagu: " << pBantuLagu->judulLagu << ", Genre: " << pBantuLagu->genre << ", Durasi: " << pBantuLagu->durasi << endl;
                    pBantuLagu = pBantuLagu->nextLagu;
                }
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
            pBantuArtis = pBantuArtis->nextArtis;
        }
    }
}

void loadplaylist()
{
    ptrPlaylist pBantuPlaylist;
    ifstream file("playlist.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    string line;

    while (getline(file, line))
    {
        if (line == "Lagu:")
        {
            ptrLaguPlaylist newLagu = new LaguPlaylist;
            getline(file, newLagu->judulLagu);
            file.ignore();
            newLagu->nextLagu = nullptr;
            newLagu->prevLagu = nullptr;

            enqueue(pBantuPlaylist, newLagu);
        }
    }

    file.close();
}

void save(ptrArtis head)
{
    ofstream file("data.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }

    ptrArtis currentArtis = head;
    while (currentArtis != nullptr)
    {
        file << "Artis:" << endl;
        file << currentArtis->idArtis << endl;
        file << currentArtis->namaArtis << endl;
        file << currentArtis->jumlahAlbum << endl;

        ptrAlbum currentAlbum = currentArtis->firstAlbum;
        while (currentAlbum != nullptr)
        {
            file << "Album:" << endl;
            file << currentAlbum->idalbum << endl;
            file << currentAlbum->judulAlbum << endl;
            file << currentAlbum->jumlahLagu << endl;

            ptrLagu currentLagu = currentAlbum->firstLagu;
            while (currentLagu != nullptr)
            {
                file << "Lagu:" << endl;
                file << currentLagu->idLagu << endl;
                file << currentLagu->judulLagu << endl;
                file << currentLagu->genre << endl;
                file << currentLagu->durasi << endl;
                currentLagu = currentLagu->nextLagu;
            }
            currentAlbum = currentAlbum->nextAlbum;
        }
        currentArtis = currentArtis->nextArtis;
    }

    file.close();
}
void load(ptrArtis &pBantu)
{
    ifstream file("data.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    string line;
    pBantu = nullptr;
    ptrArtis currentArtis = nullptr;
    ptrAlbum currentAlbum = nullptr;

    while (getline(file, line))
    {
        if (line == "Artis:")
        {
            ptrArtis newArtis = new Artis;
            getline(file, newArtis->idArtis);
            getline(file, newArtis->namaArtis);
            file >> newArtis->jumlahAlbum;
            file.ignore();
            newArtis->nextArtis = nullptr;
            newArtis->firstAlbum = nullptr;

            insertLastArtis(newArtis, pBantu);
            currentArtis = newArtis;
            currentAlbum = nullptr;
        }
        else if (line == "Album:")
        {
            ptrAlbum newAlbum = new Album;
            getline(file, newAlbum->idalbum);
            getline(file, newAlbum->judulAlbum);
            file >> newAlbum->jumlahLagu;
            file.ignore();
            newAlbum->nextAlbum = nullptr;
            newAlbum->firstLagu = nullptr;

            insertLastAlbum(newAlbum, currentArtis);
            currentAlbum = newAlbum;
        }
        else if (line == "Lagu:")
        {
            ptrLagu newLagu = new Lagu;
            getline(file, newLagu->idLagu);
            getline(file, newLagu->judulLagu);
            getline(file, newLagu->genre);
            file >> newLagu->durasi;
            file.ignore();
            newLagu->nextLagu = nullptr;
            newLagu->prevLagu = nullptr;

            insertLastLagu(newLagu, currentAlbum);
        }
    }

    file.close();
}

int main()
{
    first list;
    ptrArtis pArtis, pCariArtis, pCariArtisPrev, pHapusArtis;
    ptrAlbum pAlbum, pCariAlbum, pCariAlbumPrev, pHapusAlbum;
    ptrLagu pLagu, pCariLagu, pCariLaguPrev, pHapusLagu;
    int pilih;
    string key, key2;
    createStack(top);
    createDataList(list);
    load(list);
    createPlayList(headPlaylist);

    do
    {
        tabel();
        cout << "  MENU" << endl;
        tabel();
        cout << "1. Tambah Artis" << endl;
        cout << "2. Tambah Album" << endl;
        cout << "3. Tambah Lagu" << endl;
        cout << "4. Hapus Artis" << endl;
        cout << "5. Hapus Album" << endl;
        cout << "6. Hapus Lagu" << endl;
        cout << "7. Search (User)" << endl;
        cout << "9. Menu Playlist" << endl;
        cout << "10. Tampilkan Data" << endl;
        cout << "11. Keluar" << endl;
        tabel();
        cout << "Pilih menu: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            createArtis(pArtis);
            insertLastArtis(pArtis, list);
            break;
        case 2:
            if (list == nullptr)
            {
                cout << "List kosong, tambahkan artis terlebih dahulu." << endl;
            }
            else
            {
                cout << "Masukkan id artis: ";
                cin.ignore();
                getline(cin, key);
                if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
                {
                    createAlbum(pAlbum);
                    insertLastAlbum(pAlbum, pCariArtis);
                }
                else
                {
                    cout << "Artis tidak ditemukan." << endl;
                }
            }
            break;
        case 3:
            if (list == nullptr)
            {
                cout << "List kosong, tambahkan artis terlebih dahulu." << endl;
            }
            else
            {
                cout << "Masukkan id artis: ";
                cin >> key;
                if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
                {
                    cout << "Masukkan id album: ";
                    cin >> key;
                    if (searchAlbuminArtis(pCariArtis, pCariAlbum, pCariAlbumPrev, key))
                    {
                        createLagu(pLagu);
                        insertLastLagu(pLagu, pCariAlbum);
                    }
                    else
                    {
                        cout << "Album tidak ditemukan." << endl;
                    }
                }
                else
                {
                    cout << "Artis tidak ditemukan." << endl;
                }
            }
            break;
        case 4:
            traversalArtis(list);
            cout << "Masukkan id artis yang ingin di hapus : ";
            cin >> key;
            if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
            {
                deletePcariArtis(pCariArtis, pCariArtisPrev, list, pHapusArtis);
            }
            else
            {
                cout << "id artis tidak ditemukan";
            }

            break;
        case 5:
            traversalArtis(list);
            cout << "Masukkan id Artis dari album yang ingin di hapus : ";
            cin >> key;
            if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
            {
                traversalAlbum(pCariArtis);
                cout << "masukan id album yang ingin dihapus : ";
                cin >> key;
                if (searchAlbuminArtis(pCariArtis, pCariAlbum, pCariAlbumPrev, key))
                {
                    cout << "album ketemu" << endl;
                    deletePcariAlbum(pCariArtis, pCariAlbumPrev, pCariAlbum, list, pHapusAlbum);
                }
                else
                {
                    cout << "id Album tidak ditemukan";
                }
            }
            else
            {
                cout << "id artis tidak ditemukan";
            }
            break;
        case 6:
            traversalArtis(list);
            cout << "Masukkan id Artis dari lagu yang ingin di hapus : ";
            cin >> key;
            if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
            {
                traversalAlbum(pCariArtis);
                cout << "masukan id album dari lagu yang ingin dihapus : ";
                cin >> key;
                if (searchAlbuminArtis(pCariArtis, pCariAlbum, pCariAlbumPrev, key))
                {
                    traversalLagu(pCariAlbum);
                    cout << "Masukan id lagu yang ingin di hapus: ";
                    cin >> key;
                    if (searchLagu(pCariAlbum, pCariLagu, pCariLaguPrev, key))
                    {
                        cout << "lagu ketemu" << endl;
                        deletePcariLagu(pCariAlbum, pCariLaguPrev, pCariLagu, list, pHapusLagu);
                    }
                    else
                    {
                        cout << "lagu tidak ditemukan" << endl;
                    }
                }
                else
                {
                    cout << "id Album tidak ditemukan";
                }
            }
            else
            {
                cout << "id artis tidak ditemukan";
            }
            break;
        case 7:
        {
            int pilihSearch = 0;
            while (pilihSearch != 4)
            {
                cout << "1. Search Artis\n"
                     << "2. Search Album\n"
                     << "3. Search Lagu\n"
                     << "4. Back\n"
                     << "Masukan Pilihan: ";
                cin >> pilihSearch;
                switch (pilihSearch)
                {
                case 1:
                    cout << "Masukkan nama artis: ";
                    cin >> key;
                    fungsiMemilihArtis(list, key);
                    break;
                case 2:
                    cout << "Masukkan nama album: ";
                    cin >> key;
                    fungsiMemilihAlbum(list, key);
                    break;
                case 3:
                    cout << "Masukkan nama lagu: ";
                    cin >> key;
                    traversalSearchLagu(list, key);
                    break;
                case 4:
                    // Exit search menu
                    break;
                default:
                    cout << "Pilihan tidak valid, coba lagi." << endl;
                    pilihSearch = 4;
                    break;
                }
            }
            break;
        }
        case 9:
        {
            traversalPlaylist(headPlaylist);
            int InstruksiPlaylist = 0;
            cout << "pilih Playlist ke berapa (0 untuk back) : ";
            cin >> InstruksiPlaylist;
            pickPlaylistFromList(headPlaylist, InstruksiPlaylist);
            break;
        }
        case 10:
            traversal(list);
            break;
        case 11:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilih != 11);

    save(list);

    return 0;
}
