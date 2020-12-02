#include <iostream>
#include <cstring>

using namespace std;

bool IsPalindrome(char parola[], int MAX, int lunghezza);

int main(){
    const int MAX = 100;
    char parola[MAX];
    int lunghezza = 0;

    cout << "Inserisci una parola: "; cin.getline(parola, MAX, '\n');
    lunghezza = strlen(parola);

    cout << endl;

    if(IsPalindrome(parola, MAX, lunghezza))
        cout << "La parola è palindroma!" << endl;
    else{
        for(int i=lunghezza-1; i>=0; i--)
            cout << parola[i];      // Reverse print
        cout << endl;
    }

    return 0;
}

bool IsPalindrome(char parola[], int MAX, int lunghezza){
    for(int i=0; i<lunghezza; i++){
        if(parola[i] != parola[lunghezza-i-1])  //-1 -> \0
            return false;
    }
    return true;
}