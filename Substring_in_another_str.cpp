#include <iostream>
#include <cstring>
using namespace std;

// menentukan apakah potongan kata terdapat pada kata lainnya

bool Ispresent(char* str, char* substr){
    
    int size_a = strlen(str);
    int size_b = strlen(substr);
    
    for(int i = 0; i < size_a - size_b; ++i){
        for(int j; j < size_b; ++j){
            if(str[i+j] != substr[j]){
                continue;
            }
            else {
                return true;
            }
        }
    }

    return false;
}

int main() {
    
    char word1[] = "robotika";
    char word2[] = "robot";
    
    if(Ispresent(word1,word2)){
        cout << "Present" <<'\n';
    }
    else {
        cout <<"Not Present"<<'\n';
    }
   
   
   
   
   
    return 0;
}