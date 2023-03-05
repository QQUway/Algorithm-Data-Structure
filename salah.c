#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char nim[13];
    char nama[51];
    char Jurusan[51];
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

void insert_node() {
    Node *new_node = (Node*) malloc(sizeof(Node));
    printf("Masukkan NIM: ");
    getchar();
    scanf("%[^\n]s", new_node->nim);
    printf("Masukkan nama: ");
    getchar();
    scanf("%[^\n]s", new_node->nama);
    printf("Masukkan Jurusan: ");
    getchar();
    scanf("%[^\n]s", new_node->Jurusan);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node_by_nim(char *nim) {
    if (head == NULL) {
        return;
    }

    if (strcmp(head->nim, nim) == 0) {
        head = head->next;
        return;
    }

    Node *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->nim, nim) == 0) {
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
}

void delete_first_node() {
    if (head == NULL) {
        return;
    }

    head = head->next;
}

void delete_all_nodes() {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void print_linked_list() {
    int i = 1;
    if (head == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    Node *current = head;
        printf("=========================================================================================\n");
        printf("| No. |      NIM      | Name                           |           Jurusan              |\n");
        printf("=========================================================================================\n");
    while (current != NULL) {
        printf("| %-3d | %-13s | %-30s | %-30s |\n",i, current->nim, current->nama, current->Jurusan);
        current = current->next;
        i++;
    }
        printf("=========================================================================================\n");
}

void display_menu() {
    printf("Menu:\n");
    printf("1. Insert new node\n");
    printf("2. Print linked list\n");
    printf("3. Delete all data\n");
    printf("4. Delete first data\n");
    printf("5. Delete data by nim\n");
    printf("6. Exit\n");
}

int main() {
    while (1) {
        system("cls");
        system("clear");
        display_menu();
        int choice;
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:               
                insert_node();
                printf("New Node added\n");
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            case 2:               
                print_linked_list();
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            case 3:
                delete_all_nodes();
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            case 4:
                delete_first_node();
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            case 5:
                char nim[11];
                printf("Masukkan NIM yang akan dihapus: ");
                scanf("%s", nim);
                delete_node_by_nim(nim);
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            case 6:
                return 0;
            default:
                printf("Pilihan tidak valid\n");
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
        }
    }
    return 0;
}
