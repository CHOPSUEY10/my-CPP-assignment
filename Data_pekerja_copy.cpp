# include "Deklarasi_projek.h"
# include "Defenisi_projek.cpp"
# include <fstream>
# include <sstream>
# include <iostream>
# include <vector>
# include <memory>
# include <algorithm>
# include <cctype> 


// kelas polimorfisme 
class Pengembang : public Karyawan {

    void Jobdesc () {
        cout << NamaKaryawan << " pada departmen " << NamaDept << " Sebagai pengembang perangkat lunak" << endl;;
    }

};

class Pemasaran : public Karyawan {

     void Jobdesc () {
        cout << NamaKaryawan << " pada departmen " << NamaDept << " Sebagai pemasar produk frozen food" << endl;;
    }


};

class Keuangan : public Karyawan {

     void Jobdesc () {
        cout << NamaKaryawan << " pada departmen " << NamaDept << " Sebagai pengatur keuangan perusahaan" << endl;;
    }


};

class Peneliti : public Karyawan {

    public:
     void Jobdesc () {
        cout << NamaKaryawan << " pada departmen " << NamaDept << " Sebagai peneliti teknologi pangan perusahaan" << endl;;
    }



};

string normalizeString(const string& str) {
    string result = str;
    // Menghapus whitespace dari awal dan akhir string
    result.erase(0, result.find_first_not_of(" \t\n\r\f\v"));
    result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
    // Mengubah ke lowercase
    transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return tolower(c); });
    return result;
}

    
    
unique_ptr<Karyawan> createKaryawan(const string& departmen) {
     
    string normalizedDept = normalizeString(departmen);
    
    if (normalizedDept == "pengembang") {
        return make_unique<Pengembang>();
    } else if (normalizedDept == "pemasaran") {
        return make_unique<Pemasaran>();
    } else if (normalizedDept == "keuangan") {
        return make_unique<Keuangan>();
    } else if (normalizedDept == "peneliti") {
        return make_unique<Peneliti>();
    } else {
        cout << "Department tidak dikenal: " << departmen << endl;
        return nullptr;
    }
}

// Membaca data csv
bool readCSV(vector<unique_ptr<Karyawan>>& daftarKaryawan) {
    ifstream file("Data.csv");
    if (!file.is_open()) {
        cout << "Tidak bisa membuka file tersebut!" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nama, departmen, jabatan, gaji, umur, lamaBekerja, jenisKelamin;

        getline(ss, nama, ';');
        getline(ss, departmen, ';');
        getline(ss, jabatan, ';');
        getline(ss, gaji, ';');
        getline(ss, umur, ';');
        getline(ss, lamaBekerja, ';');
        getline(ss, jenisKelamin, ';');

        auto karyawan = createKaryawan(departmen);
        if (karyawan) {
            karyawan->SetNamaKaryawan(nama);
            karyawan->Department::SetNama(departmen);
            karyawan->SetJabatan(jabatan);
            karyawan->SetGaji(stoi(gaji));
            karyawan->SetUmur(stoi(umur));
            karyawan->SetLamaBekerja(stoi(lamaBekerja));
            karyawan->SetJenisKelamin(jenisKelamin[0]);

            daftarKaryawan.push_back(move(karyawan));
        } else {
            cout << "Department tidak dikenal: " << departmen << endl;
        }
    }

    file.close();
    return !daftarKaryawan.empty();
}

int main() {
    vector<unique_ptr<Karyawan>> daftarKaryawan;

    if (readCSV(daftarKaryawan)) {
        for (const auto& karyawan : daftarKaryawan) {
            cout << "Nama Karyawan : " << karyawan->GetNamaKaryawan() << '\n';
            cout << "Department : " << karyawan->GetNamaDept() << '\n';
            cout << "Jabatan : " << karyawan->GetJabatan() << '\n';
            cout << "Gaji : " << karyawan->GetGaji() << '\n';
            cout << "Umur : " << karyawan->GetUmur() << '\n';
            cout << "Lama Bekerja : " << karyawan->GetLamaBekerja() <<" Tahun "<< '\n';
            cout << "Jenis Kelamin : " << karyawan->GetJenisKelamin() << '\n';
            karyawan->Jobdesc();
            cout << endl;
        }
    } else {
        cout << "Gagal membaca data dari file CSV atau tidak ada data valid." << endl;
    }
}
    

