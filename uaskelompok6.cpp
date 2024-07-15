#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

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
// Fungsi untuk menambah reservasi
void tambahReservasi(Reservasi reservasi[], int *jumlahReservasi) {
    char tanggal[20], waktu[10];
    
    printf("Masukkan nama: ");
    scanf("%s", reservasi[*jumlahReservasi].nama);
    printf("Masukkan jumlah orang: ");
    scanf("%d", &reservasi[*jumlahReservasi].jumlahOrang);
    printf("Masukkan tanggal (DD-MM-YYYY): ");
    scanf("%s", tanggal);
    printf("Masukkan waktu (HH:MM): ");
    scanf("%s", waktu);
    
    if(validasiMeja(reservasi, *jumlahReservasi, tanggal, waktu)) {
        strcpy(reservasi[*jumlahReservasi].tanggal, tanggal);
        strcpy(reservasi[*jumlahReservasi].waktu, waktu);
        (*jumlahReservasi)++;
        printf("Reservasi berhasil ditambahkan.\n");
    } else {
        printf("Meja sudah dipesan pada waktu tersebut. Silakan pilih waktu lain.\n");
    }
}
// Fungsi untuk menampilkan daftar reservasi
void tampilkanReservasi(Reservasi reservasi[], int jumlahReservasi) {
    for(int i = 0; i < jumlahReservasi; i++) {
        printf("Reservasi %d\n", i + 1);
        printf("Nama: %s\n", reservasi[i].nama);
        printf("Jumlah Orang: %d\n", reservasi[i].jumlahOrang);
        printf("Tanggal: %s\n", reservasi[i].tanggal);
        printf("Waktu: %s\n", reservasi[i].waktu);
        printf("--------------------------\n");
    }
}
// Fungsi untuk menghapus reservasi
void hapusReservasi(Reservasi reservasi[], int *jumlahReservasi) {
    int nomor;
    printf("Masukkan nomor reservasi yang ingin dihapus: ");
    scanf("%d", &nomor);
    
    if(nomor > 0 && nomor <= *jumlahReservasi) {
        for(int i = nomor - 1; i < *jumlahReservasi - 1; i++) {
            reservasi[i] = reservasi[i + 1];
        }
        (*jumlahReservasi)--;
        printf("Reservasi berhasil dihapus.\n");
    } else {
        printf("Nomor reservasi tidak valid.\n");
    }
}
// Fungsi validasi ketersediaan meja
int validasiMeja(Reservasi reservasi[], int jumlahReservasi, char tanggal[], char waktu[]) {
    for(int i = 0; i < jumlahReservasi; i++) {
        if(strcmp(reservasi[i].tanggal, tanggal) == 0 && strcmp(reservasi[i].waktu, waktu) == 0) {
            return 0; // Meja sudah dipesan pada waktu tersebut
        }
    }
    return 1; // Meja tersedia
}
// Menu utama
int main() {
    Reservasi reservasi[100];
    int jumlahReservasi = 0;
    int pilihan;
    
    do {
        printf("Menu:\n");
        printf("1. Tambah Reservasi\n");
        printf("2. Tampilkan Reservasi\n");
        printf("3. Hapus Reservasi\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1:
                tambahReservasi(reservasi, &jumlahReservasi);
                break;
            case 2:
                tampilkanReservasi(reservasi, jumlahReservasi);
                break;
            case 3:
                hapusReservasi(reservasi, &jumlahReservasi);
                break;
            case 4:
                printf("Terima kasih telah menggunakan aplikasi ini.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while(pilihan != 4);
    
    return 0;
}