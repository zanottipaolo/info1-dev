#include <iostream>
#define pigreco 3.141592653589793238462643383279

using namespace std;

int main(){
    int angolo_gradi;
    float angolo_radianti = 0;

    do{
        cout << "Inserisci un angolo intero in gradi: ";
        cin >> angolo_gradi;
        cout << endl;

        if(angolo_gradi > 0 || angolo_gradi < 360){
            angolo_radianti = ((float) angolo_gradi) / 180 * pigreco;
            cout << "Angolo in radianti: " << angolo_radianti << endl;
        }
        else{
            cout << "Errore, valore dell'angolo non valido" << endl;
            cout << endl;
        }

    }while(angolo_gradi < 0 || angolo_gradi > 360);

    return 0;
}