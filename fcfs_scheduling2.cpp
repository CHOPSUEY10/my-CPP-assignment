#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi proses
struct Process {
    string Nama;
    int Bandwidth;
    int Jarak;
    int Waktutunggu;
    int Waktupenyelesaian;
    Process* next;
};
/*

Penerapan algoritma FCFS scheduler untuk pembagian bandwidth setiap komputer

- Urutan pembagian bandwidth berdasarkan jarak komputer ke router
- Komputer dengan jarak terdekat, akan mendapatkan bandwidthnya terlebih dahulu 
- Masing-masing komputer dapat menentukan kebutuhan bandwidthnya


*/

class Bus {
private:
    Process* head = nullptr;

public:
    

    // Fungsi untuk menambahkan proses baru
    void addProcess(string Nama, int Bandwidth, int Jarak) {
        Process* newProcess = new Process{Nama, Bandwidth, Jarak, 0, 0, nullptr};
        if (!head || Jarak < head->Jarak) {
            newProcess->next = head;
            head = newProcess;
        } else {
            Process* current = head;
            while (current->next && current->next->Jarak <= Jarak) {
                current = current->next;
            }
            newProcess->next = current->next;
            current->next = newProcess;
        }
    }

    // Fungsi untuk menghitung waktu tunggu dan turnaround
    void calculateTimes() {
        if (!head) return;

        int currentTime = head->Jarak;
        Process* current = head;

        while (current) {
            if (currentTime < current->Jarak) {
                currentTime = current->Jarak;
            }

            current->Waktutunggu = currentTime - current->Jarak;
            current->Waktupenyelesaian = current->Waktutunggu + current->Bandwidth;

            currentTime += current->Bandwidth;
            current = current->next;
        }
    }

    // Fungsi untuk menampilkan hasil penjadwalan
    void displaySchedule() {
        Process* current = head;
        cout << "Pengiriman Data\tBandwidth\tJarak\tWaktu tunggu\tWaktu penyelesaian\n";
        while (current) {
            cout << current->Nama << "\t" << current->Bandwidth << "\t\t"
                 << current->Jarak << "\t\t" << current->Waktutunggu << "\t\t"
                 << current->Waktupenyelesaian << "\n";
            current = current->next;
        }
    }

    // Fungsi untuk menghitung rata-rata waktu tunggu dan turnaround
    void displayAverageTimes() {
        int totalWaitingTime = 0, totalTurnaroundTime = 0, count = 0;
        Process* current = head;

        while (current) {
            totalWaitingTime += current->Waktutunggu;
            totalTurnaroundTime += current->Waktupenyelesaian;
            count++;
            current = current->next;
        }

        if (count > 0) {
            cout << "Average Waiting Time: " << (float)totalWaitingTime / count << endl;
            cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / count << endl;
        }
    }
};

int main() {
    Bus scheduler;

    // Menambahkan beberapa computer
    scheduler.addProcess("Computer1", 10, 0);
    scheduler.addProcess("Computer2", 5, 3);
    scheduler.addProcess("Computer3", 8, 2);

    // Menghitung waktu
    scheduler.calculateTimes();

    // Menampilkan hasil penjadwalan
    scheduler.displaySchedule();

    // Menampilkan rata-rata waktu
    scheduler.displayAverageTimes();

    return 0;
}