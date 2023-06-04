#include <iostream>
#include <vector>

using namespace std;

vector<int> create_array(int length) {
    /* Membuat array kosong dengan panjang sesuai yang diminta */
    vector<int> array(length, 0);
    return array;
}

void input_array_values(vector<int>& array) {
    /* Menginput nilai-nilai pada array */
    for (int i = 0; i < array.size(); i++) {
        cout << "Masukkan nilai pada index ke-" << i << ": ";
        cin >> array[i];
    }
}

int find_value_in_array(vector<int>& array, int value) {
    /* Mencari nilai tertentu pada array */
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

void update_array_value(vector<int>& array, int index, int value) {
    /* Mengubah nilai pada index tertentu dalam array */
    array[index] = value;
    cout << "Nilai pada index ke-" << index << " berhasil diubah menjadi " << value << endl;
}

int main() {
    int length;
    cout << "Masukkan panjang array yang diinginkan: ";
    cin >> length;
    vector<int> array = create_array(length);

    int choice;
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Input nilai array" << endl;
        cout << "2. Cari nilai pada array" << endl;
        cout << "3. Ubah nilai pada array" << endl;
        cout << "4. Exit" << endl;

        cout << "Pilih menu: ";
        cin >> choice;

        if (choice == 1) {
            input_array_values(array);
            cout << "Array saat ini: [";
            for (int i = 0; i < array.size(); i++) {
                cout << array[i];
                if (i != array.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        } else if (choice == 2) {
            int value;
            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> value;
            int index = find_value_in_array(array, value);
            if (index != -1) {
                cout << "Nilai " << value << " ditemukan pada index ke-" << index << endl;
            } else {
                cout << "Nilai " << value << " tidak ditemukan dalam array" << endl;
            }
        } else if (choice == 3) {
            int index, value;
            cout << "Masukkan index yang ingin diubah: ";
            cin >> index;
            cout << "Masukkan nilai baru: ";
            cin >> value;
            update_array_value(array, index, value);
            cout << "Array saat ini: [";
            for (int i = 0; i < array.size(); i++) {
                cout << array[i];
                if (i != array.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        } else if (choice == 4) {
            cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}