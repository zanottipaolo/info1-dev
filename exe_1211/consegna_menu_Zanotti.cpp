#include <iostream>

using namespace std;

int main(){
    int n1, n2, n3;
    char scelta;
    int somma = 0, prodotto = 0, differenza = 0;
    double divisione = 0;

    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2020 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl;

    cout << "Ciao!" << endl;
    cout << "Inserisci 3 numeri interi [1-100]\n" << endl;
    
    //Input validation
    do{
        cout << "Primo numero: "; cin >> n1;
    }while(n1 < 1 || n1 > 100);

    do{
        cout << "Secondo numero: "; cin >> n2;
    }while(n2 < 1 || n2 > 100);

    do{
        cout << "Terzo numero: "; cin >> n3;
    }while(n3 < 1 || n3 > 100);

    cout << endl;

    //Menu (Uppercase and lowercase both accepted)
    do{
        cout << "A) # Somma tra n1, n2, n3" << endl;
        cout << "B) # Prodotto tra n1 e n2" << endl;
        cout << "C) # Sottrazione tra n3 e n1" << endl;
        cout << "D) # Divisione tra n1 e n2" << endl;
        cout << "X) # Uscita dal programma" << endl;

        cout << endl;

        cout << "Cosa vuoi fare? "; cin >> scelta;

        if(scelta == 'a' || scelta == 'A'){
            system("clear");

            cout << "n1: " << n1 << endl;
            cout << "n2: " << n2 << endl;
            cout << "n3: " << n3 << endl;

            cout << endl;

            somma = n1 + n2 + n3;

            cout << "La somma tra " << n1 << ", " << n2 << " e " << n3 <<  " è: " << somma << endl;

            cout << endl;
            cout << "-------------------------------------------------" << endl;
            cout << endl;
        }
        else if(scelta == 'b' || scelta == 'B'){
            system("clear");

            cout << "n1: " << n1 << endl;
            cout << "n2: " << n2 << endl;

            cout << endl;

            prodotto = n1 * n2;

            cout << "Il prodotto tra " << n1 << " e " << n2 << " è: " << prodotto << endl;

            cout << endl;
            cout << "-------------------------------------------------" << endl;
            cout << endl;
        }
        else if(scelta == 'c' || scelta == 'C'){
            system("clear");

            cout << "n3: " << n3 << endl;
            cout << "n1: " << n1 << endl;

            cout << endl;

            differenza = n3 -n1;

            cout << "La differenza tra " << n3 << " e " << n1 << " è: " << differenza << endl;

            cout << endl;
            cout << "-------------------------------------------------" << endl;
            cout << endl;
        }
        else if(scelta == 'd' || scelta == 'D'){
            system("clear");

            cout << "n1: " << n1 << endl;
            cout << "n2: " << n2 << endl;

            cout << endl;

            divisione = ((float)n1) / n2;
            cout << "La divisione tra " << n1 << " e " << n2 << " è: " << divisione << endl;

            cout << endl;
            cout << "-------------------------------------------------" << endl;
            cout << endl;
        }
        else
            system("clear");

    }while(scelta != 'x' && scelta != 'X');      

    // With the || operator
    //  # if scelta == x  ->  while(false || true) ->  while(true) - Endless loop
    //  # if scelta == X  ->  while(true || false) ->  while(true) - Endless loop

    cout << "Hai lasciato il programma..." << endl;

    return 0;
}