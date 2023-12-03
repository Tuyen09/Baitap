#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nhanvien{
	char name[500];
	int id;
	float mon;
};
struct NV{
	Nhanvien s;
	NV* next;
};

typedef struct NV* nv;

// cap phat dong du lieu
nv makeNode(){
	Nhanvien s;
	printf("Nhap thong tin nhan vien: \n");
	printf("Nhap ID: ");
	scanf("%d", &s.id);
	printf("Nhap ten: ");
	fflush(stdin);
	fgets(s.name, sizeof(s.name), stdin);
	printf("Nhap luong : ");
	scanf("%f", &s.mon);
	
	nv tmp = new NV();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}

// Kiem tra rong
bool empty(nv a){
	return a == NULL;
}

int Size(nv a){
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi tiep theo cho node hien tai
		// cho node hien tai nhay sang node tiep theo
	}
	return cnt;
}

// them mot phan tu vao dau danh sach lien ket
void insertFirst(nv &a){
	nv tmp = makeNode();
	if(a == NULL){
		a= tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}

// them mot phan tu vao cuoi danh sach
void insertLast(nv &a){
	nv tmp = makeNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		nv p = a;
		while( p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}

// them mot phan tu vao giua
void insertMid(nv &a, int pos){
	int n = Size(a);
	if(pos <= 0 || pos > pos + 1){
		printf("Vi tri chen khog hop le. \n");
	}
	if(pos == 1)
	{
		insertFirst(a); return;
	}
	else if(pos = n + 1)
	{
		insertLast(a); return;
	}
	nv p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	
	nv tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}

// xoa phan tu o dau
void delFirst(nv &a){
	if(a == NULL ) return;
	a = a->next;
}

// xoa phan tu o cuoi
void delLast(nv &a){
	if(a == NULL ) return;
	nv fir = NULL, las = a;
	while(las->next != NULL){
		fir = las;
		las = las->next;
	}
	if(fir == NULL){
		a = NULL;
	}
	else{
		fir->next = NULL;
	}
}

// xoa o giua
void delmid(nv &a, int pos){
	if(pos <= 0 || pos > Size(a)) return;
	nv fir = NULL, las = a;
	for( int i = 0; i < pos - 1; i++){
		fir = las;
		las = las->next;
	}
	if(fir == NULL){
		a = a->next;
	}
	else{
		fir->next = las->next;
	}
}
// in thong tin
void in(Nhanvien s){
	printf("-----------------------------\n");
	printf("ID: %d \n", s.id);
	printf("Ho ten : %s\n", s.name);
	printf("Luong: %.2f\n", s.mon);
	printf("-----------------------------\n");
}
// in danh sach
void inds(nv a){
	printf("------------------------------\n");
	printf("Danh sach nhan vien : \n");
	while(a != NULL){
		in(a->s);
		a = a->next;
	}
	printf("\n------------------------------\n");
}
// Tim kiem nhan vien theo ten
nv searchByName(nv a, const char* ten) {
    while (a != NULL) {
        if (strstr(a->s.name, ten) != NULL) {
            return a;
        }
        a = a->next;
    }
    return NULL; 
}
// Tim kiem nhan vien theo id
nv searchById(nv a, int id) {
    while (a != NULL) {
        if (a->s.id == id) {
            return a;
        }
        a = a->next;
    }
    return NULL;
}

// xoa nhan vien theo ten hoac id
void deleteByCriteria(nv &a, const char* criteria) {
    if (a == NULL) return;

    nv fir = NULL, las = a;

    while (las != NULL) {
        if (strstr(las->s.name, criteria) != NULL ||
            las->s.id == atoi(criteria)) {
            break;
        }
        fir = las;
        las = las->next;
    }

    if (las == NULL) {
        printf("Khong tim thay nhan vien co ten hoac ID: %s\n", criteria);
        return;
    }

    if (fir == NULL) {
        // xoa phan tu o dau danh sach
        a = a->next;
    } else {
        fir->next = las->next;
    }

    delete las;
    printf("Xoa thanh cong nhan vien co ten hoac ID: %s\n", criteria);
}

int main()
{
	nv head = NULL;
	int quit = 0;
	
	while(1){
		printf("\n------------MENU-------------\n");
		printf("1. Them nhan vien \n");
		printf("2. Xoa nhan vien  \n");
		printf("3. Tim kiem nhan vien \n");
		printf("4. Danh sach tat ca nhan vien \n");
		printf("5. Thoat chuong trinh. \n");
		printf("\n------------------------------\n");
		printf("Nhap lua chon : ");
		int sel; 
		scanf("%d", &sel);
			
		switch(sel){
			case 1:{
				int x, pos;
				printf("Nhap vi tri  : ");
				scanf("%d", &pos);
				insertMid(head, pos);
				break;	
			}
			case 2:{
				char criteria[500];
   				printf("Nhap thong tin can xoa: ");
   				fflush(stdin);
   				fgets(criteria, sizeof(criteria), stdin);
   				deleteByCriteria(head, criteria);
   				break;
			}
			case 3:{
				printf("Nhap 1 de tim theo ten.\n");
				printf("Nhap 2 de tim theo ma. \n");
				int _sel;
				scanf("%d", &_sel);
				switch(_sel){
					case 1:{
						char ten[500];
    					printf("Nhap ten can tim: ");
    					fflush(stdin);
   						fgets(ten, sizeof(ten), stdin);
   						nv result = searchByName(head, ten);
   						if (result != NULL) {
   						    in(result->s);
   						} else {
   						    printf("Khong tim thay nhan vien co ten: %s\n", ten);
   						}
						break;
					}
					case 2:{
						int id;
   						printf("Nhap ID can tim: ");
   						scanf("%d", &id);
   						nv result = searchById(head, id);
   						if (result != NULL) {
   						    in(result->s);
   						} else {
   						    printf("Khong tim thay nhan vien co ID: %d\n", id);
   						}
						break;
					}
					default:
						printf("Lua chon khong hop le. Vui long nhap lai.");
				}
				
   				break;
			}
			case 4:{
				inds(head);
				printf("\n");
				break;
			}
			case 5:{
				printf("--------------- Tam biet -------------  \n");
				quit = 1;
				break;
			}
			
			default:
				printf("Vui long nhap lai !!! \n");
		}
		if(quit == 1)
		{
			break;
		}
		
	}
	return 0;
}


