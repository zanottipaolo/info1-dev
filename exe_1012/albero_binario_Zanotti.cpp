#include <iostream>

using namespace std;

struct nodo{
    int dato;
    struct nodo *left, *right;
};

nodo *NuovoNodo(int dato);

void RiempiAlbero(nodo *&root);

void StampaFoglie(nodo *root);

int main(){
    nodo *root = NULL;

    cout << endl;
    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2021 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl << endl;

    RiempiAlbero(root);

    StampaFoglie(root);

    return 0;
}

nodo *NuovoNodo(int dato){
    nodo *temp = new nodo;
    temp->dato = dato;
    temp->left = temp->right = NULL;

    return temp;
}

//TODO: recursive
void RiempiAlbero(nodo *&root){
    root = NuovoNodo(10);
    root->left = NuovoNodo(9);
    root->right = NuovoNodo(8);
    root->left->left = NuovoNodo(5);
    root->left->right = NuovoNodo(4);
    root->right->left = NuovoNodo(6);
    root->right->right = NuovoNodo(2);
}

void StampaFoglie(nodo *root){
    if(!root)
        return;
    
    if(!root->left && !root->right){
        cout << "Foglia: " << root->dato << endl;
        
        return;
    }

    if(root->left){
        StampaFoglie(root->left);
    }

    if(root->right){
        StampaFoglie(root->right);
    }
}