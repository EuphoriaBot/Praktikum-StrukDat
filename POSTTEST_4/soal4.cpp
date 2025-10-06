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
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *head = head_ref;

    if (data < head->data)
    {
        Node *tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head_ref = newNode;
        return;
    }

    Node *current = head;
    while (current->next != head && current->next->data < data)
    {
        current = current->next;
    }

    Node *nextNode = current->next;

    newNode->next = nextNode;
    newNode->prev = current;

    current->next = newNode;
    nextNode->prev = newNode;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
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