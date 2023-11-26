#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// cau truc nhan vien 
struct NhanVien{
	char hoten[100];
	char maso[30];
	int luong;
	struct NhanVien* next;	
};


// ham lua chon
void Menu()
{
	printf("\nVui long chon chuc nang :\n");
	printf("1. Them nhan vien moi. \n");
	printf("2. Xoa nhan vien. \n");
	printf("3. Tim kiem nhan vien. \n");
	printf("4. Quit !!! . \n");
}

// cac ham chuc nang
void themnhanvien(struct NhanVien** head)
{
    struct NhanVien* newNhanVien = (struct NhanVien*)malloc(sizeof(struct NhanVien)); // cap phat bo nho dong

    printf("Nhap ho ten: ");
    fflush(stdin);  // Clear input buffer before reading
    fgets(newNhanVien->hoten, sizeof(newNhanVien->hoten), stdin);
    // Remove newline character from fgets result
    newNhanVien->hoten[strcspn(newNhanVien->hoten, "\n")] = '\0';

    printf("Nhap ma so nhan vien: ");
    scanf("%s", newNhanVien->maso);

    printf("Nhap luong hang thang: ");
    scanf("%d", &(newNhanVien->luong));

    newNhanVien->next = *head;
    *head = newNhanVien;

    printf("Da them nhan vien moi.\n");

}
void xoanhanvien(struct NhanVien** head, char *key)
{
	struct NhanVien* cur = *head;
	struct NhanVien* rev = NULL;
	while(cur != NULL)
	{
		if(strcmp(cur->maso, key) == 0 || strcmp(cur->hoten, key) == 0)
		{
			if(rev == NULL)
			{
				*head = cur->next;
			}
			else
			{
				rev->next = cur->next;
			}
			
			free(cur);
			printf("Da xoa nhan vien.\n");
			return;
		}
		
		rev = cur;
		cur = cur->next;
		
	}
	
	printf("Khong tim thay nhan vien co ma so hoac ten la %s.\n", key);
}



void timkiem(struct NhanVien* head, char* key)
{
	struct NhanVien* cur = head;
	int found = 0;
	
	while(cur != NULL)
	{
		if (strcmp(cur->maso, key) == 0 || strcmp(cur->hoten, key) == 0) {
            printf("Thong tin nhan vien:\n");
            printf("Ho ten: %s\n", cur->hoten);
            printf("Ma so nhan vien: %s\n", cur->maso);
            printf("Luong hang thang: %d\n", cur->luong);
            found = 1;
            break;
        }

        cur = cur->next;
	}
	
	if (!found) {
        printf("Khong tim thay nhan vien co ma so hoac ten la %s.\n", key);
    }
	
}
int main()
{
	struct NhanVien* danhsach = NULL;
	char select;
	char out = 0;
	char key[30];
	while(1)
	{
		Menu();
		printf("Nhap lua chon : \n");
		scanf(" %c", &select);
		fflush(stdin);
		switch(select)
		{
			case '1': 
			{
				themnhanvien(&danhsach); 
				fflush(stdin);
				break;
			}
			case '2':
			{
				printf("Nhap ma so hoac ten can xoa \n");
				//scanf("%s", key);
				fgets(key, sizeof(key), stdin);
				key[strcspn(key, "\n")] = '\0';
				xoanhanvien(&danhsach, key); 
				fflush(stdin);
				break;
			}
			case '3':
			{
				printf("Nhap ma so hoac ten nhan vien can tim kiem: ");
                fgets(key, sizeof(key), stdin);
				key[strcspn(key, "\n")] = '\0';
				timkiem(danhsach, key); 
				fflush(stdin);
				break;
			}
			case '4':
			{
				out = 1; 
				break;
			}
			default :
				printf("Lua chon khong hop le \n");
		}
		
		if(out == 1 && select == '4') break;
	}


	return 0;
}


