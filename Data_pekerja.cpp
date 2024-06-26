# include "Deklarasi_projek.h"
# include "Defenisi_projek.cpp"
# include <fstream>
# include <sstream>
# include <iostream>
# include <vector>


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
    
    

bool readCSV(Karyawan &bacadata) {
    ifstream file;
    file.open("Data.csv");

    if (!file.is_open()) {
        cout << "Tidak bisa membuka file tersebut!" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nama,departmen,jabatan, gaji, umur, lamaBekerja, jenisKelamin;

        getline(ss, nama, ';');
        getline(ss, departmen, ';');
        getline(ss, jabatan, ';');
        getline(ss, gaji, ';');
        getline(ss, umur, ';');
        getline(ss, lamaBekerja, ';');
        getline(ss, jenisKelamin, ';');

        bacadata.SetNamaKaryawan(nama);
        bacadata.Department::SetNama(departmen);
        bacadata.SetJabatan(jabatan);
        bacadata.SetGaji(stoi(gaji));
        bacadata.SetUmur(stoi(umur));
        bacadata.SetLamaBekerja(stoi(lamaBekerja));
        bacadata.SetJenisKelamin(jenisKelamin[0]);
        
    }

    file.close();
    return true;
}




int main () {


        


        Pengembang pengembang01;
        Pemasaran pemasaran01;
        Keuangan keuangan01;
        Peneliti peneliti01;

        Karyawan* pekerja01 = &peneliti01;
    
        
        


    if (readCSV(*pekerja01)) {
        pekerja01->Jobdesc();
    } else {
        cout << "Gagal membaca data dari file CSV." << endl;
    }

    

    
    
}