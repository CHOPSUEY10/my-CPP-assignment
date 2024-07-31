#include<vector>
#include<string>
#include <iostream>
using namespace std;



int main() {

    // 2D vector 
    
    vector<string> kata =  {"Teknik","Robotika","KapalCepat", "Juara"};
    vector<vector<char>> tts(kata.size());
    int size = tts.size();
    
    for(int i = 0; i < size ; ++i){
        tts[i] = vector<char>(kata[i].begin(),kata[i].end());
        
        for(const auto& it : kata[i])
            tts[i].push_back(it);
        
        
    }
    
    
    for(int i = 0; i < size; ++i){
        int _size_ = kata[i].length();

       for(int j = 0; j < _size_ ; ++j){
           cout << tts[i][j] << " " ;
       }
       
        cout << endl;      
    }
    
    



   
    return 0;
}