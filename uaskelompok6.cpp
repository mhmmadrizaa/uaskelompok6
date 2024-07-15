#include <stdio.h>
#include <string.h>

// Definisi struct untuk menyimpan data reservasi
typedef struct {
    char nama[50];
    int jumlahOrang;
    char tanggal[20];
    char waktu[10];
} Reservasi;