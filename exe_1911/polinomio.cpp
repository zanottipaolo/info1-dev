#include <iostream>
#include <cmath>

using namespace std;

int main(){
    const int GRADO_MASSIMO = 50;

    int grado, x;
    long int y = 0;
    double array_coef[GRADO_MASSIMO];

    do{
        cout << "Inserisci il grado del polinomio (0 <= grado <= " << GRADO_MASSIMO << "): "; cin >> grado;
    }while(grado < 0 || grado >= GRADO_MASSIMO);

    cout << endl;
    
    cout << "Ora inserisci il punto X in cui valutare il polinomio: "; cin >> x;

    cout << endl;
    cout << endl;

    for(int i=0; i<=grado; i++){
        cout << "Coeff " << i << " = "; cin >> array_coef[i]; 
    }

    for(int i=grado; i>=0; i--){
        y += pow(x, i) * array_coef[i];
    }

    cout << endl;

    cout << "Valore finale: " << y << endl;

    return 0;
}