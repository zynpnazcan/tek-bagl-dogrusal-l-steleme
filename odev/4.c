#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// ��renci bilgilerini i�eren struct
struct Student {
    int studentNumber;
    char name[50];
    int age;
};

// Tek ba�l� liste d���m�
struct Node {
    struct Student data;
    struct Node* next;
};

// Yeni bir d���m olu�turma
struct Node* createNode(struct Student student) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = NULL;
    return newNode;
}

// Listeye eleman ekleme
void insertNode(struct Node** head, struct Student student) {
    struct Node* newNode = createNode(student);
    newNode->next = *head;
    *head = newNode;
}

// Listede ��renci ad�na g�re kay�t arama
struct Student* searchByName(struct Node* head, const char* name) {
    struct Node* current = head;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            // �sim e�le�mesi bulundu
            return &current->data;
        }
        current = current->next;
    }

    // �sim bulunamad�
    return NULL;
}

int main() {
    struct Node* head = NULL;
    
    // ��renci bilgileri ile liste olu�turma
    struct Student student1 = {1, "Ilayda", 20};
    struct Student student2 = {2, "Ayse", 22};
    struct Student student3 = {3, "Mehmet", 21};

    // Liste ba��na ��renci ekleme
    insertNode(&head, student1);
    insertNode(&head, student2);
    insertNode(&head, student3);

    // �simle kay�t arama ve bilgileri ekrana yazma
    const char* searchName = "Ayse";
    struct Student* foundStudent = searchByName(head, searchName);

    if (foundStudent != NULL) {
        printf("Ogrenci bulundu:\n");
        printf("Ogrenci No: %d, Isim: %s, Yas: %d\n", foundStudent->studentNumber, foundStudent->name, foundStudent->age);
    } else {
        printf("Ogrenci bulunamad�.\n");
    }

    return 0;
}

	
