#include <stdlib.h>
#include <iostream>
#include "doblelist.h"
#include "tree.h"
#include<ctime>

using namespace std;

typedef struct Data2{
	string id;
	string nama;
	string cp; 
}; 

int Tampil_Dist(Data2 Distributor[]){
	int pilih;
	system("cls");
	cout<<"==================================== \n";
	cout<<"|       [ DATA DISTRIBUTOR ]       |\n";
	cout<<"==================================== \n";
	
	for(int i=0; i<5; i++){
		cout<<"ID		:"<<Distributor[i].id;
		cout<<"\nNama		:"<<Distributor[i].nama;
		cout<<"\nCP		:"<<Distributor[i].cp;
		cout<<"\n--------------------------------- \n";
	}
			 
			cout<<"================================== \n";
			cout<<" 1. Kembali \n";
			cout<<" 2. Keluar \n";
			cout<<"================================== \n";
			cout<<"Masukan Pilihan [1-2] : ";
			cin>>pilih; 
			switch(pilih){
				case 1: return 1; break;
				case 2: return 9; break;	
			}  
}

int Cari_Dist(Data2 Distributor[]){
	int pilih;
	string cari;
	system("cls");
	cout<<"================================ \n";
	cout<<"|     [ CARI DISTRIBUTOR ]     | \n";
	cout<<"================================ \n";
	cout<<"ID Distributor Yg Ingin Dicari:";
	cin>>cari;
	bool tes=false;
	for(int i=0; i<5; i++){
		if(cari==Distributor[i].id){
			cout<<"\nNama		:"<<Distributor[i].nama;
			cout<<"\nCP		:"<<Distributor[i].cp;
			cout<<"\n--------------------------------- \n";
			tes=true;
		}
		}	
		
		if(!tes){
			cout<<"\nData Tidak Ditemukan !!!";
			cout<<"\n--------------------------------- \n";
		}
			
			cout<<"================================== \n";
			cout<<" 1. Kembali \n";
			cout<<" 2. Keluar \n";
			cout<<"================================== \n";
			cout<<"Masukan P0ilihan [1-2] : ";
			cin>>pilih;
			switch(pilih){
				case 1: return 1; break;
				case 2: return 9; break;	
			}  
}

int Tampil_Brg(List L){
	system("cls");
	int pilih;
	cout<<"================================ \n";
	cout<<"|       [ TAMPIL DATA ]        | \n";
	cout<<"================================ \n";
	cout<<" 1. Tampilkan Dari Depan \n";
	cout<<" 2. Tampilkan Dari Belakang \n";
	cout<<"================================ \n";
		inputUlang1:
		cout<<"Masukan Pilihan [1-2] : ";
		cin>>pilih;
	system("cls");
	switch(pilih){
		case 1:
			PrintForward (L);
			
			cout<<"================================ \n";
			cout<<" 1. Kembali \n";
			cout<<" 2. Keluar \n";
			cout<<"================================ \n";
			cout<<"Masukan Pilihan [1-2] : ";
			cin>>pilih;
			switch(pilih){
				case 1: return 1; break;
				case 2: return 9; break;	
			}  
		break;
			
		case 2:
			PrintBackward (L);
			
			cout<<"================================ \n";
			cout<<" 1. Kembali \n";
			cout<<" 2. Keluar \n";
			cout<<"================================ \n";
			cout<<"Masukan Pilihan [1-2] : ";
			cin>>pilih;
			switch(pilih){
				case 1: return 1; break;
				case 2: return 9; break;	
			}  
		break;
		
		default:
			cout<<"\nInputan Anda Tidak Sesuai !\n";
			cout<<"================================ \n";
			goto inputUlang1;
		break; 
	}
}

void Tambah(List *L){
	infotype x;
	system("cls");
	cout<<"================================ \n";
	cout<<"|       [ TAMBAH DATA ]        |\n";
	cout<<"================================ \n";
	cout<<"Kode Sepatu   :";
	cin>>x.kode_brg;
	cout<<"Merk          :";
	cin>>x.merk;
	cout<<"Warna         :";
	cin>>x.warna;
	cout<<"Harga         :";
	cin>>x.harga;
	cout<<"Diskon        :";
	cin>>x.diskon;
	cout<<"Keterangan    :";
	cin>>x.keterangan;
	cout<<"Id_Distributor   :";
	cin>>x.id_distributor;
	
	if(IsEmpty(*L)){
		InsertFirst(L,x);
	}else{
		address tmp=L->first;
		address pred=NULL;
		address NewElmt = Allocation(x);
		while(tmp != NULL && tmp->info.kode_brg < x.kode_brg){
			pred=tmp;
			tmp=tmp->next;
		}
		if(pred==NULL){
			InsertFirst(L,x);
		}else{
			InsertAfter(L, NewElmt, pred);
		}
	}
	system("cls");
	cout<<"====================================== \n";
	cout<<"|  [Data Berhasil DiTambahkan !!! ]  |\n";
	cout<<"====================================== \n";
	system("pause");
}

void Update(List L){ 
infotype x;
address p=NULL;
system("cls");
	cout<<"================================== \n";
	cout<<"         [ UPDATE DATA ]         |\n";
	cout<<"================================== \n";
	cout<<"Kode Sepatu Yg ingin diubah : ";
	cin>>x.kode_brg;
p=L.first;
p=Search(L,x);
if(p==NULL){
	system("cls");
	cout<<"================================== \n";
	cout<<"   Data Tidak Ditemukan \n";
	cout<<"================================== \n";
	system("pause");
}else{
	cout<<"================================== \n";
	cout<<"Merk          :";
	cin>>x.merk;
	cout<<"Warna         :";
	cin>>x.warna;
	cout<<"Harga         :";
	cin>>x.harga;
	cout<<"Diskon        :";
	cin>>x.diskon;
	cout<<"Keterangan    :";
	cin>>x.keterangan;	
	cout<<"Id_Distributor   :";
	cin>>x.id_distributor;
	Info(p)=x;
	
	system("cls");
	cout<<"================================== \n";
	cout<<"  Data Berhasil DiUpdate !!!\n";
	cout<<"================================== \n";
	system("pause");
}
}

int Hapus(List L,BinTree *T,int *i){
infotype x;
infotype3 y;
system("cls");
cout<<"================================ \n";
cout<<"|          JUAL BARANG         | \n";
cout<<"================================ \n";
cout<<"ID Data sepatu Yg ingin dijual :";
cin>>x.kode_brg;
cout<<"Tanggal penjualan              :";
cin>>y.tanggal;
address p=Search(L , x);
if(p==NULL){
	system("cls");
	cout<<"================================ \n";
	cout<<" Barang Tidak Ditemukan !!!\n";
	cout<<"================================ \n";
system("pause");
}else{
y.harga=p->info.harga /100 * (100 -p->info.diskon);
y.kode_barang=p->info.kode_brg;
y.no_penjualan=*i;
*i++;
//y.tanggal=system("settimenow");
Tree(T,y);
DelP (&L, x);

system("cls");
	cout<<"================================ \n";
	cout<<" Barang Berhasil Terjual !!!\n";
	cout<<"================================ \n";
system("pause");
}
}

int Cari(List L){
	infotype x;
	int pilih;
	system("cls");
	cout<<"===================================== \n";
	cout<<"|        [ CARI DATA SEPATU ]       | \n";
	cout<<"===================================== \n";
	inputUlang2:
	cout<<"ID Data Sepatu Yg ingin diCari :";
 	cin>>x.kode_brg;
 	address p=NULL;
	 	p= Search (L, x);
	
	if(p==NULL) cout<<"\nData Tidak Ditemukan";
 	else {
 			cout<<"Kode_Sepatu    :"<<p->info.kode_brg;
			cout<<"\nMerk         :"<<p->info.merk;
			cout<<"\nWarna        :"<<p->info.warna;
			cout<<"\nHarga        :"<<p->info.harga;
	 } 
	 		cout<<"\n================================ \n";
			cout<<" 1. Kembali \n";
			cout<<" 2. Keluar \n";
			cout<<"================================== \n";
			cout<<"Masukan Pilihan [1-2] : ";
			cin>>pilih;
			switch(pilih){
				case 1: return 1; break;
				case 2: return 9; break;	
			} 
	 
	 }
	 	

int Riwayat_Pnj(BinTree T){
	system("cls");
			cout<<"========================================\n";
			cout<<"|       [ Riwayat Penjualan ]          |\n";
			cout<<"======================================== \n";
	InOrder(T);
	int pilih;
			cout<<"\n====================================== \n";
			cout<<" 1. Kembali \n";
			cout<<" 2. Keluar \n";
			cout<<"====================================== \n";
			cout<<"Masukan Pilihan [1-2] : ";
			cin>>pilih;
			switch(pilih){
				case 1: return 1; break;
				case 2: return 9; break;	
			}  
}

Keluar(){
	system("cls");
			cout<<"================================ \n";
			cout<<"=      Trimakasih :)         ==\n";
			cout<<"================================ \n";
}

int main(){
	List L;  
 	createList(&L);
 	infotype data_awal[5]; //array of struct data awal barang berjumlah 5
 	Data2 Distributor[5]; //array of struct untuk data distributor
 	 BinTree T; //deklarasi Tree
    T = NULL;   //alone
	int pilih,no=1;
	
 	data_awal[0]={001,"A02","Nike","Putih","Promo sampai akhir tahun",750000,10};
 	data_awal[1]={002,"A05","Adidas","Merah","Promo Sampai 5 Desember",600000,15};
 	data_awal[2]={003,"A01","Diadora","Abu-Abu","Promo berlaku 3 hari",500000,10};
 	data_awal[3]={004,"A04","Nike","Pink","Promo Untuk 5 pembeli pertama",470000,25};
 	data_awal[4]={005,"A03","Vans","Hitam","Promo_Terbatas",350000,10};
 	
 	for(int i=0; i<5; i++){
 		InsertLast(&L,data_awal[i]);
	 }
 	
 	Distributor[0]={"D01","Deo","0857886750017"};
 	Distributor[1]={"D02","Yanto","082171213453"};
 	Distributor[2]={"D03","Agus","089909878677"};
 	Distributor[3]={"D04","Yoga","080878786565"};
 	Distributor[4]={"d05","yahya","081234567890"};
 
 
	
    
	while(pilih!=9){
	system("cls");
	cout<<"==================================== \n";
	cout<<"|      [ PENJUALAN SEPATU ]        |\n";
	cout<<"==================================== \n";
	cout<<"| [1]> Tampilkan Daftar Sepatu     |\n";
	cout<<"| [2]> Tambah Barang               |\n";
	cout<<"| [3]> Update Data Sepatu          |\n";
	cout<<"| [4]> Cari Data Sepatu            |\n";
	cout<<"| [5]> Jual Barang                 |\n";
	cout<<"| [6]> Tampilkan Distributor       |\n";
	cout<<"| [7]> Cari Distributor            |\n";
	cout<<"| [8]> Riwayat Penjualan           |\n";
	cout<<"| [9]> Keluar                      |\n";
	inputUlang0:
	cout<<"+----------------------------------+ \n";
	cout<<"Masukan Pilihan [1-9] : ";
	cin>>pilih;
	switch(pilih){
		case 1: pilih=Tampil_Brg(L); 		 break;
		case 2: Tambah(&L);		 		   	 break;  
		case 3: Update(L);					 break;
		case 4: pilih=Cari(L); 				 break;	
		case 5: Hapus(L,&T,&no);		 		 break;
		case 6: pilih=Tampil_Dist(Distributor);break;
		case 7: pilih=Cari_Dist(Distributor);  break;
		case 8: pilih=Riwayat_Pnj(T);	 	   break;
		case 9: 		 	 	               break;
		default:
			cout<<"================================ \n";
			cout<<"Inputan Anda Tidak Sesuai !\n";
			goto inputUlang0 ;
		break;
	}
	}
		Keluar();
		system("pause")	;
}
 
 
