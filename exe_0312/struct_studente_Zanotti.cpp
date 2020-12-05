#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STRING = 100, MAX_STUDENTI = 3, MAX_ESAMI = 7, MAX_MATRICOLA = 7;

struct Studente{
    char matricola[MAX_MATRICOLA];
    char nome[MAX_STRING], cognome[MAX_STRING];
};

struct Esame{
    char matricola[MAX_MATRICOLA];
    char nome_esame[MAX_STRING];
    float voto;
};

void ClearScreen();

void InserimentoStudenti(Studente allievo[], bool flag);

void InserimentoVoti(Esame libretto[], Studente allievo[], bool flag);

float CalcoloMedia(Esame libretto[], char ricerca_matricola[]);

bool IfExists(Studente allievo[], char matricola[]);

int main(){
    Studente allievo[MAX_STUDENTI];
    Esame libretto[MAX_ESAMI];
    char ricerca_matricola[MAX_MATRICOLA];
    bool flag;

    cout << endl;
    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2020 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl << endl;

    // Input Studenti
    cout << "\t# STUDENTI #" << endl << endl;
    cout << "Inserisci " << MAX_STUDENTI << " studenti" << endl << endl;

    InserimentoStudenti(allievo, flag);

    cout << endl;

    // Input Esami
    cout << "\t# ESAMI #" << endl << endl;
    cout << "Inserisci " << MAX_ESAMI << " esami" << endl << endl;

    InserimentoVoti(libretto, allievo, flag);

    ClearScreen();

    // AVG
    cout << "Di quale studente vuoi calcolare la media dei voti?" << endl;

    do{
        cout << "Inserisci la matricola: "; cin.getline(ricerca_matricola, MAX_MATRICOLA, '\n');

        flag = IfExists(allievo, ricerca_matricola);

        if(ricerca_matricola[0] != '\0' && flag)    // Studente OK
            cout << "\nMedia: " << CalcoloMedia(libretto, ricerca_matricola) << endl << endl;
        else if(ricerca_matricola[0] == '\0' && !flag)  // Empty string
                cout << "\n\t\t[x] Inserire un valore valido" << endl << endl;
        else    // Wrong input
            cout << "\n\t\t[x] Studente non trovato, riprovare..." << endl << endl;
    }while(!flag);

    return 0;
}

void ClearScreen(){
    #ifdef  WINDOWS
        system("CLS");
    #else
        system("clear");
    #endif
}

void InserimentoStudenti(Studente allievo[], bool flag){
    char temp_matricola[MAX_MATRICOLA];

    for(int i=0; i<MAX_STUDENTI; i++){
        // Matricola
        cout << "\t************************" << endl;
        do{
            cout << "\t*  " << i+1 << ". Matricola: "; cin.getline(temp_matricola, MAX_MATRICOLA, '\n');
            
            flag = IfExists(allievo, temp_matricola);

            if(temp_matricola[0] == '\0' && flag){  // Empty string
                cout << "\t*\n\t*\t  [x] Inserire un valore valido" << endl;
                cout << "\t*" << endl;
            }
            else if(temp_matricola[0] != '\0' && flag){ // Student already inserted
                cout << "\t*\n\t*\t  [x] Studente già inserito, riprovare..." << endl;
                cout << "\t*" << endl;
            }
        }while(flag);

        // temp_matricola OK -> allievo[i].matricola == temp_matricola
        strcpy(allievo[i].matricola, temp_matricola);

        // Nome
        cout << "\t*  " << i+1 << ". Nome: "; cin.getline(allievo[i].nome, MAX_STRING, '\n');

        // Cognome
        cout << "\t*  " << i+1 << ". Cognome: "; cin.getline(allievo[i].cognome, MAX_STRING, '\n');
        cout << "\t************************" << endl;
        cout << endl << endl;
    }
}

void InserimentoVoti(Esame libretto[], Studente allievo[], bool flag){
    for(int i=0; i<MAX_ESAMI; i++){
        // Matricola
        cout << "\t************************" << endl;
        do{
            cout << "\t*  " << i+1 << ". Matricola: "; cin.getline(libretto[i].matricola, MAX_MATRICOLA, '\n');

            flag = IfExists(allievo, libretto[i].matricola);

            if(libretto[i].matricola[0] != '\0' && !flag){  // Wrong input
                cout << "\t*\n\t*\t  [x] Studende non riconosciuto, riprovare..." << endl;
                cout << "\t*" << endl;
            }
            else if(libretto[i].matricola[0] == '\0' && !flag){ // Empty string
                cout << "\t*\n\t*\t  [x] Inserire un valore valido" << endl;
                cout << "\t*" << endl;
            }
        }while(!flag);

        // Esame
        cout << "\t*  " << i+1 << ". Esame: "; cin.getline(libretto[i].nome_esame, MAX_STRING, '\n');

        // Voto
        do{
            cout << "\t*  " << i+1 << ". Voto: "; cin >> libretto[i].voto;

            if(libretto[i].voto < 18 || libretto[i].voto > 30){ // Wrong input
                cout << "\t*\n\t*\t  [x] Voto non ammesso (18 <= Voto <= 30), riprovare..." << endl;
                cout << "\t*" << endl;
            }
        }while(libretto[i].voto < 18 || libretto[i].voto > 30);
        cout << "\t************************" << endl;
        cout << endl << endl;

        cin.ignore(1000, '\n'); // Because next input (Matricola) requires cin.getline()
    }
}

float CalcoloMedia(Esame libretto[], char ricerca_matricola[]){
    float media = 0, somma = 0;
    int numero_esami = 0;

    for(int i=0; i<MAX_ESAMI; i++){
        // libretto[i].matricola == ricerca_matricola
        if(strcmp(libretto[i].matricola, ricerca_matricola) == 0){
            somma += libretto[i].voto;
            numero_esami++;
        }
    }
    media = (float)somma / numero_esami;

    if(somma == 0 && numero_esami == 0)
        media = 0;  // Instead of "NaN"

    return media;
}

bool IfExists(Studente allievo[], char matricola[]){
    for(int i=0; i<MAX_STUDENTI; i++){
        // allievo[i].matricola == matricola
        if(strcmp(allievo[i].matricola, matricola) == 0)
            return true;    // Student exists
    }
    return false;
}