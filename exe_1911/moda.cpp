#include <iostream>

using namespace std;

int moda(double *frequenze, int MAX);

int main(){
    const int MAX = 10;
    
    int valore;
    double frequenze[MAX+1];
    int contatore = 0;

    cout << "Inserisci un valore [1, " << MAX << "]: " << endl;

    do{
        cout << "Valore: "; cin >> valore;

        if(valore >= 1 || valore <= MAX){
            frequenze[valore]++;
            contatore++;
        }
    }while(valore != 0);

    contatore--;

    cout << endl;

    cout << "La moda è: " << moda(frequenze, MAX) << "." << endl;

    return 0;
}

int moda(double *frequenze, int MAX){
    int valore_moda = 0;

    for(int i=1; i<MAX+1; i++){
        if(frequenze[i] > valore_moda)
            valore_moda = frequenze[i];
    }

    return valore_moda;
}