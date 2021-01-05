#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct nodo{
    int dato;
    struct nodo *left, *right;
};

nodo *NuovoNodo(int dato);

void RiempiAlbero(nodo *&root, int MAX);

void StampaFoglie(nodo *root);

int main(){
    const int MAX = 100;
    nodo *root = NULL;

    cout << endl;
    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2021 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl;

    RiempiAlbero(root, MAX);

    StampaFoglie(root);

    return 0;
}

// Generate the node
nodo *NuovoNodo(int dato){
    nodo *temp = new nodo;
    temp->dato = dato;
    temp->left = temp->right = NULL;

    return temp;
}

// Add rand items (range: [1-100])
void RiempiAlbero(nodo *&root, int MAX){
    srand((unsigned int)time(0));
    
    root = NuovoNodo(rand() % MAX + 1);
    root->left = NuovoNodo(rand() % MAX + 1);
    root->right = NuovoNodo(rand() % MAX + 1);
    root->left->left = NuovoNodo(rand() % MAX + 1);
    root->left->right = NuovoNodo(rand() % MAX + 1);
    root->right->left = NuovoNodo(rand() % MAX + 1);
    root->right->right = NuovoNodo(rand() % MAX + 1);
}

// Print leaves (recursive)
void StampaFoglie(nodo *root){

    // Check if the node is null
    if(!root)
        return;
    
    // Check if the node is a leaf (left->NULL && right->NULL)
    if(!root->left && !root->right){
        cout << "\t* Foglia dell'albero binario: " << root->dato << endl << endl;
        
        return;
    }

    // Check if the left child of node exists
    if(root->left){
        StampaFoglie(root->left);
    }

    // Check if the right child of node exists
    if(root->right){
        StampaFoglie(root->right);
    }
}