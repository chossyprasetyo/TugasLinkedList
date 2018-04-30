#include <iostream>
using namespace std;

class TNode{
	
  public:
    
	int data;
    TNode *next;
};

TNode *up;
TNode *down;
TNode *del;

void init()
{
    up=NULL;
    down = NULL;
}

int isEmpty ()
{
	if (down==NULL){
	return true;
	}
	else{
	return false;
	}
}

void tambahDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        up=baru;
        down=baru;
        up->next=up;
        down->next=down;
    }
    else
    {
    	
        baru->next=up;
        up=baru;
        down->next=up;
    
	}
}

void tambahBelakang(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        up= baru;
        down = baru;
        up->next =up;
        down->next= down;
    }
    else
    {
        down->next = baru;
        down = baru;
        down->next =up;
    }
}

void cetak(){
    
        TNode *bantu;
        bantu =up;
    if (isEmpty() == 0){
		
        do{
            cout<<bantu->data<<"---->";
            bantu=bantu->next;
        }while (bantu!=down->next);
    } else {
        cout<<"List Kosong";
    }
}



void hapusDepan(){
	TNode *hapus;
	if (isEmpty()==0){
		int x;
		hapus =up;
		x =up->data;
		if(up!=down){
			hapus=up;
			up=up->next;
			down->next=up;
			delete hapus;
		}else{
			up=NULL;
			down=NULL;
		}
		cout<<"Hilang --> "<<x<<endl;
	} else cout<<"Kosong\n";
}


