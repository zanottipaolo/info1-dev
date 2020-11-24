#include <iostream>

using namespace std;

int Moda(int *frequenze, int MAX);

int main(){
    const int MAX = 10;
    
    int valore;
    int frequenze[MAX+1];

    for(int i=0; i<MAX+1; i++){
        frequenze[i] = 0;
    }

    cout << "Inserisci un valore [1, " << MAX << "]: " << endl;

    // Input validation && Count the number of occurrences 
    do{
        cout << "Valore: "; cin >> valore;

        if(valore >= 1 || valore <= MAX){
            frequenze[valore]++;
        }
    }while(valore != 0);

    cout << endl;

    cout << "La moda è: " << Moda(frequenze, MAX) << "." << endl;

    return 0;
}

int Moda(int *frequenze, int MAX){
    int valore_moda = 0;
    int occorrenza = 0;

    // Set the max number
    for(int i=1; i<MAX+1; i++){
        if(frequenze[i] > occorrenza){
            occorrenza = frequenze[i];
            valore_moda = i;
        }
    }

    return valore_moda;
}