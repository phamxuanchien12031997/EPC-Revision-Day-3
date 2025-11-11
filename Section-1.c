#include <stdio.h>
// Viết chương trình nhập vào một giá trị và lưu vào biến a, dùng con trỏ p để trỏ tới biến a này.
// Hãy in ra giá trị của p, giá trị tại địa chỉ p trỏ tới, giá trị của a, địa chỉ của a.
// Có nhận xét gì giữa giá trị của p và địa chỉ của a?
// Nếu a thay đổi thì giá trị tại địa chỉ p trỏ tới có thay đổi?
// Thay đổi giá trị của a bằng biến con trỏ p.
// Viết hàm tăng giá trị của biến a lên 10 đơn vị.
// Viết hàm hoán đổi giá trị của 2 biến a và b sử dụng con trỏ.

void up10(int *x)
{
    *x += 10;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b;
    int *p;

    printf("Nhap gia tri a: ");
    scanf("%d", &a);

    p = &a;

    printf("\n--- Thong tin ---\n");
    printf("Gia tri cua p (dia chi ma p tro toi): %p\n", p);
    printf("Gia tri tai dia chi p tro toi (*p): %d\n", *p);
    printf("Gia tri cua a: %d\n", a);
    printf("Dia chi cua a (&a): %p\n", &a);

    printf("\n=> Nhan xet: Gia tri cua p = dia chi cua a (&a)\n");

    a = 50;
    printf("\nSau khi thay doi a = 50:\n");
    printf("Gia tri tai dia chi p tro toi (*p): %d\n", *p);
    printf("=> *p thay doi theo vi a va *p cung tro cung 1 dia chi.\n");

    *p = 100;
    printf("\nSau khi thay doi *p = 100:\n");
    printf("Gia tri cua a: %d\n", a);

    up10(&a);
    printf("\nSau khi tang 10 don vi: a = %d\n", a);

    printf("\nNhap them gia tri b: ");
    scanf("%d", &b);
    printf("Truoc khi hoan doi: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("Sau khi hoan doi: a = %d, b = %d\n", a, b);

    return 0;
}
