#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string document;
    Node *next;
};

void enqueue(Node *&front, Node *&rear, string document)
{
    Node *newNode = new Node{document, nullptr}; // buat node baru yang nyimpen dokumen

    if (front == nullptr) // kalau antrian kosong
    {
        front = newNode; // jadi elemen pertama
        rear = newNode;  // jadi elemen terakhir
    }
    else // kalau gak kosong
    {
        rear->next = newNode; // sambungkan node baru ke belakang antrian
        rear = newNode;       // ubah pointer rear ke node baru
    }
}

string dequeue(Node *&front, Node *&rear)
{
    if (front == nullptr) // jika kosong
        return "";

    Node *temp = front;          // simpan alamat node
    string doc = temp->document; // simpan data

    front = front->next;  // geser pointer
    if (front == nullptr) // kalau misal digeser hasilnya kosong
    {
        rear = nullptr; // belakangnya juga jadi kosong

        delete temp; // hapus node lama
        return doc;  // kembalikan dokumen yang tadi diambil
    }
}

void processAllDocuments(Node *&front, Node *&rear)
{
    while (front != nullptr) // selama antrian tidak kosong
    {
        string doc = dequeue(front, rear); // ambil dokumen dari depan
        cout << "Memproses: " << doc << endl;
    }
}

int main()
{
    Node *front = nullptr;
    Node *rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
