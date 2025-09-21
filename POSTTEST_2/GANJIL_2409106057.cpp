#include <iostream>
using namespace std;

struct Inventory
{
    string NamaItem;
    int JumlahItem;
    string TipeItem;
};

struct Node
{
    Inventory inv;
    Node *next;
};

void addFirst(Node *&head, string NamaItem, int JumlahItem, string TipeItem)
{
    Node *nodeBaru = new Node;
    nodeBaru->inv.NamaItem = NamaItem;
    nodeBaru->inv.JumlahItem = JumlahItem;
    nodeBaru->inv.TipeItem = TipeItem;
    nodeBaru->next = head;
    head = nodeBaru;
}

void addLast(Node *&head, string NamaItem, int JumlahItem, string TipeItem)
{
    Node *nodeBaru = new Node;
    nodeBaru->inv.NamaItem = NamaItem;
    nodeBaru->inv.JumlahItem = JumlahItem;
    nodeBaru->inv.TipeItem = TipeItem;
    nodeBaru->next = nullptr;

    if (head == nullptr)
    {
        head = nodeBaru;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void addSpecific(Node *&head, int Sisipan, string NamaItem, int JumlahItem, string TipeItem)
{
    if (Sisipan <= 1)
    {
        addFirst(head, NamaItem, JumlahItem, TipeItem);
        return;
    }

    Node *temp = head;
    int index = 1;

    while (temp != nullptr && index < Sisipan - 1)
    {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr)
    {
        cout << "Posisi melebihi panjang list, Ditambahkan di akhir." << endl;
        addLast(head, NamaItem, JumlahItem, TipeItem);
    }
    else
    {
        Node *nodeBaru = new Node;
        nodeBaru->inv.NamaItem = NamaItem;
        nodeBaru->inv.JumlahItem = JumlahItem;
        nodeBaru->inv.TipeItem = TipeItem;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

void deleteLast(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Inventory kosong" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteSpesific(Node *&head, string nama)
{
    if (head == nullptr)
    {
        cout << "Inventory kosong" << endl;
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr && temp->inv.NamaItem != nama)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Item tidak ditemukan" << endl;
        return;
    }

    temp->inv.JumlahItem--;

    cout << "Menggunakan 1 " << nama << ". Sisa: " << temp->inv.JumlahItem << endl;

    if (temp->inv.JumlahItem <= 0)
    {
        cout << "Item " << nama << " habis, dihapus dari inventory." << endl;
        if (prev == nullptr)
        {
            head = temp->next;
            delete temp;
        }
        else
        {
            prev->next = temp->next;
            delete temp;
        }
    }
}

void showInventory(Node *head)
{
    if (head == nullptr)
    {
        cout << "Inventory Kosong" << endl;
        return;
    }

    cout << "===== INVENTORY GAME =====" << endl;
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << "Nama   : " << temp->inv.NamaItem << endl;
        cout << "Jumlah : " << temp->inv.JumlahItem << endl;
        cout << "Tipe   : " << temp->inv.TipeItem << endl;
        cout << "--------------------------" << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = nullptr;
    string NamaItem, TipeItem;
    int pilihan;
    int JumlahItem = 57;
    int Sisipan = 7 + 1;

    do
    {
        cout << "----------------------------------------------" << endl;
        cout << "        GAME INVENTORY MANAGEMENT             " << endl;
        cout << "         [ Dimas - 2409106057 ]               " << endl;
        cout << "----------------------------------------------" << endl;
        cout << "| 1. Tambah Item Baru                         " << endl;
        cout << "| 2. Sisipkan Item                            " << endl;
        cout << "| 3. Hapus Item Terakhir                      " << endl;
        cout << "| 4. Gunakan Item                             " << endl;
        cout << "| 5. Tampilkan Inventory                      " << endl;
        cout << "| 0. Keluar                                   " << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "Masukkan nama item: ";
            cin >> NamaItem;
            cout << "Masukkan tipe item: ";
            cin >> TipeItem;
            addLast(head, NamaItem, JumlahItem, TipeItem);
        }
        else if (pilihan == 2)
        {
            cout << "Masukkan nama item: ";
            cin >> NamaItem;
            cout << "Masukkan tipe item: ";
            cin >> TipeItem;
            addSpecific(head, Sisipan, NamaItem, JumlahItem, TipeItem);
        }
        else if (pilihan == 3)
        {
            deleteLast(head);
        }
        else if (pilihan == 4)
        {
            cout << "Masukkan nama item yang ingin digunakan: ";
            cin >> NamaItem;
            deleteSpesific(head, NamaItem);
        }
        else if (pilihan == 5)
        {
            showInventory(head);
        }
        else if (pilihan == 0)
        {
            cout << "Keluar dari program" << endl;
        }
        else
        {
            cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
