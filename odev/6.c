#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// ��renci bilgileri tan�mlamalar�:
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student *next;
};

// Ba�l� liste �zerinde dola�arak en uzun ismi bulan fonksiyon
void findLongestName(struct Student *head) {
    struct Student *current = head;
    int maxLength = 0;
    char *longestName;

    while (current != NULL) {
        if (strlen(current->name) > maxLength) {
            maxLength = strlen(current->name);
            longestName = current->name;
        }
        current = current->next;
    }

    // En uzun isme sahip kayd� yazd�r
    printf("En uzun isme sahip kayit: %s\n", longestName);
}

// �rnek bir ba�l� liste olu�tur
struct Student* createSampleLinkedList() {
    struct Student *head = NULL;
    struct Student *second = NULL;
    struct Student *third = NULL;

    // Bellekte yer ay�r
    head = (struct Student *)malloc(sizeof(struct Student));
    second = (struct Student *)malloc(sizeof(struct Student));
    third = (struct Student *)malloc(sizeof(struct Student));

    // Veri atamas� yap
    head->studentNumber = 1;
    strcpy(head->name, "Arya");
    head->age = 20;
    head->next = second;

    second->studentNumber = 2;
    strcpy(second->name, "Melek");
    second->age = 21;
    second->next = third;

    third->studentNumber = 3;
    strcpy(third->name, "Abdullah");
    third->age = 22;
    third->next = NULL;

    // En uzun ismi bulan fonksiyonu �a��r
    findLongestName(head);

    return head;
}

// Ana fonksiyon
int main() {
    // �rnek ba�l� listeyi olu�tur
    struct Student *list = createSampleLinkedList();

    // Belle�i serbest b�rak
    free(list);
    
    return 0;
}
