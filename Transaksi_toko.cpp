#include <iostream>
#include <fstream> 
using namespace std;


class belanja{
    protected :
        string Nama_barang;
        double Jumlah_barang;
        double Harga_barang;
  
        string GetNamaBarang(){
            return Nama_barang;
        }
        
        double GetJumlahBarang(){
            return Jumlah_barang;
        }
        
        double GetHargaBarang(){
            return Harga_barang;
        }

    public:
        string SetNamaBarang(string __Nama){
            Nama_barang = __Nama;
            return Nama_barang;
        }

        double SetJumlahBarang(double __Jumlah){
            Jumlah_barang = __Jumlah;
            return Jumlah_barang;
        }

        double SetHargaBarang(double __Harga){
            Harga_barang = __Harga;
            return Harga_barang;
        }

        
};


class Transaksi : public belanja{

    private:

        double Total_harga;
        float Diskon_belanja = 0.8;

    public : 


        double GetTotalHarga(){
            
            Total_harga = Jumlah_barang * Harga_barang;
            
            if(Total_harga >= 50000 && Total_harga < 100000){
                Total_harga *= Diskon_belanja;
            }
            else if (Total_harga >= 100000){
                double pengurangan  = Total_harga * (Diskon_belanja - 0.64);
                
                Total_harga -= pengurangan;
                
            }


            return Total_harga;
            
        }

        void Simpan_data_transaksi(){
            fstream Simpan_data;
            Simpan_data.open("Daftar_Transaksi_Toko.txt", ios::app);

            if(Simpan_data.is_open()){
                Simpan_data <<"================================="<<'\n';
                Simpan_data <<"Nama Barang : "<< GetNamaBarang() <<'\n';
                Simpan_data <<"Jumlah Barang : "<< GetJumlahBarang() <<'\n';
                Simpan_data <<"Harga Barang : "<< GetHargaBarang() <<'\n';
                Simpan_data <<"Total Harga : "<< GetTotalHarga() <<'\n';
                Simpan_data <<"================================="<<'\n';


                Simpan_data.close();

            }

        }

        void Tampilkan_data_transaksi(){
            fstream Tampil_data;
            Tampil_data.open("Daftar_Transaksi_Toko.txt",ios::out);
            
            if(Tampil_data.is_open()){
                Tampil_data <<"================================="<<'\n';
                Tampil_data <<"Nama Barang : "<< GetNamaBarang() <<'\n';
                Tampil_data <<"Jumlah Barang : "<< GetJumlahBarang() <<'\n';
                Tampil_data <<"Harga Barang : "<< GetHargaBarang() <<'\n';
                Tampil_data <<"Total Harga : "<< GetTotalHarga() <<'\n';
                Tampil_data <<"================================="<<'\n';

                Tampil_data.close();


            }
        }

};


    


int main() {


    char menu_utama;
    Transaksi Daftar_transaksi;
   
   
    
    do{
        
        string Nama;
        unsigned int Jumlah;
        int Harga;
        
        cout << "Masukkan Nama Barang : "; getline(cin,Nama) ; cin.clear();
        cout <<"Masukkan Harga Barang : "; cin >> Jumlah ; cin.clear();
        cout <<"Masukkan Jumlah Barang : " ; cin >> Harga ;cin.clear();

        belanja transaksi01;

        transaksi01.SetNamaBarang(Nama); transaksi01.SetJumlahBarang(Jumlah); transaksi01.SetHargaBarang(Harga);

        cout <<"Total Harga: " << Daftar_transaksi.GetTotalHarga() << endl; cin.clear();

        Daftar_transaksi.Simpan_data_transaksi();

        Daftar_transaksi.Tampilkan_data_transaksi();
       
       
        cout <<"Kembali ke menu utama (y/n) : "; cin >> menu_utama; cin.clear();
        
        cout << endl;
        
    }while(menu_utama == 'Y' || menu_utama == 'y');  
    
       
    
    
    
    
    
    
    
   











    return 0;
}