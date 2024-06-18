[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/TrJZcZ6X)
<p align="center">
  <h2 align="center">
    Program aplikasi pemutar lagu
  </h2>
</p>

<!-- Daftar Isi -->
<details open="open">
  <summary><h2 style="display: inline-block">Daftar Isi</h2></summary>
  <ol>
    <li><a href="#anggota-tim">Anggota Tim</a></li>
    <li><a href="#latar-belakang">Latar Belakang</a></li>
    <li><a href="#tujuan-dan-manfaat">Tujuan dan Manfaat</a></li>
    <li><a href="#penjelasan-aplikasi">Penjelasan Aplikasi</a></li>
    <li><a href="#gambar-rancangan-antarmuka">Gambar Rancangan Antarmuka</a></li>
    <li><a href="#rencana-pengerjaan-proyek">Rencana Pengerjaan Proyek</a></li>
    <li><a href="#lisensi">Lisensi</a></li>
  </ol>
</details>

<!-- Anggota Tim -->
## Anggota Tim
| NPM           | Name        |
| ------------- |-------------|
| 140810230027  | David       |
| 140810230071  | Dzikri      |
| 140810230081  | Luthfi      |

<!-- Latar Belakang -->
## Latar Belakang
Di era digital saat ini, kebutuhan akan akses musik yang cepat dan mudah semakin meningkat. Aplikasi streaming musik seperti Spotify telah merevolusi cara orang mendengarkan musik dengan menyediakan platform yang memungkinkan pengguna untuk menemukan, mendengarkan, dan mengelola musik mereka dengan mudah. Namun, tidak semua aplikasi yang ada saat ini memenuhi keinginan pengguna untuk personalisasi yang lebih dalam, seperti memilih penyanyi favorit dan membuat antrian lagu secara khusus. Oleh karena itu, proyek ini bertujuan untuk menciptakan sebuah aplikasi musik yang menggabungkan fitur-fitur tersebut, memberikan pengalaman mendengarkan musik yang lebih personal dan disesuaikan dengan preferensi pengguna.

<!-- Tujuan dan Manfaat -->
## Tujuan dan Manfaat
Tujuan:

- Mengembangkan sebuah aplikasi streaming musik yang memungkinkan pengguna untuk memasukkan penyanyi favorit mereka dan memilih lagu-lagu dari penyanyi tersebut.
- Menyediakan fitur antrian lagu yang memungkinkan pengguna untuk mengatur lagu-lagu yang ingin didengarkan sesuai dengan urutan pilihan mereka.
- Memberikan antarmuka yang intuitif dan mudah digunakan sehingga semua kalangan pengguna dapat menikmati aplikasi ini tanpa kesulitan.
  
Manfaat:

- Memberikan pengalaman mendengarkan musik yang lebih personal dan disesuaikan dengan selera musik masing-masing pengguna.
- Meningkatkan keterlibatan pengguna dengan aplikasi melalui fitur interaktif dan personalisasi.
- Menyediakan platform yang dapat mendukung berbagai macam genre dan artis, sehingga memperluas pilihan musik untuk pengguna.
- Mendorong penggunaan aplikasi secara berkelanjutan dengan menyediakan fitur-fitur yang memudahkan pengguna dalam menemukan dan mengatur musik mereka.


<!-- Penjelasan Aplikasi -->
## Penjelasan Aplikasi
Aplikasi ini akan memiliki beberapa fitur utama:

1. Multi-list Input untuk Artis, Album dan Lagu:

Pengguna dapat mencari dan memilih penyanyi yang mereka inginkan dari database yang tersedia.
Setelah memilih penyanyi, pengguna dapat melihat daftar Album dari penyanyi tersebut dan setelah memilih album , lagu lagu dari album yang dipilih akan di tampilkan dan pengguna dapat memilih beberapa lagu.
Pengguna dapat menambahkan Artis, album dan lagu-lagu, dari daftar tersebut ke dalam playlist mereka.

2. Queue dan Stack untuk Memutar Lagu:

Pengguna dapat membuat plalist lagu sesuai dengan pilihan lagu dari daftar lagu multi list tadi.
Lagu-lagu dalam playlist akan diputar satu per satu sesuai urutan yang ditentukan.
Pengguna dapat mengubah urutan lagu dalam antrian, menambahkan lagu baru, atau menghapus lagu yang sudah ada di dalam playlist.
Pengguna dapat memutar lagu yang didengar sebelumnya dengan prinsip stack.

3. Antarmuka Pengguna yang Intuitif:

Desain antarmuka yang ramah pengguna dengan navigasi yang mudah untuk mencari penyanyi, mencari album ,memilih lagu, dan mengatur playlist.

<!-- Gambar Rancangan Antarmuka -->
## Gambar Rancangan Antarmuka

### Menu Utama

**Tampilan Playlist User**

•	Pilih Playlist

**Database:**

•	Tambah Artis

•	Tambah Album dari Artis tertentu

•	Tambah Lagu dari Album Tertentu dari Artis Tertentu

•	Hapus Artis

•	Hapus Album dari Artis Tertentu

•	Hapus Lagu dari Album Tertentu dari Artis Tertentu

**Pencarian**

•	Nama Artis

•	Judul Album

•	Judul Lagu

•	Back (Kembali ke Menu Utama)

### Menu Database

Tambah Artis:

•	User menginput data artis baru.

•	Back (Kembali ke Menu Database)

Tambah Album:

•	User menginput data album baru dan mengaitkan dengan artis tertentu.

•	Back (Kembali ke Menu Database)

Tambah Lagu:

•	User menginput data lagu baru dan mengaitkan dengan album tertentu dan mengaitkan dengan artis tertentu.

•	Back (Kembali ke Menu Database)

Hapus Artis:

•	User memilih artis yang ingin dihapus (Searching).

•	Back (Kembali ke Menu Database)

Hapus Album dari Artis Tertentu :

•	User memilih artis dan kemudian memilih album yang ingin dihapus (Seach).

•	Back (Kembali ke Menu Database)

Hapus Lagu dari Album Tertentu:

•	User memilih artis, kemudian album, dan kemudian lagu yang ingin dihapus (Search).

•	Back (Kembali ke Menu Database)

### Menu Pencarian

User Memilih Opsi Pencarian:

•	Nama Artis

•	Judul Album

•	Judul Lagu

•	Back (Kembali ke Menu Utama)

**Pencarian Berdasarkan Nama Artis:**

•	User menginput nama artis yang dicari.

•	Sistem menampilkan daftar artis yang cocok dengan pencarian.

•	Back (Kembali ke Menu Pencarian)

1. Memilih Artis:

•	User memilih artis dari daftar yang muncul.

•	Sistem menampilkan semua album dari artis tersebut.

•	Back (Kembali ke Daftar Artis)

3. Memilih Album:

•	User memilih album dari daftar album yang ada.

•	Sistem menampilkan semua lagu dalam album tersebut.

•	Back (Kembali ke Daftar Album)

4. Memilih Lagu:

•	User memilih lagu dari daftar lagu dalam album tersebut.

•	Sistem menampilkan menu pemutar lagu.

•	Back (Kembali ke Daftar Lagu)

**Pencarian Berdasarkan Judul Album :**

User Menginput Judul Album:

•	Sistem menampilkan daftar album dari seluruh artis yang cocok dengan pencarian.

•	Back (Kembali ke Menu Pencarian)

Memilih Album:

•	User memilih album dari daftar yang muncul.

•	Sistem menampilkan semua lagu dalam album tersebut.

•	Back (Kembali ke Daftar Album)

Memilih Lagu:

•	User memilih lagu dari daftar lagu dalam album tersebut.

•	Sistem menampilkan menu pemutar lagu.

•	Back (Kembali ke Daftar Lagu)

**Pencarian Berdasarkan Judul Lagu :**

User Menginput Judul Lagu:

•	Sistem menampilkan daftar lagu dari seluruh artis dan album yang cocok dengan pencarian.

•	Back (Kembali ke Menu Pencarian)

Memilih Lagu :

•	User memilih lagu dari daftar yang muncul.

•	Sistem menampilkan menu pemutar lagu.

•	Back (Kembali ke Daftar Lagu)

•	Menu Playlist

### Menu Playlist

Memilih Playlist:

•	User memilih playlist dari daftar playlist.

•	Sistem menampilkan semua lagu dalam playlist tersebut.

•	Back (Kembali ke Menu Utama)

Memilih Lagu dalam Playlist:

•	User memilih lagu dari daftar lagu dalam playlist.

Opsi untuk:

•	Memutar lagu

•	Memutar semua lagu dalam urutan (queue)

•	Memutar semua lagu secara acak (random)

•	Menghapus lagu dari playlist

•	Back (Kembali ke Daftar Playlist)

### Menu Pemutar Lagu

•	Menampilkan durasi lagu

Opsi untuk:

Menambahkan lagu ke playlist

•	Membuat playlist baru

•	Menambahkan ke playlist yang sudah ada

•	Back (Kembali ke Daftar Lagu)

•	Previous (Memutar Lagu sebelumnya di list)

•	next (Memutar Lagu setelahnya di list)

•	undo (Memutar Lagu yang sebelumnya di putar) (Stack). 




<!-- Rencana Pengerjaan Proyek -->
## Rencana Pengerjaan Proyek

Proyek akhir ini akan dibagi menjadi tiga bagian :

1. Implementasi Multi List: Satu anggota tim akan bertanggung jawab untuk mengimplementasikan struktur data multi list. mencakup pembuatan dan pengelolaan data artis, album, dan lagu juga membuat fungsi fungsi multi list yang akan digunakan pada proyek ini.

2. Implementasi Queue & Stack: Anggota tim kedua dan ketiga akan fokus pada implementasi struktur data queue yang digunakan untuk memutar lagu. mencakup pengkodean algoritma untuk menambah lagu ke playlist, menghapus lagu dari playlist, dan fungsi-fungsi lain yang diperlukan untuk playlist pemutaran lagu membuat semua hal yang ada di menu pemutar musik dan playlist. 

3. Tampilan UI (User Interface): Anggota tim ketiga akan bertanggung jawab atas desain dan implementasi antarmuka pengguna. mencakup merancang fungsi mencetak ouput, form input untuk menambah data, tabel daftar data, serta kontrol untuk pemutaran lagu. (kalau sempat)

<!-- Lisensi -->
## Lisensi

MIT License 2024
