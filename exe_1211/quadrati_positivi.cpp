#include <iostream>

using namespace std;

int main(){
    int numero, somma_dispari;

    //Input validation
    do{
        cout << "Inserisci un numero: "; cin >> numero;

        if(numero < 0){
            cout << endl;
            cout << "[x] Il numero deve essere positivo.\n" << endl;
        }

    }while(numero < 0);

    // Sum of first N odd numbers
    for(int i=0; i<numero; i++){
        somma_dispari += i+i+1;
    }

    cout << endl;
    cout << endl;

    cout << "Il quadrato di " << numero << " è: " << somma_dispari << endl;
    return 0;
}