#include "../include/Stack.hpp"

topStack top = nullptr;
topStackS topS = nullptr;
firstPlaylist headPlaylist = nullptr;

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

void createStack(topStack &top)
{
    top = nullptr;
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
