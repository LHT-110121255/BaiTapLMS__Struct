#include <stdio.h>
#include <windows.h>
#include <math.h>

typedef struct phan_so
{
    int tu;
    int mau;
}phan_so;

void Nhap(phan_so &p);
void Xuat(phan_so p);
int UCLN(int a, int b);
phan_so RutGon(phan_so p);
phan_so CongPS(phan_so p1, phan_so p2);
phan_so TruPS(phan_so p1, phan_so p2);
phan_so NhanPS(phan_so p1, phan_so p2);
phan_so ChiaPS(phan_so p1, phan_so p2);

int main()
{
    system("cls");
    phan_so p, p1, p2;
    printf("Nhap phan so thu nhat: \n");
    Nhap(p1);
    printf("Nhap phan so thu nhat: \n");
    Nhap(p2);
    printf("\nNhap e de thoat");
    int KT = true;
    while (KT)
    {
    	printf("\n phep tinh cong: +");
    	printf("\n phep tinh tru: -");
    	printf("\n phep tinh nhan: *");
    	printf("\n phep tinh chia: /");
        printf("\nChon phep tinh 2 phan so: ");
        fflush(stdin);
        char lc; scanf("%c", &lc);
        switch (lc)
        {
        case '+':
            p = CongPS(p1, p2);
            Xuat(p);
            break;
        case '-':
            p = TruPS(p1, p2);
            Xuat(p);
            break;
        case '*':
            p = NhanPS(p1, p2);
            Xuat(p);
            break;
        case '/':
            p = ChiaPS(p1, p2);
            Xuat(p);
            break;
        case 'e':
            KT = false;
            break;
        default:
            printf("Nhap sai !!!!");
            break;
        }
    }
}

void Nhap(phan_so &p)
{
    printf("Nhap tu: "); scanf("%d", &p.tu);
    printf("Nhap mau: "); scanf("%d", &p.mau);
}
void Xuat(phan_so p)
{
    printf("\n%d/%d", p.tu, p.mau);
}
int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while( a* b != 0)
    {
        (a > b) ? (a%= b) : (b %= a);
    }
    return a + b;
}
phan_so RutGon(phan_so p)
{
    phan_so c;
    c.tu = p.tu / UCLN(p.tu, p.mau);
    c.mau = p.mau / UCLN(p.tu, p.mau);
    return c;
}

phan_so CongPS(phan_so p1, phan_so p2)
{
    phan_so p;
    if(p1.mau == p2.mau)
    {
        p.tu = p1.tu + p2.tu;
        p.mau = p1.mau;
    } else
    {
        p.tu = p1.tu*p2.mau + p2.tu*p1.mau;
        p.mau = p1.mau * p2.mau;
    }
    if(p.mau < 0)
    {
        p.tu = p.tu*(-1);
        p.mau = abs(p.mau);
    }
    return RutGon(p);
}
phan_so TruPS(phan_so p1, phan_so p2)
{
    phan_so p;
    if(p1.mau == p2.mau)
    {
        p.tu = p1.tu - p2.tu;
        p.mau = p1.mau;
    } else
    {
        p.tu = p1.tu*p2.mau - p2.tu*p1.mau;
        p.mau = p1.mau * p2.mau;
    }
    if(p.mau < 0)
    {
        p.tu = p.tu*(-1);
        p.mau = abs(p.mau);
    }
    return RutGon(p);
}
phan_so NhanPS(phan_so p1, phan_so p2)
{
    phan_so p;
    p.tu = p1.tu*p2.tu;
    p.mau = p1.mau*p2.mau;
    if(p.mau < 0)
    {
        p.tu = p.tu*(-1);
        p.mau = abs(p.mau);
    }
    return RutGon(p);
}
phan_so ChiaPS(phan_so p1, phan_so p2)
{
    phan_so p;
    p.tu = p1.tu * p2.mau;
    p.mau = p1.mau * p2.tu;
    if(p.mau < 0)
    {
        p.tu = p.tu*(-1);
        p.mau = abs(p.mau);
    }
    return RutGon(p);
}
