#include <stdio.h>
#include <string.h>

struct NhanVien {
    char hoTen[50];
    int maSo;
    float luong;
};

struct DanhSachNhanVien {
    struct NhanVien nhanVien[1000];
    int soLuong;
};

int main() {
    struct DanhSachNhanVien dsNhanVien;
    dsNhanVien.soLuong = 0;

    int luachon;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Them nhan vien moi\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Tim kiem nhan vien\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%c", &luachon);
        fflush(stdin);

        switch (luachon) {
            case '1': {
                struct NhanVien nv;
                printf("Nhap ho ten: ");
                fflush(stdin);
                fgets(nv.hoTen, sizeof(nv.hoTen), stdin);
				fflush(stdin);
                printf("Nhap ma so nhan vien: ");
                scanf("%d", &nv.maSo);
				fflush(stdin);
				printf("Nhap luong nhan vien: ");
				scanf("%f",&nv.luong );
				fflush(stdin);
				dsNhanVien.nhanVien [dsNhanVien.soLuong ]=nv;
				dsNhanVien.soLuong ++;
				break;
                }   

            case '2': {
       			char hoten[50];
				int ma,x;
                printf("Nhap 1 de xoa theo ten \n");
				printf("Nhap 2 de xoa theo ma  \n");
				scanf("%d",&x);
				fflush(stdin);
				if(x==1){
					printf("Nhap ho ten nhan vien can xoa: ");
					fgets(hoten, sizeof(hoten), stdin);
	                fflush(stdin);
				}
				if(x==2){
					printf("Nhap ma nhan vien can xoa: ");
					scanf("%d",&ma);
	                fflush(stdin);
				}
                for (int i = 0; i < dsNhanVien.soLuong; i++) {
					if(dsNhanVien.nhanVien[i].maSo == ma||strcmp(dsNhanVien.nhanVien[i].hoTen ,hoten) == 0){
						for(int j=i;j<dsNhanVien.soLuong ; j++){
							dsNhanVien.nhanVien[j]=dsNhanVien.nhanVien[j+1];
						}
					printf("Da xoa nhan vien");
					dsNhanVien.soLuong --;
					}
                }
                break;
            }
            case '3': {
       			char hoten[50];
				int ma,x;
                printf("Nhap 1 de tim theo ten \n");
				printf("Nhap 2 de tim theo ma  \n");
				scanf("%d",&x);
				fflush(stdin);
				if(x==1){
					printf("Nhap ho ten nhan vien can tim: ");
					fgets(hoten, sizeof(hoten), stdin);
	                fflush(stdin);
				}
				if(x==2){
					printf("Nhap ma nhan vien can tim: ");
					scanf("%d",&ma);
	                fflush(stdin);
				}
                for (int i = 0; i < dsNhanVien.soLuong; i++) {
					if(dsNhanVien.nhanVien[i].maSo == ma||strstr(dsNhanVien.nhanVien[i].hoTen ,hoten) != NULL ){
						printf("Nhan vien ban can tim la:\n");
						printf("Ho ten: %s\n",dsNhanVien.nhanVien[i].hoTen);
						printf("Ma so: %d\n",dsNhanVien.nhanVien[i].maSo);
						printf("Luong: %f\n",dsNhanVien.nhanVien[i].luong);
						printf("------------\n");
					}
                }
                break;
            }
            
            default:
            	printf("\n Tim kiem khong hop le. Vui long nhap lai !");
				
       }
   }

    return 0;
}
