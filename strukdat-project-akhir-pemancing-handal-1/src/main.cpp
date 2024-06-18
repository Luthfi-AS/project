#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "../include/Album.hpp"
#include "../include/Lagu.hpp"
#include "../include/Artis.hpp"
#include "../include/Playlist.hpp"
#include "../include/Fileoperation.hpp"
#include "../include/Stack.hpp"
using namespace std;


void tabel() // untuk tabel menu pada awal program dijalankan
{
    for (int i = 0; i < 20; i++){
        cout << "=";
    }
    cout << endl;
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
    loadLagu(list);
    createPlayList(headPlaylist);
    loadPlaylist(headPlaylist);

    do
    {
        tabel();
        cout << "  MENU" << endl;
        tabel();
        cout << "1. Tambah Artis" << endl;
        cout << "2. Tambah Album" << endl;
        cout << "3. Tambah Lagu" << endl;
        cout << "4. Hapus Artis With ID" << endl;
        cout << "5. Hapus Album With ID" << endl;
        cout << "6. Hapus Lagu With ID" << endl;
        cout << "7. Search (User)" << endl;
        cout << "8. Hapus Artis" << endl;
        cout << "9. Hapus album" << endl;
        cout << "10. Hapus lagu" << endl;
        cout << "11. Menu Playlist" << endl;
        cout << "12. Tampilkan Data" << endl;
        cout << "13. Keluar" << endl;

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
                cout << "id artis tidak ditemukan" << endl;
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
                    cout << "id Album tidak ditemukan" << endl;
                }
            }
            else
            {
                cout << "id artis tidak ditemukan" << endl;
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
                    cout << "id Album tidak ditemukan" << endl;
                }
            }
            else
            {
                cout << "id artis tidak ditemukan" << endl;
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
        case 8:
            traversalArtis(list);
            cout << "Masukkan nomor artis yang ingin di hapus : ";
            int pilihArtis;
            cin >> pilihArtis;
            if (deleteArtisWithNumber(list, pCariArtisPrev, pCariArtis, pilihArtis))
            {
                deletePcariArtis(pCariArtis, pCariArtisPrev, list, pHapusArtis);
            }
            else
            {
                cout << "nomor artis tidak ditemukan" << endl;
            }

            break;
        case 9:
            traversalArtis(list);
            cout << "Masukkan nomor artis yang ingin di hapus : ";
            int pilihAlbum;
            cin >> pilihAlbum;
            if (deleteArtisWithNumber(list, pCariArtisPrev, pCariArtis, pilihAlbum))
            {
                traversalAlbum(pCariArtis);
                cout << "masukan nomor album yang ingin dihapus : ";
                cin >> pilihAlbum;
                if (deleteAlbumWithNumber(pCariArtis, pCariAlbumPrev, pCariAlbum, pilihAlbum))
                {
                    cout << "album ketemu" << endl;
                    deletePcariAlbum(pCariArtis, pCariAlbumPrev, pCariAlbum, list, pHapusAlbum);
                }
                else
                {
                    cout << "id Album tidak ditemukan" << endl;
                }
            }
            else
            {
                cout << "id artis tidak ditemukan" << endl;
            }
            break;
        case 10:
            traversalArtis(list);
            cout << "Masukkan nomor artis yang ingin di hapus : ";
            int pilihLagu;
            cin >> pilihLagu;
            if (deleteArtisWithNumber(list, pCariArtisPrev, pCariArtis, pilihLagu))
            {
                traversalAlbum(pCariArtis);
                cout << "masukan nomor album yang ingin dihapus : ";
                cin >> pilihLagu;
                if (deleteAlbumWithNumber(pCariArtis, pCariAlbumPrev, pCariAlbum, pilihLagu))
                {
                    traversalLagu(pCariAlbum);
                    cout << "masukan nomor lagu yang ingin dihapus : ";
                    cin >> pilihLagu;
                    if (deleteLaguWithNumber(pCariAlbum, pCariLaguPrev, pCariLagu, pilihLagu))
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
                    cout << "id Album tidak ditemukan" << endl;
                }
            }
            else
            {
                cout << "id artis tidak ditemukan" << endl;
            }
            break;
        case 11:
        {
            traversalPlaylist(headPlaylist);
            int InstruksiPlaylist = 0;
            cout << "pilih Playlist ke berapa (0 untuk back) : ";
            cin >> InstruksiPlaylist;
            pickPlaylistFromList(headPlaylist, InstruksiPlaylist);
            break;
        }
        case 12:
            traversal(list);
            break;
        case 13:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilih != 13);

    saveLagu(list);
    savePlaylist(headPlaylist);
    return 0;
}
