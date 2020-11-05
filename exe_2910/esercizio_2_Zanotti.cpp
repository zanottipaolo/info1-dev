#include <iostream>

using namespace std;

int main(){
    int primo_numero, secondo_numero, terzo_numero;
    char scelta;

    // Ciclo do-while per creare un menù di scelta costante dell'azione da fare.
    do{
        system("clear");    // per pulire la console

        // Per Windows
        // system("CLS");

        cout << "Inserisci 3 numeri interi: " << endl;
        cout << endl;
        cout << endl;
        cout << "Numero 1) "; cin >> primo_numero;
        cout << endl;
        cout << "Numero 2) "; cin >> secondo_numero;
        cout << endl;
        cout << "Numero 3) "; cin >> terzo_numero;
        cout << endl;
        cout << endl;
        cout << "Numeri inseriti in ordine crescente: " << endl;

        // Algoritmo per disporre i numeri in ordine crescente
        if (primo_numero >= secondo_numero){
            if (secondo_numero >= terzo_numero){
                if (primo_numero >= terzo_numero)
                    cout << terzo_numero << " - " << secondo_numero << " - " << primo_numero << endl;
            }
            else{
                if (primo_numero >= terzo_numero)
                    cout << secondo_numero << " - " << terzo_numero << " - " << primo_numero << endl;
                else
                    cout << secondo_numero << " - " << primo_numero << " - " << terzo_numero << endl;
            }
        }
        else{
            if (secondo_numero >= terzo_numero){
                if (primo_numero >= terzo_numero)
                    cout << terzo_numero << " - " << primo_numero << " - " << secondo_numero << endl;
                else
                    cout << primo_numero << " - " << terzo_numero << " - " << secondo_numero << endl;
            }
            else
                cout << primo_numero << " - " << secondo_numero << " - " << terzo_numero << endl;
        }

        cout << endl;
        cout << endl;
        cout << "Ripetere l'esercizio? [s/n]: "; cin >> scelta;
    }while(scelta != 'n');

    system("clear");    // per pulire la console

    // Per Windows
    // system("CLS");

    cout << "Hai lasciato il programma." << endl;
    cout << endl;
    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2020 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl;

    return 0;
}
