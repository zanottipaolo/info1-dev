#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void GeneraArray(int array[], int MAX, int NUMERO_MAX);

void OrdinaArray(int array[], int MAX);

int ScegliNumero(int array[], int MAX, int NUMERO_MAX);

int RicercaDicotomica(int array[], int left, int right, int valore);

int main(){
    const int MAX = 50;
    const int NUMERO_MAX = 100;
    int array[MAX], scelta_ricerca, pos;

    GeneraArray(array, MAX, NUMERO_MAX);
    OrdinaArray(array, MAX);
    scelta_ricerca = ScegliNumero(array, MAX, NUMERO_MAX);

    pos = RicercaDicotomica(array, 0, MAX-1, scelta_ricerca);

    if(pos == -1)
        cout << "\nElemento non trovato" << endl << endl;
    else
        cout << "\nL'elemento cercato si trova nella posizione: " << pos << endl << endl;

    return 0;
}

void GeneraArray(int array[], int MAX, int NUMERO_MAX){
    cout << "# Sto generando l'array..." << endl << endl;
    
    srand((unsigned int)time(0));

    for(int i=0; i<MAX; i++){
        array[i] = rand() % NUMERO_MAX + 1;
        for(int j=0; j<MAX; j++){   // Different elements
            if(array[i] == array[j] && i != j){
                array[i] = rand() % NUMERO_MAX + 1;
                j = -1;
            }
        }
    }
    
    cout << "# Array generato correttamente!" << endl << endl;
}

void OrdinaArray(int array[], int MAX){
    int temp = 0;

    cout << "# Sto ordinando l'array..." << endl << endl;

    // Bubble sort mod.
    for(int i=0; i<MAX-1; i++){
        for(int j=i+1; j<MAX; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    cout << "# Array ordinato correttamente in modo crescente!" << endl << endl;
}

int ScegliNumero(int array[], int MAX, int NUMERO_MAX){
    int numero = 0;

    // Input validation (1 <= numero <= 100)
    do{
        cout << "\tInserisci un numero da cercare [1-" << NUMERO_MAX << "]: "; cin >> numero;

        if(numero > 100)
            cout << "\n\t\t[x] Numero troppo grande, riprova..." << endl << endl;
        else if(numero < 1)
            cout << "\n\t\t[x] Numero troppo piccolo, riprova..." << endl << endl;
    }while(numero < 1 || numero > 100);

    return numero;
}

int RicercaDicotomica(int array[], int left, int right, int valore){
    int middle;

    // Not found
    if(left > right)
        return -1;

    middle = (left + right) / 2;

    // Right side
    if(array[middle] < valore)
        return RicercaDicotomica(array, middle+1, right, valore);
        
    // Left side
    else if(array[middle] > valore)
        return RicercaDicotomica(array, left, middle-1, valore);
    
    // If array[middle] == valore
    return middle;
}