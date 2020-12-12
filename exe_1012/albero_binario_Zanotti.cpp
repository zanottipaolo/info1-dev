#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *left, *right;
};

nodo *NuovoNodo(int dato);

void RiempiAlbero(nodo *root);

void StampaFoglie(nodo *root);

int main(){
    nodo *root = NULL;

    cout << endl;
    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2020 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl << endl;

    return 0;
}

nodo *NuovoNodo(int dato){
    nodo *temp = new nodo;
    temp->dato = dato;
    temp->left = temp->right = NULL;

    return temp;
}

void RiempiAlbero(nodo *root){
}

void StampaFoglie(nodo *root){

}