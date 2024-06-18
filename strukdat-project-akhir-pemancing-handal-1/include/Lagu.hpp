#ifndef LAGU_HPP
#define LAGU_HPP

#include "Album.hpp"
#include "Fileoperation.hpp"
#include "Stack.hpp"
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

struct historyLagu;
struct stackHistoryOutPlaylist;
struct stackHistoryInPlaylist;
typedef stackHistoryOutPlaylist *ptrStack;
typedef stackHistoryInPlaylist *ptrStackS;
typedef ptrStack topStack;
typedef ptrStackS topStackS;

typedef Lagu *ptrLagu;

void createLagu(ptrLagu &newLagu);            // membuat node lagu baru taro di header lagu
void outputMenuLagu(ptrLagu pBantu);          // menampilkan lagu yang di pilih di luar playlist taro di header lagu
void menuLagu(ptrLagu pBantu);                // tampilan menu lagu di luar playlist taro di header lagu
void traversalLagu(ptrAlbum pBantuAlbum);     // menampilkan lagu dari album pertama dari artis tertentu taro di header lagu
void traversalLaguFromAlbum(ptrAlbum pAlbum); // menampilkan lagu dari album tertentu diluar playlist taro di header
bool deleteLaguWithNumber(ptrAlbum pBantuAlbum, ptrLagu &ptrLaguPrev, ptrLagu &ptrLagu, int pilihLagu);
void pickLaguFromAlbum(ptrAlbum pBantuAlbum, int pilihLagu);                                        // memilih lagu dari album diluar playlist masukin ke header lagu
bool searchLagu(ptrAlbum pCariAlbum, ptrLagu &pCariLagu, ptrLagu &pCariLaguPrev, const string key); // mencari lagu tertentu dengan id masukin ke header lagu
void traversalLaguByKey(first head, string key);
void pickLaguFromList(first head, string key, int pilihLagu);                                                      // memilih album dari banyaknya list album yang dicari
void traversalSearchLagu(first head, string key);                                                                  // mencari lagu tertentu  masukin ke header lagu
void insertFirstLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum);                                                       // operasi insert first lagu masukin ke header lagu
void insertLastLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum);                                                        // operasi insert last lagu masukin ke header lagu
void deleteFirstLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus);                                                        // operasi delete first lagu masukin ke header
void deleteLastLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus);                                                         // operasi delet last lagu masukin ke header lagu
void deletePcariLagu(ptrAlbum pCariAlbum, ptrLagu pCariLaguPrev, ptrLagu pCariLagu, first &head, ptrLagu &pHapus); // operasi menghapus lagu tertentu yang dicari masukin ke header lagu
void traversal(first head);                                                                                        // operasi traversal semua artis dengan album dan lagunya bebas simpen dmn

#endif // LAGU_H
