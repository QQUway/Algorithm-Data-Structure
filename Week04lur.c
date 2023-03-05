#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char nim[11];
    char nama[51];
    float nilai;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

void insert_node() {
    Node *new_node = (Node*) malloc(sizeof(Node));
    printf("Masukkan NIM: ");
    scanf("%s", new_node->nim);
    printf("Masukkan nama: ");
    scanf("%s", new_node->nama);
    printf("Masukkan nilai: ");
    scanf("%f", &new_node->nilai);
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
    if (head == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        printf("NIM: %s, Nama: %s, Nilai: %.2f\n", current->nim, current->nama, current->nilai);
        current = current->next;
    }
}

void display_menu() {
    printf("Menu:\n");
    printf("1. Insert new node\n");
    printf("2. Print linked list\n");
    printf("3. Delete all data\n");
    printf("4. Delete first data\n");
    printf("5. Delete data by nim\n");
}

int main() {
    while (1) {
        display_menu();
        int choice;
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_node();
                break;
            case 2:
                print_linked_list();
                break;
            case 3:
                delete_all_nodes();
                break;
            case 4:
                delete_first_node();
                break;
            case 5:
                char nim[11];
                printf("Masukkan NIM yang akan dihapus: ");
                scanf("%s", nim);
                delete_node_by_nim(nim);
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    }
    return 0;
}
