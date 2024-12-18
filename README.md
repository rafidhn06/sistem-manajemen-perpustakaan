# Demo
![demo](https://github.com/user-attachments/assets/3e69a1eb-a818-489f-8583-6b994a0c00aa)
# Dependensi
Program ini dapat dijalankan di komputer, dengan syarat komputer tersebut menggunakan Windows sebagai sistem operasinya. Panduan ini dibuat dengan asumsi bahwa syarat tersebut telah terpenuhi.  
\
\
Instalasi program memerlukan Git. Untuk mengecek apakah Git sudah terinstal, command berikut dapat dijalankan di terminal.

```bash
git --version
```

Jika terminal menampilkan pesan galat, command berikut dapat dijalankan kemudian.

```bash
winget install -e --id Git.Git
```  
\
Instalasi program juga memerlukan kompilator G++. Untuk mengecek apakah G++ sudah terinstal, command berikut dapat dijalankan di terminal.

```bash      
g++ --version
```

Jika terminal menampilkan pesan galat, pembaca dapat menuju ke [__halaman__](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain) ini terlebih dahulu.
# Instalasi
Untuk menginstal program, command berikut dapat dijalankan di terminal.

```bash
git clone https://github.com/rafidhn06/sistem-manajemen-perpustakaan
cd sistem-manajemen-perpustakaan
g++ -o sistem-manajemen-perpustakaan src/*.cpp main.cpp -Iinclude -std=c++17
```

Untuk menjalankan program, command berikut dapat dijalankan.

```bash
./sistem-manajemen-perpustakaan
```
