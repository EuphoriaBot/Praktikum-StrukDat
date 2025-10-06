#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

void push(Node *&top, char data)
{
    Node *newNode = new Node{data, top};
    top = newNode;
}

char pop(Node *&top)
{
    if (top == nullptr)
        return '\0'; // Return null character jika stack kosong
    Node *temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s)
{
    Node *stackTop = nullptr;
    string reversed = "";

    for (int i = 0; i < s.length(); i++) // ngeloop tiap karakter dari pertama sampe terakhir
    {
        push(stackTop, s[i]); // ngemasukin tiap karakter ke dalam stack
    }

    while (stackTop != nullptr)
    {
        reversed += pop(stackTop); // ngeluarkan karakternya baru memasukkan kembali secara di reversed
    }

    return reversed;
}

int main()
{
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // ataD rukurtS
    return 0;
}