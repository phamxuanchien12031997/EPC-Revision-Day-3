// Viết chương trình C nhập n giá trị nguyên. Hãy thực hiện các chức năng sau:
// Tìm max.
// Tìm min.
// Tính trung bình cộng.
// Đếm và liệt kê các số nguyên tố trong mảng
// Sắp xếp theo thứ tự tăng dần.
// Thêm phần tử giá trị V tại vị trí k.
// Xóa phần tử tại vị trí k.
#include <stdio.h>
#include <math.h>

void inputArr(int arr[], int *n)
{
    printf("Nhap so phan tu n: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void outputArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int searchMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int searchMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

float tinhTBC(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

int laNguyenTo(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void lietKeNguyenTo(int arr[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (laNguyenTo(arr[i]))
        {
            printf("%d ", arr[i]);
            dem++;
        }
    if (dem == 0)
        printf("Khong co so nguyen to nao!");
    printf("\n");
}

void sapXepTangDan(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
}

void themPhanTu(int arr[], int *n, int k, int v)
{
    if (k < 0 || k > *n)
    {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *n; i > k; i--)
        arr[i] = arr[i - 1];
    arr[k] = v;
    (*n)++;
}

void xoaPhanTu(int arr[], int *n, int k)
{
    if (k < 0 || k >= *n)
    {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = k; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}
int main()
{
    int arr[100];
    int n;

    inputArr(arr, &n);
    printf("\nMang vua nhap: ");
    outputArr(arr, n);

    printf("\nGia tri lon nhat: %d", searchMax(arr, n));
    printf("\nGia tri nho nhat: %d", searchMin(arr, n));
    printf("\nTrung binh cong: %.2f", tinhTBC(arr, n));

    printf("\nCac so nguyen to trong mang: ");
    lietKeNguyenTo(arr, n);

    sapXepTangDan(arr, n);
    printf("\nMang sau khi sap xep tang dan: ");
    xuatMang(arr, n);

    int k, v;
    printf("\n\nNhap vi tri can them (0-%d): ", n);
    scanf("%d", &k);
    printf("Nhap gia tri can them: ");
    scanf("%d", &v);
    themPhanTu(arr, &n, k, v);
    printf("Mang sau khi them: ");
    xuatMang(arr, n);

    printf("\n\nNhap vi tri can xoa (0-%d): ", n - 1);
    scanf("%d", &k);
    xoaPhanTu(arr, &n, k);
    printf("Mang sau khi xoa: ");
    xuatMang(arr, n);

    return 0;
}