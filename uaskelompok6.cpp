#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Tambahkan ini untuk menggunakan tipe bool

// Definisi struct untuk menyimpan data reservasi
typedef struct {
    char nama[50];
    int jumlahOrang;
    char tanggal[20];
    char waktu[10];
} Reservasi;

// Fungsi validasi ketersediaan meja
bool validasiMeja(Reservasi reservasi[], int jumlahReservasi, const char tanggal[], const char waktu[]) {
    for(int i = 0; i < jumlahReservasi; i++) {
        if(strcmp(reservasi[i].tanggal, tanggal) == 0 && strcmp(reservasi[i].waktu, waktu) == 0) {
            return false; // Meja sudah dipesan pada waktu tersebut
        }
    }
    return true; // Meja tersedia
}
