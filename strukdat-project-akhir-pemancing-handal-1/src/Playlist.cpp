#include "../include/Playlist.hpp"


void createPlayList(firstPlaylist &headPlaylist) // membuat playlist Baru taro di header playlist
{
    headPlaylist = nullptr;
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
        if (pilihPlaylist == 1)
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

void deleteLaguFromPlaylist(ptrLaguPlaylist &pBantuLaguPlaylist, ptrPlaylist &pBantuPlaylist)
{
    if (pBantuLaguPlaylist == nullptr)
        return;

    if (pBantuPlaylist->laguQueue.head == pBantuLaguPlaylist && pBantuPlaylist->laguQueue.tail == pBantuLaguPlaylist)
    {
        pBantuPlaylist->laguQueue.head = nullptr;
        pBantuPlaylist->laguQueue.tail = nullptr;
    }
    else if (pBantuLaguPlaylist == pBantuPlaylist->laguQueue.head)
    {
        pBantuPlaylist->laguQueue.head = pBantuLaguPlaylist->nextLagu;
        if (pBantuPlaylist->laguQueue.head != nullptr)
        {
            pBantuPlaylist->laguQueue.head->prevLagu = nullptr;
        }
    }
    else if (pBantuLaguPlaylist == pBantuPlaylist->laguQueue.tail)
    {
        pBantuPlaylist->laguQueue.tail = pBantuLaguPlaylist->prevLagu;
        if (pBantuPlaylist->laguQueue.tail != nullptr)
        {
            pBantuPlaylist->laguQueue.tail->nextLagu = nullptr;
        }
    }
    else
    {
        pBantuLaguPlaylist->prevLagu->nextLagu = pBantuLaguPlaylist->nextLagu;
        pBantuLaguPlaylist->nextLagu->prevLagu = pBantuLaguPlaylist->prevLagu;
    }

    pBantuLaguPlaylist->prevLagu = nullptr;
    pBantuLaguPlaylist->nextLagu = nullptr;
    return;
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
            pBantuPlaylist = pBantuPlaylist->next;
        }
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

void insertPlayList(firstPlaylist &head, ptrPlaylist newPlayList)
{ // operasi insert last playlist masukin ke header playlist
    ptrPlaylist pBantu = head;
    if (head == nullptr){
        head = newPlayList;
    }
    else{
        while (pBantu->next != nullptr)
        {
            pBantu = pBantu->next;
        }
        pBantu->next = newPlayList;
    }
}
