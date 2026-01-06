#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string nama[50];
    float matematika[50], ips[50], ipa[50];
    float rata[50];
    int jumlah = 0;
    int pilihan;

    cout <<"=====================\n";
    cout <<"MANAJEMEN NILAI SISWA\n";
    cout <<"=====================\n";

    while(true) {
        cout <<"\n1.Input siswa\n";
        cout <<"2.Lihat nilai\n";
        cout <<"3.Hitung Rata-rata\n";
        cout <<"4.Keluar\n";
        cout <<"pilih: ";
        cin >> pilihan;

        if(pilihan == 1) {
            if(jumlah >= 50) {
                cout <<"Data sudah penuh!\n";
                continue;
            }

            cout <<"Nama :";
            cin.ignore();
            getline(cin, nama[jumlah]);

            cout <<"Nilai Matematika :";
            cin >> matematika[jumlah];

            cout <<"Nilai IPS :";
            cin >> ips[jumlah];

            cout <<"Nilai IPA :";
            cin >> ipa[jumlah];

            jumlah++;
            cout <<"Data tersimpan!\n";

        } else if(pilihan == 2) {
            if(jumlah == 0) {
                cout <<"Belum ada data!\n";
                continue;
            }

            cout << "\n===============================================\n";
            cout << left << setw(4) << "No" 
                 << setw(15) << "Nama" 
                 << setw(12) << "Matematika" 
                 << setw(10) << "IPS" 
                 << setw(10) << "IPA" << endl;
            cout <<"==============================================\n";

            for(int i = 0; i < jumlah; i++) {
                cout << left << setw(4) << (i + 1) 
                     << setw(15) << nama[i].substr(0, 14)
                     << setw(12) << fixed << setprecision(1) << matematika[i] 
                     << setw(10) << fixed << setprecision(1) << ips[i] 
                     << setw(10) << fixed << setprecision(1) << ipa[i] << endl;
            }

            cout <<"==============================================\n";

        } else if(pilihan == 3) {
            if(jumlah == 0) {
                cout <<"Belum ada data!\n";
                continue;
            }

            // Hitung rata-rata
            for(int i = 0; i < jumlah; i++) {
                rata[i] = (matematika[i] + ips[i] + ipa[i]) / 3.0;
            }

            cout << "\n=================================================\n";
            cout << left << setw(4) << "No" 
                 << setw(15) << "Nama" 
                 << setw(12) << "Rata-rata"
                 << setw(8) << "Grade" << endl;
            cout <<"===================================================\n";

            for(int i = 0; i < jumlah; i++) {
                char grade;
                if(rata[i] >= 85.0) grade = 'A';
                else if(rata[i] >= 70.0) grade = 'B';
                else if(rata[i] >= 55.0) grade = 'C';
                else if(rata[i] >= 40.0) grade = 'D';
                else grade = 'E';

                cout << left << setw(4) << (i + 1) 
                     << setw(15) << nama[i].substr(0, 14)
                     << setw(12) << fixed << setprecision(2) << rata[i]
                     << setw(8) << grade << endl;
            }

            cout <<"===================================================\n";

        } else if(pilihan == 4) {
            cout <<"Program selesai.\n";
            break;

        } else {
            cout <<"Pilihan salah!\n";
    }
}

return 0;
}