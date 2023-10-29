#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>

// Liste elemanýný temsil eden yapý (node)
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düðüm (node) oluþturan yardýmcý fonksiyon
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Tek ve çift sayýlarý ayrý listelere ayýran fonksiyon
void ayirEkle(struct Node** tekListe, struct Node** ciftListe, int sayi) {
    struct Node* node = newNode(sayi);

    if (sayi % 2 == 1) { // Tek sayý ise
        node->next = *tekListe;
        *tekListe = node;
    } else { // Çift sayý ise
        if (*ciftListe == NULL) {
            *ciftListe = node;
        } else {
            struct Node* temp = *ciftListe;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
}

// Liste elemanlarýný ekrana yazdýran fonksiyon
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* tekListe = NULL;  // Tek sayýlarý tutan liste
    struct Node* ciftListe = NULL; // Çift sayýlarý tutan liste
    int girilenSayi;

    // Kullanýcý -1 girene kadar sayýlarý oku ve listelere ekle
    printf("Sayilari giriniz (-1 girerek sonlandiriniz):\n");
    scanf("%d", &girilenSayi);

    while (girilenSayi != -1) {
        ayirEkle(&tekListe, &ciftListe, girilenSayi);
        scanf("%d", &girilenSayi);
    }

    // Tek sayýlarý ekrana yazdýr
    printf("Tek sayilarin listesi: ");
    printList(tekListe);

    // Çift sayýlarý ekrana yazdýr
    printf("Cift sayilarin listesi: ");
    printList(ciftListe);

    // Belleði temizle
    free(tekListe);
    free(ciftListe);

    return 0;
}

