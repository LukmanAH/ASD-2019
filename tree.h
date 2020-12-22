#include <iostream>

using namespace std;

typedef struct data2{
	int no_penjualan;
	int kode_barang;
	int harga;
	string tanggal;
};

typedef data2 infotype3;
typedef struct tNode *add;
typedef struct tNode {
    infotype3 info3;
    add left;
    add right;
} Node;
 
typedef add BinTree;
add AlokNode (infotype3 x) {
    add node = new Node;;
    node->info3 = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void dealok (add x) {
    delete(x);
}
bool IsTreeEmpty (BinTree P){
    /* Kamus Lokal */
    /* Algoritma */
    return (P == NULL);
}

void Tree (BinTree *P,infotype3 Akar) {
    add New = AlokNode(Akar);
    if (New!=NULL) {
        if (IsTreeEmpty(&(*(*P)))) {
            (*P) = New;
            (*P)->left = NULL;
            (*P)->right = NULL;
        } else if (Akar.no_penjualan < (*P)->info3.no_penjualan) {
            Tree(&(*P)->left, Akar);
        } else if (Akar.no_penjualan > (*P)->info3.no_penjualan) {
            Tree(&(*P)->right, Akar);
        }
    } else New = NULL;
}


void InOrder (BinTree P) {
    if (IsTreeEmpty(P)) {
			
    } else {
        InOrder((P)->left);
        cout<<"No Penjualan    :";
        cout<<((P)->info3.no_penjualan);
        cout<<"\nKode Barang     :";
        cout<<(P)->info3.kode_barang;//<<" \";
        cout<<"\nHarga           :";
        cout<<(P)->info3.harga;//<<" \";
        cout<<"\nTanggal         :";
        cout<<(P)->info3.tanggal;
        InOrder((P)->right);
    }
    
    
}
