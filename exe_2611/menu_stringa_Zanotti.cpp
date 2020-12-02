#include <iostream>

using namespace std;

int StrLen(char frase[]);

void Stampa(char frase[], int lunghezza);

void StampaReverse(char frase[], int lunghezza);

void StampaMaiusc(char frase[], int lunghezza);

void StampaSenzaSpazi(char frase[], int lunghezza);

int ContaParole(char frase[], int lunghezza);

void SostituzioneCarattere(char frase[], int lunghezza, char carattere_prima, char carattere_dopo);

int RicorrenzaLettera(char frase[], int lunghezza, char lettera);

int main(){
    const int MAX = 50;
    char scelta, frase[MAX], lettera, carattere_prima, carattere_dopo;
    int lunghezza = 0;

    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2020 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl;
            
    cout << "Inserisci una frase: "; cin.getline(frase, MAX, '\n');
    lunghezza = StrLen(frase);
        
    cout << endl;

    // Menu
    do{
        cout << "\t** MENU **\n" << endl;
        cout << "# 1. Stampa la frase." << endl;
        cout << "# 2. Stampa la frase invertita." << endl;
        cout << "# 3. Stampa la frase in maiuscolo." << endl;
        cout << "# 4. Stampa la frase senza gli spazi." << endl;
        cout << "# 5. Conta il numero di parole presenti." << endl;
        cout << "# 6. Sostituisci un carattere." << endl;
        cout << "# 7. Ricorrenza di una determinata lettera (sia maiuscola che minuscola)" << endl;
        cout << "# 8. Esci dal programma.\n" << endl;
        cout << "Cosa vuoi fare? "; cin >> scelta;

        if(scelta == '1'){
            system("clear");
            Stampa(frase, lunghezza);
            cout << endl;
            cout << "---------------------------------------------\n\n" << endl;

        }else if(scelta == '2'){
            system("clear");
            StampaReverse(frase, lunghezza);
            cout << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }else if(scelta == '3'){
            system("clear");
            StampaMaiusc(frase, lunghezza);
            cout << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }else if(scelta == '4'){
            system("clear");
            StampaSenzaSpazi(frase, lunghezza);
            cout << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }else if(scelta == '5'){
            system("clear");
            cout << "Il numero di parole è: " << ContaParole(frase, lunghezza);
            cout << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }else if(scelta == '6'){
            system("clear");
            cout << "Che carattere vuoi sostituire? "; cin >> carattere_prima;
            cout << endl;
            cout << "Che carattere vuoi inserire al suo posto? "; cin >> carattere_dopo;
            cout << endl;
            SostituzioneCarattere(frase, lunghezza, carattere_prima, carattere_dopo);
            cout << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }else if(scelta == '7'){
            system("clear");

            // Input validation: [a-z A-Z]
            do{
                cout << "Che lettera vuoi cercare? "; cin >> lettera;
            }while((lettera < 'a' || lettera > 'z') && (lettera < 'A' || lettera > 'Z'));

            cout << endl;
            cout << "Il numero di ricorrenze è: " << RicorrenzaLettera(frase, lunghezza, lettera);
            cout << endl;
            cout << "---------------------------------------------\n\n" << endl;
        }else if(scelta == '8'){
            system("clear");

            cout << "Hai lasciato il programma...\n\n" << endl;
        }
    }while(scelta != '8');

    return 0;
}

int StrLen(char frase[]){
    int lunghezza = 0;

    for(int i=0; frase[i]!='\0'; i++)
        lunghezza++;
    return lunghezza;
}

void Stampa(char frase[], int lunghezza){
    for(int i=0; i<lunghezza; i++)
        cout << frase[i];
}

void StampaReverse(char frase[], int lunghezza){
    for(int i=lunghezza-1; i>=0; i--)
        cout << frase[i];
}

void StampaMaiusc(char frase[], int lunghezza){
    // frase[] can't be changed during the execution (because it's just a print), so I work on frase_maiusc[]
    char frase_maiusc[lunghezza];

    for(int i=0; i<lunghezza; i++){
        frase_maiusc[i] = frase[i];
        if(frase[i] >= 'a' && frase[i] <= 'z')  // Check lowercase
            frase_maiusc[i] -= 32;
        cout << frase_maiusc[i];
    }
}

void StampaSenzaSpazi(char frase[], int lunghezza){
    for(int i=0; i<lunghezza; i++){
        if(frase[i] != 32)  // 32 -> space ASCII
            cout << frase[i];
    }
}

int ContaParole(char frase[], int lunghezza){
    int numero_parole = 0;

    for(int i=0; i<lunghezza; i++){
        // If the next char is not a letter
        if(!((frase[i+1] >= 'a' && frase[i+1] <= 'z') || (frase[i+1] >= 'A' && frase[i+1] <= 'Z'))){
            // If the current char is a letter
            if(((frase[i] >= 'a' && frase[i] <= 'z') || (frase[i] >= 'A' && frase[i] <= 'Z')))
                numero_parole++;
        }
    }
    return numero_parole;
}

void SostituzioneCarattere(char frase[], int lunghezza, char carattere_prima, char carattere_dopo){
    bool check = false;

    for(int i=0; i<lunghezza; i++){
        if(frase[i] == carattere_prima){
            frase[i] = carattere_dopo;
            check = true;
        }
    }

    if(check){
        Stampa(frase, lunghezza);
    }else{
        cout << "Carattere non trovato..." << endl;
    }
}

int RicorrenzaLettera(char frase[], int lunghezza, char lettera){
    int numero_ricorrenze = 0;

    for(int i=0; i<lunghezza; i++){
        // If a=a || a=A || A=a || A=A
        if(frase[i] == lettera || frase[i] == lettera-32 || frase[i]-32 == lettera || frase[i]-32 == lettera-32)
            numero_ricorrenze++;
    }
    return numero_ricorrenze;
}