#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ADI_UZUNLUGU 50
#define MAX_SOYADI_UZUNLUGU 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */




struct Ogrenci {
    int numara;
    char adi[MAX_ADI_UZUNLUGU];
    char soyadi[MAX_SOYADI_UZUNLUGU];
    struct Ogrenci* next;
};

void ogrenciSilSonraki(struct Ogrenci* head, const char *arananAd) {
    struct Ogrenci *temp = head;
    struct Ogrenci *silDugumu = NULL;

    while (temp != NULL && strcmp(temp->adi, arananAd) != 0) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        silDugumu = temp->next;
        temp->next = silDugumu->next;
        free(silDugumu);
        printf("%s adli ogrencinin sonraki ogrencisi listeden silindi.\n", arananAd);
    } else {
        printf("%s adli ogrencinin sonraki ogrencisi bulunamadi veya listede sadece bir ogrenci var.\n", arananAd);
    }
}

void ogrenciEkle(struct Ogrenci** head, int numara, const char *adi, const char *soyadi) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->numara = numara;
    strncpy(yeniOgrenci->adi, adi, MAX_ADI_UZUNLUGU - 1);
    yeniOgrenci->adi[MAX_ADI_UZUNLUGU - 1] = '\0';
    strncpy(yeniOgrenci->soyadi, soyadi, MAX_SOYADI_UZUNLUGU - 1);
    yeniOgrenci->soyadi[MAX_SOYADI_UZUNLUGU - 1] = '\0';
    yeniOgrenci->next = *head;
    *head = yeniOgrenci;
}

void ogrenciListele(struct Ogrenci* head) {
    printf("Ogrenci Listesi:\n");
    while (head != NULL) {
        printf("Numara: %d, Ad: %s, Soyad: %s\n", head->numara, head->adi, head->soyadi);
        head = head->next;
    }
}

int main() {
    struct Ogrenci* head = NULL;

    ogrenciEkle(&head, 1, "Eylul", "Yilmaz");
    ogrenciEkle(&head, 2, "Ayse", "Gisi");
    ogrenciEkle(&head, 3, "Zeynep", "Kaya");

    printf("Baslangicta:\n");
    ogrenciListele(head);

    char arananAd[MAX_ADI_UZUNLUGU];
    printf("\nSilmek istediginiz ogrencinin adini girin: ");
    scanf("%s", arananAd);

    ogrenciSilSonraki(head, arananAd);

    printf("\nYeni Liste:\n");
    ogrenciListele(head);

    return 0;
}








