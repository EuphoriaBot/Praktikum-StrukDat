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
    Node *prev;
};

void addFirst(Node *&head, string NamaItem, int JumlahItem, string TipeItem)
{
    Node *nodeBaru = new Node;
    nodeBaru->inv.NamaItem = NamaItem;
    nodeBaru->inv.JumlahItem = JumlahItem;
    nodeBaru->inv.TipeItem = TipeItem;
    nodeBaru->prev = nullptr;
    nodeBaru->next = head;
    if (head != nullptr)
    {
        head->prev = nodeBaru;
    }
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
        nodeBaru->prev = nullptr;
        head = nodeBaru;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    nodeBaru->prev = temp;
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
        cout << "Ditambahkan Di Akhir Karena Melebihi Panjang List" << endl;
        addLast(head, NamaItem, JumlahItem, TipeItem);
    }
    else
    {
        Node *nodeBaru = new Node;
        nodeBaru->inv.NamaItem = NamaItem;
        nodeBaru->inv.JumlahItem = JumlahItem;
        nodeBaru->inv.TipeItem = TipeItem;

        nodeBaru->next = temp->next;
        nodeBaru->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = nodeBaru;
        }
        temp->next = nodeBaru;
    }
}

void deleteLast(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Inventory Kosong" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void deleteSpesific(Node *&head, string nama)
{
    if (head == nullptr)
    {
        cout << "Inventory Kosong" << endl;
        return;
    }

    Node *temp = head;

    while (temp != nullptr && temp->inv.NamaItem != nama)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Item Tidak Ditemukan" << endl;
        return;
    }

    temp->inv.JumlahItem--;

    cout << "Menggunakan 1 " << nama << " Sisa: " << temp->inv.JumlahItem << endl;

    if (temp->inv.JumlahItem <= 0)
    {
        cout << "Item " << nama << " Sudah Habis" << endl;
        if (temp->prev == nullptr)
        {
            head = temp->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
        }
        else
        {
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
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

void showInventoryReverse(Node *head)
{
    if (head == nullptr)
    {
        cout << "Inventory Kosong" << endl;
        return;
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    cout << "===== INVENTORY GAME =====" << endl;
    while (tail != nullptr)
    {
        cout << "Nama   : " << tail->inv.NamaItem << endl;
        cout << "Jumlah : " << tail->inv.JumlahItem << endl;
        cout << "Tipe   : " << tail->inv.TipeItem << endl;
        cout << "--------------------------" << endl;
        tail = tail->prev;
    }
}

void showDetail(Node *head, string nama)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->inv.NamaItem == nama)
        {
            cout << "===== DETAIL ITEM =====" << endl;
            cout << "Nama   : " << temp->inv.NamaItem << endl;
            cout << "Jumlah : " << temp->inv.JumlahItem << endl;
            cout << "Tipe   : " << temp->inv.TipeItem << endl;
            cout << "=======================" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Item Dengan Nama " << nama << " Tidak Ditemukan" << endl;
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
        cout << "1. Tambah Item Baru                           " << endl;
        cout << "2. Sisipkan Item                              " << endl;
        cout << "3. Hapus Item Terakhir                        " << endl;
        cout << "4. Gunakan Item                               " << endl;
        cout << "5. Tampilkan Inventory Dari Depan             " << endl;
        cout << "6. Tampilkan Inventory Dari Belakang          " << endl;
        cout << "7. Tampilkan Detail Item                      " << endl;
        cout << "0. Keluar                                     " << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "Masukkan Nama Item: ";
            cin >> NamaItem;
            cout << "Masukkan Tipe Item: ";
            cin >> TipeItem;
            addLast(head, NamaItem, JumlahItem, TipeItem);
        }
        else if (pilihan == 2)
        {
            cout << "Masukkan Nama Item: ";
            cin >> NamaItem;
            cout << "Masukkan Tipe Item: ";
            cin >> TipeItem;
            addSpecific(head, Sisipan, NamaItem, JumlahItem, TipeItem);
        }
        else if (pilihan == 3)
        {
            deleteLast(head);
        }
        else if (pilihan == 4)
        {
            cout << "Masukkan Nama Item Yang Ingin Digunakan: ";
            cin >> NamaItem;
            deleteSpesific(head, NamaItem);
        }
        else if (pilihan == 5)
        {
            showInventory(head);
        }
        else if (pilihan == 6)
        {
            showInventoryReverse(head);
        }
        else if (pilihan == 7)
        {
            cout << "Masukkan Nama Item untuk Detail: ";
            cin >> NamaItem;
            showDetail(head, NamaItem);
        }
        else if (pilihan == 0)
        {
            cout << "Keluar Dari Program" << endl;
        }
        else
        {
            cout << "Pilihan Tidak Valid" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
