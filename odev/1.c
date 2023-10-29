#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>

// Liste eleman�n� temsil eden yap� (node)
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir d���m (node) olu�turan yard�mc� fonksiyon
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Tek ve �ift say�lar� ayr� listelere ay�ran fonksiyon
void ayirEkle(struct Node** tekListe, struct Node** ciftListe, int sayi) {
    struct Node* node = newNode(sayi);

    if (sayi % 2 == 1) { // Tek say� ise
        node->next = *tekListe;
        *tekListe = node;
    } else { // �ift say� ise
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

// Liste elemanlar�n� ekrana yazd�ran fonksiyon
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* tekListe = NULL;  // Tek say�lar� tutan liste
    struct Node* ciftListe = NULL; // �ift say�lar� tutan liste
    int girilenSayi;

    // Kullan�c� -1 girene kadar say�lar� oku ve listelere ekle
    printf("Sayilari giriniz (-1 girerek sonlandiriniz):\n");
    scanf("%d", &girilenSayi);

    while (girilenSayi != -1) {
        ayirEkle(&tekListe, &ciftListe, girilenSayi);
        scanf("%d", &girilenSayi);
    }

    // Tek say�lar� ekrana yazd�r
    printf("Tek sayilarin listesi: ");
    printList(tekListe);

    // �ift say�lar� ekrana yazd�r
    printf("Cift sayilarin listesi: ");
    printList(ciftListe);

    // Belle�i temizle
    free(tekListe);
    free(ciftListe);

    return 0;
}

