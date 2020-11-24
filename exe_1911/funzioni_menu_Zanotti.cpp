#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void RiempiArray(int *rand_array, int SIZE, int MAX);

void VisualizzazioneArray(int *rand_array, int SIZE);

float Media(int *rand_array, int SIZE);

int Massimo(int *rand_array, int SIZE);

int Minimo(int *rand_array, int SIZE, int MAX);

void DistanzaMedia(int *rand_array, int SIZE);

int Moda(int *rand_array, int SIZE, int MAX);

int main(){
    const int SIZE = 50;
    const int MAX = 100;
    int rand_array[SIZE];
    char scelta;

    RiempiArray(rand_array, SIZE, MAX);

    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2020 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl;

    // Menu
    do{
        cout << "\t** MENU **\n" << endl;
        cout << "# 0. Visualizzare gli elementi dell'array." << endl;
        cout << "# 1. Calcolare la media." << endl;
        cout << "# 2. Visualizzare il massimo." << endl;
        cout << "# 3. Visualizzare il minimo." << endl;
        cout << "# 4. Rigenerare l'array." << endl;
        cout << "# 5. Visualizzare i valori che distano meno di 4 dalla media." << endl;
        cout << "# 6. Calcolare la moda." << endl;
        cout << "# 7. Uscire dal programma.\n" << endl;
        cout << "Cosa vuoi fare? "; cin >> scelta;

        if(scelta == '0'){
            system("clear");

            VisualizzazioneArray(rand_array, SIZE);
            cout << "---------------------------------------------\n\n" << endl;
        }
        else if(scelta == '1'){
            system("clear");

            cout << "La media è: " << Media(rand_array, SIZE) << "\n\n" << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }
        else if(scelta == '2'){
            system("clear");

            cout << "Il massimo è: " << Massimo(rand_array, SIZE) << "\n\n" << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }
        else if(scelta == '3'){
            system("clear");

            cout << "Il minimo è: " << Minimo(rand_array, SIZE, MAX) << "\n\n" << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }
        else if(scelta == '4'){
            system("clear");

            RiempiArray(rand_array, SIZE, MAX);

            cout << "L'array è stato rigenerato.\n\n" << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }
        else if(scelta == '5'){
            system("clear");

            DistanzaMedia(rand_array, SIZE);
            cout << "---------------------------------------------\n\n" << endl;
        }
        else if(scelta == '6'){
            system("clear");

            cout << "La moda è: " << Moda(rand_array, SIZE, MAX) << "\n\n" << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }
        else if(scelta == '7'){
            system("clear");

            cout << "Hai lasciato il programma...\n\n" << endl;
        }
    }while(scelta != '7');

    return 0;
}

void RiempiArray(int *rand_array, int SIZE, int MAX){
    srand((unsigned int)time(0));

    // Range [1-MAX(100)]
    for(int i=0; i<SIZE; i++){
        rand_array[i] = rand() % MAX + 1;
    }
}

void VisualizzazioneArray(int *rand_array, int SIZE){
    for(int i=0; i<SIZE; i++)
        cout << rand_array[i] << "  ";
    
    cout << endl;
    cout << endl;
}

float Media(int *rand_array, int SIZE){
    int somma = 0;
    float valore_media;

    for(int i=0; i<SIZE; i++){
        somma += rand_array[i];
    }

    valore_media = ((float)somma) / SIZE;

    return valore_media;
}

int Massimo(int *rand_array, int SIZE){
    int valore_massimo = 0;

    for(int i=0; i<SIZE; i++){
        if(rand_array[i] > valore_massimo)
            valore_massimo = rand_array[i];
    }

    return valore_massimo;
}

int Minimo(int *rand_array, int SIZE, int MAX){
    int valore_minimo = MAX;

    for(int i=0; i<SIZE; i++){
        if(rand_array[i] < valore_minimo)
            valore_minimo = rand_array[i];
    }

    return valore_minimo;
}

void DistanzaMedia(int *rand_array, int SIZE){
    float valore_media = Media(rand_array, SIZE);

    cout << "I valori che distano meno di 4 dalla media sono: " << endl;
    
    for(int i=0; i<SIZE; i++){
        if(abs(valore_media - rand_array[i]) < 4)
            cout << rand_array[i] << "  "; 
    }

    cout << endl;
    cout << endl;
}

int Moda(int *rand_array, int SIZE, int MAX){
    int occorrenza = 0;
    int valore_moda = 0;
    int frequenze_array[MAX+1]; // n. of elements = value of the big number in the main array (MAX) + 1
    int rand_array_value = 0;

    // Set each element of the array to 0
    for(int i=0; i<MAX+1; i++){
        frequenze_array[i] = 0;
    }

    // Count the number of occurrences 
    for(int i=0; i<SIZE; i++){
        rand_array_value = rand_array[i];
        frequenze_array[rand_array_value]++;
    }

    // Set the max number
    for(int i=1; i<MAX+1; i++){
        if(frequenze_array[i] > occorrenza){
            occorrenza = frequenze_array[i];
            valore_moda = i;
        }
    }

    return valore_moda;
}