#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct HocSinh
{
	char ma_so_hoc_sinh[11];
	char ho_ten[51];
	float toan;
	float li;
	float hoa;
	float DIEM_TB;
}HocSinh;

void Nhap_1_HS(HocSinh &hs);
void Xuat_1_HS(HocSinh hs);
void Nhap_Xuat_n_HS(HocSinh *hs, int n);
float AVD(HocSinh &hs);
void Xuat_n_HS(HocSinh *hs, int n);
void SX_theo_Toan(HocSinh *hs, int n);
void SX_theo_DTB(HocSinh *hs, int n);
void DTB_MAX(HocSinh *hs, int n);
void Toan_MAX(HocSinh *hs, int n);

int main()
{
	int key = true;
	
	printf("\n---------------CHUONG TRINH HOC SINH LMS CUA LHT-------------------\n");
	while(key)
	{
		printf("\n1. Nhap/Xuat mot hoc sinh");
		printf("\n2. Nhap/Xuat n hoc sinh");
		printf("\n3. Tinh diem trung binh 1 hoc sinh");
		printf("\n4. Sap xep hoc sinh tang dan theo diem toan");
		printf("\n5. Sap xep hoc sinh tang dan theo diem trung binh");
		printf("\n6. tim diem trung binh lon nhat trong danh sach hoc sinh");
		printf("\n7. tim hoc sinh co diem toan lon nhat");
		printf("\n8. LAM SACH MAN HINH CONSLE");
		printf("\n0. THOAT");
		printf("\nNhap lua chon: "); int lc; 
		scanf("%d", &lc);
		int n;
		switch(lc)
		{
			case 0:
				key = false;
				break;
			case 1: 
				HocSinh hs;
				Nhap_1_HS(hs);
				printf("\nDANH SACH HOC SINH VUA NHAP\n");
				Xuat_1_HS(hs);
				break;
			case 2:
				printf("\nNhap so hoc sinh muon nhap: ");
				scanf("%d", &n);
				HocSinh arr_hs[100];
				Nhap_Xuat_n_HS(arr_hs, n);
				break;
			case 3:
				int m;
				printf("\nNhap thu tu hoc sinh ma ban muon tinh diem trung binh = ");
				fflush(stdin);
				scanf("%d", &m);
				Xuat_1_HS(arr_hs[m]);
				printf("\nDiem trung binh = %.2f", AVD(arr_hs[m]));
				break;
			case 4:
				SX_theo_Toan(arr_hs, n);
				break;
			case 5:
				SX_theo_DTB(arr_hs, n);
				break;
			case 6:
				DTB_MAX(arr_hs, n);
				break;
			case 7:
				Toan_MAX(arr_hs, n);
				break;
			case 8:
				system("cls");
			default:
				printf("\nKhong co chuc nang nay !!! Moi nhap lai !!!");
		}
	}
}

void Nhap_1_HS(HocSinh &hs)
{
	fflush(stdin);
	printf("\nNhap MSSHS = ");
	gets(hs.ma_so_hoc_sinh);
	fflush(stdin);
	printf("\nNhap ho & ten = ");
	gets(hs.ho_ten);
	fflush(stdin);
	printf("\nNhap diem toan = ");
	scanf("%f", &hs.toan);
	fflush(stdin);
	printf("\nNhap diem Ly = ");
	scanf("%f", &hs.li);
	fflush(stdin);
	printf("\nNhap diem Hoa = ");
	scanf("%f", &hs.hoa);
}

void Xuat_1_HS(HocSinh hs)
{
	printf("\n\t-----------------Thong tin hoc sinh---------------------------\n");
	printf("\t");
	puts(hs.ma_so_hoc_sinh);
	printf("\t");
	puts(hs.ho_ten);
	printf("\tDiem Toan = %.2f\tDiem Ly = %.2f\tDiem Hoa = %.2f", hs.toan, hs.li, hs.hoa);
	printf("\n");
}

void Nhap_Xuat_n_HS(HocSinh *hs, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("\nNhap hoc sinh thu %d: ", i);
		Nhap_1_HS(hs[i]);
	}
}
void Xuat_n_HS(HocSinh *hs, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("\nHoc sinh thu %d: ", i);
		Xuat_1_HS(hs[i]);
	}
}

float AVD(HocSinh &hs)
{
	hs.DIEM_TB = (hs.toan + hs.li + hs.hoa)/3;
	return hs.DIEM_TB;
}

void SX_theo_Toan(HocSinh *hs, int n)
{
	int i; 
	for(i = 1; i < n; i++)
	{
		if(hs[i].toan > hs[i+1].toan)
		{
			HocSinh temp = hs[i];
			hs[i] = hs[i+1];
			hs[i+1] = temp;
		}
	}
	printf("\nDanh sach sau khi sap xep");
	Xuat_n_HS(hs, n);
}

void SX_theo_DTB(HocSinh *hs, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		hs[i].DIEM_TB = (hs[i].toan + hs[i].li + hs[i].hoa)/3;
	}
	for(i = 1; i < n; i++)
	{
		if(hs[i].DIEM_TB > hs[i+1].DIEM_TB)
		{
			HocSinh temp = hs[i];
			hs[i] = hs[i+1];
			hs[i+1] = temp;
		}
	}
	printf("\nDanh sach sau khi sap xep");
	for(i = 1; i <= n; i++)
	{
		printf("\nHoc sinh thu %d: ", i);
		printf("\n\t-----------------Thong tin hoc sinh vua nhap---------------------------\n");
		printf("\t");
		puts(hs[i].ma_so_hoc_sinh);
		printf("\t");
		puts(hs[i].ho_ten);
		printf("\tDiem Toan = %.2f\tDiem Ly = %.2f\tDiem Hoa = %.2f", hs[i].toan, hs[i].li, hs[i].hoa);
		printf("\n\tDiem Trung Binh = %f", hs[i].DIEM_TB);
		printf("\n");
	}
}

void DTB_MAX(HocSinh *hs, int n)
{
	int i, index;
	float max = hs[1].DIEM_TB;
	for(i = 2; i <= n; i++)
	{
		if(max < hs[i].DIEM_TB)
			max = hs[i].DIEM_TB;
			index = i;
		
	}
	Xuat_1_HS(hs[index]);
	printf("\nDiem trung binh = %f", hs[index].DIEM_TB);
}

void Toan_MAX(HocSinh *hs, int n)
{
	int i, index;
	float max = hs[1].toan;
	for(i = 2; i <= n; i++)
	{
		if(max < hs[i].toan)
			max = hs[i].toan;
			index = i;
		
	}
	Xuat_1_HS(hs[index]);
}
