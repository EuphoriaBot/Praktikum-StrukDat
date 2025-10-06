#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void sortedInsert(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr}; // buat node baru

    if (head_ref == nullptr) // jika kosong
    {
        newNode->next = newNode; // next nunjuk ke dirinya sendiri
        newNode->prev = newNode; // prev nunjuk ke dirinya sendiri
        head_ref = newNode;      // head ke node baru
        return;
    }

    Node *head = head_ref;

    if (data < head->data)
    {
        Node *tail = head->prev;

        newNode->next = head; // node baru menunjuk ke head sebagai next
        newNode->prev = tail; // node baru menunjuk ke tail sebagai prev

        tail->next = newNode; // tail menunjuk ke node baru sebagai next
        head->prev = newNode; // head menunjuk ke node baru sebagai prev

        head_ref = newNode; // diperbarui agar node baru menjadi head
        return;
    }

    Node *current = head; // transversal dari head
    while (current->next != head && current->next->data < data)
    {
        current = current->next; // nge geser sampe nemu posisi yang diinginkan
    }

    Node *nextNode = current->next;

    newNode->next = nextNode; // node baru menunjuk ke node setelah current
    newNode->prev = current;  // node baru menunjuk ke current sebagai prev

    current->next = newNode;  // current sekarang menunjuk node baru sebagai next
    nextNode->prev = newNode; // node setelahnya menunjuk balik ke node baru sebagai prev
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref; // transversal dari head
    do
    {
        cout << current->data << " "; // Cetak data dari node saat ini
        current = current->next;      // Pindah ke node berikutnya
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}