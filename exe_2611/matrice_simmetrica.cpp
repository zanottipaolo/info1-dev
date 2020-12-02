#include <iostream>

using namespace std;

const int DIM_MAX = 10;

bool IsSymmetric(float matrice[][DIM_MAX], int dim);

int main(){
    float matrice [DIM_MAX][DIM_MAX];
    int dim_utente;

    // Current size
    do{
        cout << "Inserisci la dimensione della matrice (0 < dim <= " << DIM_MAX << "): "; cin >> dim_utente;
    }while(dim_utente <= 0 || dim_utente > DIM_MAX);

    cout << endl;

    // Input
    for(int i=0; i<dim_utente; i++){
        for(int j=0; j<dim_utente; j++){
            cout << "Inserisci un valore alla pos. (" << i+1 << " ; " << j+1 << "): "; cin >> matrice[i][j];
        }
    }

    if(IsSymmetric(matrice, dim_utente))
        cout << "\nLa matrice è simmetrica." << endl;
    else{
        for(int i=0; i<dim_utente; i++)
            matrice[i][i] = 0;      // diagonal to 0
    }

    return 0;
}

bool IsSymmetric(float matrice[][DIM_MAX], int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            if(matrice[i][j] != matrice[j][i])
                return false;
        }
    }
    return true;
}