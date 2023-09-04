#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
void nhap_random(int* a, int n)  //ham random mang
{
    for (int i = 0; i < n; i++)
    {
        *(a + i) = rand() % 100;  //random voi 100 so dau tien 
    }
}

//ham nhap xuat mang kieu con tro 
void nhap_mang(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]=";
        cin >> a[i];
    }
}
void xuat_mang(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

//ham nhap xuat mang voi n so nguyen 8 5 3 0 7 11 4
void Nhap_Mang(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]=";
        cin >> b[i];
    }
}
void Xuat_Mang(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}

//ham nhap xuat voi n ki tu H K E C L M I B
void nhap_Mang(string d[], int n)  //goi d  la string boi vi ta phai xuat ki tu 
{
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]=";
        cin >> d[i];
    }
}
void xuat_Mang(string d[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
}

int ktnguyento(int n) //ham kiem tra so nguyen to 
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int vi_tri(int b[], int n) //ham tim vi tri SNT lon nhat
{
    int vt, d, i;
    for (i = 0; i < n; i++)
        if (ktnguyento(b[i]) == 1)
        {
            d = i;
            break;
        }
    if (i == n)
    {
        return -1;
    }
    vt = d;
    for (i = vt + 1; i < n; i++)
        if (ktnguyento(b[i]) == 1 && b[i] > b[vt])
            vt = i;
    return vt;
}
void liet_ke_ngto(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ktnguyento(a[i]))
        {
            cout << a[i] << " ";
        }
    }
}
void xuat_thap_phan(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] % 10 << " ";
    }
}
int dem_mot_chu_so(int* a, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % 10 == 2)
        {
            dem++;
            n = n / 10;
        }
    }
    return dem;
}
int dem_hai_chu_so(int* a, int n)
{
    int dem = 0;
    for (int i = 2; i < n; i++)
    {
        dem += dem_mot_chu_so(a, i);
    }
    return dem;
}
void xoa(int* a, int& n, int vtxoa)   //ham xoa 
{
    for (int i = vtxoa; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}
void xoa_so_le(int* a, int& n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            xoa(a, n, i);
            i--;
        }
    }
}

int xoa_max(int* a, int& n)
{
    int max = a[0], vt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            vt = i;
        }
    }
    return vt;
}
int xoa_min(int* a, int n)
{
    int min = a[0], vt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            vt = i;
        }
    }
    return vt;
}
void tim_x(int* a, int n, int x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            dem++;
        }
    }
    cout << "trong a co " << dem << " ptu x ";
}
void them_x_max(int*& a, int& n, int x)
{
    if (n <= 0)
    {
        throw "Mang rong hoac khong hop le.";
    }
    int vi_tri_max = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[vi_tri_max])
        {
            vi_tri_max = i;
        }
    }
    int* b = new int[n + 1];
    for (int i = 0; i <= vi_tri_max; i++)
    {
        b[i] = a[i];
    }
    b[vi_tri_max + 1] = x;
    for (int i = vi_tri_max + 1; i < n; i++)
    {
        b[i + 1] = a[i];
    }
    delete[] a;
    a = b;
    n++;
}
void them_x_min(int*& a, int& n, int x)
{
    if (n <= 0)
    {
        throw "Mang rong hoac khong hop le.";
    }
    int vt_min = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[vt_min])
        {
            vt_min = i;
        }
    }
    int* b = new int[n + 1];
    for (int i = 0; i < vt_min; i++)
    {
        b[i] = a[i];
    }
    b[vt_min] = x;

    for (int i = vt_min; i < n; i++)
    {
        b[i + 1] = a[i];
    }

    delete[] a;
    a = b;
    n++;
}

//ham tinh tien dien 
int tinh_tien(int sodien)
{
    if (sodien >= 401)
    {
        cout << "so tien dien : " << sodien * 2927;
    }
    else if (sodien >= 301)
    {
        cout << "so tien dien : " << sodien * 2834;
    }
    else if (sodien >= 201)
    {
        cout << "so tien dien : " << sodien * 2536;
    }
    else if (sodien >= 101)
    {
        cout << "so tien dien : " << sodien * 2014;
    }
    else if (sodien >= 51)
    {
        cout << "so tien dien : " << sodien * 1734;
    }
    else if (sodien > 0)
    {
        cout << "so tien dien : " << sodien * 1678;
    }
    return 0;
}

//ham sap xep tang giam trong mang bang con tro
void inter_sort_tang(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
void inter_sort_giam(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
                swap(a[i], a[j]);
        }
    }
}
void select_sort_tang(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imax = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[imax] > a[j])
                imax = j;
        }
        swap(a[imax], a[i]);
    }
}
void select_sort_giam(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[imin] < a[j])
                imin = j;
        }
        swap(a[imin], a[i]);
    }
}
void quick_sort_tang(int* a, int left, int right)
{
    if (left >= right)
        return;
    int ileft = left, iright = right, imid = (left + right) / 2;
    int key = a[imid];
    while (ileft <= iright)
    {
        while (a[ileft] < key)
            ileft++;
        while (a[iright] > key)
            iright--;
        if (ileft <= iright)
        {
            swap(a[ileft], a[iright]);
            ileft++;
            iright--;
        }
        quick_sort_tang(a, left, ileft - 1);
        quick_sort_tang(a, ileft, right);
    }
}
int partititon(int* a, int low, int high)
{
    int pivot = a[high], left = low, right = high - 1;
    while (true)
    {
        while (left <= right && a[left] > pivot)
            left++;// Tìm phần tử >= arr[pivot]
        while (right >= left && a[right] < pivot)
            right--; // Tìm phần tử <= arr[pivot]
        if (left >= right) // Đã duyệt xong thì thoát vòng lặp
            break;// Nếu chưa xong, đổi chỗ.
        swap(a[left], a[right]);
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(a[left], a[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}
void quick_sort_giam(int* a, int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
        và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partititon(a, low, high);
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quick_sort_giam(a, low, pi - 1);
        quick_sort_giam(a, pi + 1, high);
    }
}

//ham sap xep mang tang giam trong mang co so nguyen sau 8  5  3  0  7  11  4  
int Linear_Search(int b[], int n, int c)  //int c la X
{
    for (int i = 0; i < n; i++)
    {
        if (b[i] == c)
            return i;
    }
}
void Inter_Sort_Tang(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] > b[j])
                swap(b[i], b[j]);
        }
    }
}
void Inter_Sort_Giam(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] < b[j])
                swap(b[i], b[j]);
        }
    }
}
void Select_Sort_Tang(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imax = i;
        for (int j = i + 1; j < n; j++)
        {
            if (b[imax] > b[j])
            {
                imax = j;
            }
            swap(b[imax], b[i]);
        }
    }
}
void Select_Sort_Giam(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (b[imin] < b[j])
            {
                imin = j;
            }
            swap(b[imin], b[i]);
        }
    }
}
void Quick_Sort_Tang(int b[], int left, int right)
{
    if (left >= right)
        return;
    int ileft = left, iright = right, imid = (left + right) / 2;
    int key = b[imid];
    while (ileft <= iright)
    {
        while (b[ileft] < key)
            ileft++;
        while (b[iright] > key)
            iright--;
        if (ileft <= iright)
        {
            swap(b[ileft], b[iright]);
            ileft++;
            iright--;
        }
        Quick_Sort_Tang(b, left, ileft - 1);
        Quick_Sort_Tang(b, ileft, right);
    }
}
int partition(int b[], int low, int high)
{
    int pivot = b[high], left = low, right = high - 1;
    while (true)
    {
        while (left <= right && b[left] > pivot)
            left++;
        while (right >= left && b[right] < pivot)
            right--;
        if (left >= right)
            break;
        swap(b[left], b[right]);
        left++;
        right--;
    }
    swap(b[left], b[high]);
    return left;
}
void Quick_Sort_Giam(int b[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(b, low, high);
        Quick_Sort_Giam(b, low, pi - 1);
        Quick_Sort_Giam(b, pi + 1, high);
    }
}
int Binary_Search(int b[], int n, int c) //int c duoc thay bang gt cua X 
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (b[mid] == c)
        {
            return mid;
        }
        else if (b[mid] < c)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

//ham sap xep mang tang giam trong mang co ki tu sau H  K  E  C  L  M  I  B
int linear_Serach(string d[], int n, string e) //string e la X
{
    for (int i = 0; i < n; i++)
    {
        if (d[i] == e)
        {
            return i;
        }
    }
}
void inter_Sort_tang(string d[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i] > d[j])
                swap(d[i], d[j]);
        }
    }
}
void inter_Sort_giam(string d[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i] < d[j])
                swap(d[i], d[j]);
        }
    }
}
void select_Sort_tang(string d[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imax = i;
        for (int j = i + 1; j < n; j++)
        {
            if (d[imax] > d[j])
            {
                imax = j;
            }
            swap(d[imax], d[i]);
        }
    }
}
void select_Sort_giam(string d[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (d[imin] < d[j])
            {
                imin = j;
            }
            swap(d[imin], d[i]);
        }
    }
}
void quick_Sort_tang(string d[], int left, int right)
{
    if (left >= right)
        return;
    int ileft = left, iright = right, imid = (left + right) / 2;
    string key = d[imid];
    while (ileft <= iright)
    {
        while (d[ileft] < key)
            ileft++;
        while (d[iright] > key)
            iright--;
        if (ileft <= iright)
        {
            swap(d[ileft], d[iright]);
            ileft++;
            iright;
        }
        quick_Sort_tang(d, left, ileft - 1);
        quick_Sort_tang(d, ileft, right);
    }
}
int partition(string d[], int low, int high)
{
    string pivot = d[high];
    int left = low, right = high - 1;
    while (true)
    {
        while (left <= right && d[left] > pivot)
            left++;
        while (right >= left && d[right] < pivot)
            right--;
        if (left >= right)
            break;
        swap(d[left], d[right]);
        left++;
        right--;
    }
    swap(d[left], d[high]);
    return left;
}
void quick_Sort_giam(string d[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(d, low, high);
        quick_Sort_giam(d, low, pi - 1);
        quick_Sort_giam(d, pi + 1, high);
    }
}
int binary_Search(string d[], int n, string e)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (d[mid] == e)
            return mid;
        else if (d[mid] < e)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
void tinh_tong_chan(int b[], int n)
{
    int tong = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)  //xet dk neu ptu chan thi lay
        {
            tong += b[i];
        }
    }
    cout << "tong cac ptu thu chan : " << tong;
}
void sap_xep(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] % 2 == 0)
            {
                swap(b[i], b[j]);
            }
        }
    }
}
void kt_tang(int b[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++) //duyet tu dau mang den cuoi mang
    {
        if (b[i] < b[i + 1])//neu vt lon hon thi dem++
            dem++;
    }
    if (dem == n - 1)
    {
        cout << "mang tang ";
    }
    else
    {
        cout << "mang khong tang ";
    }
}
int cap_so_cong(int b[], int n)
{
    int d = b[1] - b[0], flag = 1;
    for (int i = 2; i < n; i++)
    {
        if ((b[i + 1]) - b[i] != d)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int tim_vt_max(int b[], int n)
{
    int vtmax = 0, max = b[0];
    for (int i = 0; i < n; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
            vtmax = i;
        }
    }
    return vtmax;
}
int tim_vt_chia(int b[], int n)
{
    int vt, i, temp = -1; //vt la so chia het chia 3 be nhat
    for (i = 0; i < n; i++) //i la vi tri xet tu dau mang den cuoi mang 
    {
        if (b[i] % 3 == 0)
        {
            vt = b[i];
            temp = i;
            break;
        }
    }
    for (int j = i; j < n; j++)
    {
        if (b[j] % 3 == 0 && b[j] < vt)
        {
            vt = b[j];
            temp = j;
        }
    }
    return temp;
}
int mang_tang(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] >= b[i] + 1)
        {
            return i;
        }
    }
    return n - 1;
}
int mang_giam(int b[], int n)  //ham phu de tum mang con tang dai nhat
{
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] < b[i + 1])
        {
            return i;
        }
    }
    return n - 1;
}
void mang_con_tang(int b[], int n)  //ham tim mang con tang dai nhat
{
    int max = 0, j, i = 0, c = 0, d = 0;
    while (i < n - 1)
    {
        if (b[i] < b[i + 1])
        {
            j = mang_tang(b, n);
            if (j - i + 1 > max)
            {
                max = j - i + 1;
                c = i;
                d = j;
            }
            i = j + 1;
        }
        else i = mang_giam(b, n);
    }
    if (max > 0)
    {
        cout << "mang con tang dai nhat : " << endl;
        for (int c = 0; c <= d; c++)
        {
            cout << "a[" << c << "]=" << b[c] << endl;
        }
    }
    else
        cout << "mang nay ko co mang con tang ";
}
void sap_xep_nho_hon_10(int b[], int n)
{
    int temp[1000]; // Tạo mảng tạm thời chứa các phần tử nhỏ hơn 10
    int temp_size = 0; // Kích thước của mảng tạm thời

    // Duyệt mảng b và đưa các phần tử nhỏ hơn 10 vào mảng tạm thời
    for (int i = 0; i < n; i++)
    {
        if (b[i] < 10)
        {
            temp[temp_size] = b[i];
            temp_size++;
        }
    }

    // Sắp xếp mảng tạm thời giảm dần
    for (int i = 0; i < temp_size - 1; i++)
    {
        for (int j = i + 1; j < temp_size; j++)
        {
            if (temp[i] < temp[j])
            {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    int temp_index = 0; // Biến chỉ số để duyệt mảng tạm thời

    // Duyệt lại mảng b, khi gặp các phần tử nhỏ hơn 10, thay thế bằng giá trị từ mảng tạm
    for (int i = 0; i < n; i++)
    {
        if (b[i] < 10)
        {
            b[i] = temp[temp_index];
            temp_index++;
        }
    }
}

//BAI 5: ham sap xep mang mot chieu chua n so nguyen 
int LinearSearch(int b[], int n, int c)  //int c la X
{
    for (int i = 0; i < n; i++)
    {
        if (b[i] == c)
        {
            return i;
        }
    }
}
void InterSortTang(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > n; j++)
        {
            if (b[i] > b[j])
                swap(b[i], b[j]);
        }
    }
}
void InterSortGiam(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] < b[j])
                swap(b[i], b[j]);
        }
    }
}
void SelectSortTang(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imax = i;
        for (int j = i + 1; j < n; j++)
        {
            if (b[imax] > b[j])
            {
                imax = j;
            }
            swap(b[imax], b[i]);
        }
    }
}
void SelectSortGiam(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (b[imin] < b[j])
            {
                imin = j;
            }
            swap(b[imin], b[i]);
        }
    }
}
void QuickSortTang(int b[], int left, int right)
{
    if (left >= right)
        return;
    int ileft = left, iright = right, imid = (left + right) / 2, key = b[imid];
    while (ileft <= iright)
    {
        while (b[ileft] < key)
            ileft++;
        while (b[iright] > key)
            iright--;
        if (ileft <= iright)
        {
            swap(b[ileft], b[iright]);
            ileft++;
            iright--;
        }
        QuickSortTang(b, left, ileft - 1);
        QuickSortTang(b, ileft, right);
    }
}
void QuickSortGiam(int b[], int low, int high) //vi co ham partition o tren roi nen ta ko can viet lai 
{
    if (low < high)
    {
        int pi = partition(b, low, high);
        QuickSortGiam(b, low, pi - 1);
        QuickSortGiam(b, pi + 1, high);
    }
}
int BinarySearch(int b[], int n, int c)  //int c duoc thay bang gt cua X 
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (b[mid] == c)
        {
            return mid;
        }
        else if (b[mid] < c)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

//mang 2 chieu
void nhap_hai_chieu(int f[][50], int& dong, int& cot)
{
    do
    {
        cout << "nhap so dong : ";
        cin >> dong;
    } while (dong <= 0);
    do
    {
        cout << "nhap so cot : ";
        cin >> cot;
    } while (cot <= 0);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "a" << "[" << i << "]" << "[" << j << "]=";
            cin >> f[i][j];
        }
    }
}
void xuat_hai_chieu(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "\t" << f[i][j];
        }
        cout << endl;
    }
}
void xuat_dg_cheo_ss_chinh(int f[][50], int dong, int cot)
{
    cout << "cac ptu tren cac dg cheo song song voi dg cheo chinh : ";
    for (int k = 1 - dong; k < cot; k++)
    {
        for (int i = 0; i < dong; i++)
        {
            int j = i + k;
            if(j>=0&&j<cot)
            {
                cout << f[i][j] << " ";
            }
        }
    }
    cout << endl;
}
void xuat_dg_cheo_ss_phu(int f[][50], int dong, int cot)
{
    cout << "cac ptu tren cac dg cheo song song voi dg cheo chinh : ";
    for (int k = 1 - cot; k < dong; k++)
    {
        for (int i = 0; i < dong; i++)
        {
            int j = cot - i - 1 + k;
            if (j >= 0 && j < cot)
            {
                cout << f[i][j] << " ";
            }
        }
    }
    cout << endl;
}
void dg_cheo_phu(int f[][50], int dong, int cot)
{
    int tong = 0;
    for (int i = 0; i < dong; i++)
    {
        tong += f[i][dong - 1 - i];
    }
    cout << "tong duong cheo phu : " << tong;
}
void dg_cheo_chinh(int f[][50], int dong, int cot)
{
    int tong = 0;
    for (int i = 0; i < dong; i++)
    {
        tong += f[i][i];
    }
    cout << "tong duong cheo chinh : " << tong;
}
void tam_giac_tren(int f[][50], int dong, int cot)
{
    int tong = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (i > j)
            {
                f[i][j] = 0;
            }
            tong += f[i][j];
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << "tong cac ptu tam giac tren : " << tong;
}
void tam_giac_duoi(int f[][50], int dong, int cot)
{
    int tong = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (j > i)
            {
                f[i][j] = 0;
            }
            tong += f[i][j];
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << "tong cac ptu tam giac duoi : " << tong;
}

//xuat cuc dai, cuc tieu, yen ngua va hoang hau
void xuat_cuc_dai(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if ((f[i][j] > f[i][j + 1]) && (f[i][j] > f[i][j - 1]) && (f[i][j] > f[i + 1][j]) && (f[i][j] > f[i - 1][j]) && (f[i][j] > f[i - 1][j - 1]) && (f[i][j] > f[i + 1][j + 1]) && (f[i][j] > f[i - 1][j + 1]) && (f[i][j] > f[i + 1][j - 1]))
            {
                cout << f[i][j];
            }
        }
    }
}
void xuat_cuc_tieu(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if ((f[i][j] < f[i][j + 1]) && (f[i][j] < f[i][j - 1]) && (f[i][j] < f[i + 1][j]) && (f[i][j] < f[i - 1][j]) && (f[i][j] < f[i - 1][j - 1]) && (f[i][j] < f[i + 1][j + 1]) && (f[i][j] < f[i - 1][j + 1]) && (f[i][j] < f[i + 1][j - 1]))
            {
                cout << f[i][j];
            }
        }
    }
}

//xuat hoang hau
bool max_dg_cheo(int f[][50], int dong, int cot, int i, int j)
{
    int k, h;
    for (k = i, h = j; k >= 0 && h < dong; k--, h++)
    {
        if (f[k][h] > f[i][j])
        {
            return false;
        }
    }
    for (k = i + 1, h = j - 1; k < cot && h >= 0; k++, h--)
    {
        if (f[k][h] > f[i][j])
        {
            return false;
        }
    }
    for (k = i - 1, h = j - 1; k >= 0 && h >= 0; k--, h--)
    {
        if (f[k][h] > f[i][j])
        {
            return false;
        }
    }
    for (k = i + 1, h = j + 1; k < cot && h < dong; k++, h++)
    {
        if (f[k][h] > f[i][j])
        {
            return false;
        }
    }
    return true;
}
bool max_dong_cot(int f[][50], int dong, int cot, int i, int j)
{
    for (int k = 0; k < cot; k++)
    {
        if (f[k][j] > f[i][j])
        {
            return false;
        }
    }
    for (int k = 0; k < dong; k++)
    {
        if (f[i][k] > f[i][j])
        {
            return false;
        }
    }
    return true;
}
void xuat_hoang_hau(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (max_dg_cheo(f, dong, cot, i, j) && max_dong_cot(f, dong, cot, i, j))
            {
                cout << f[i][j];
            }
        }
    }
}
void xuat_yen_ngua(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        int temp = f[i][0], socot = 0;
        for (int j = 0; j < cot; j++)
        {
            if (f[i][j] >= temp)
            {
                temp = f[i][j];
                socot = j;
            }
        }
        int dem = 0;
        for (int k = 0; k < dong; k++)
        {
            if (temp < f[k][socot])
            {
                dem++;
            }
        }
        if (dem == dong - 1)
        {
            cout << temp << " ";
        }
    }
}

//tim cuc dai, cuc tieu, yen ngua va hoang hau
void tim_cuc_dai(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (f[i][j] > f[i][j + 1] && f[i][j] > f[i][j - 1] && f[i][j] > f[i + 1][j] && f[i][j] > f[i - 1][j] && f[i][j] > f[i - 1][j - 1] && f[i][j] > f[i + 1][j + 1] && f[i][j] > f[i - 1][j + 1] && f[i][j] > f[i + 1][j - 1])
            {
                cout << "ptu cuc dai lon nhat trong ma tran : " << f[i][j] << " tai vi tri a[" << i << "]" << "[" << j << "]";
            }
        }
    }
}
void tim_cuc_tieu(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (!(j > 0 && f[i][j] >= f[i][j - 1] || j < cot - 1 && f[i][j] >= f[i][j + 1] || i > 0 && f[i][j] >= f[i - 1][j] || i < dong - 1 && f[i][j] >= f[i + 1][j] || i > 0 && j > 0 && f[i][j] >= f[i - 1][j - 1] || i < dong - 1 && j < cot - 1 && f[i][j] >= f[i + 1][j + 1] || i > 0 && j < cot - 1 && f[i][j] >= f[i - 1][j + 1] || i < dong - 1 && j > 0 && f[i][j] >= f[i + 1][j - 1]))
            {
                cout << "ptu cuc tieu lon nhat trong ma tran: " << f[i][j] << " tai vi tri a[" << i << "]" << "[" << j << "]" << endl;
            }
        }
    }
}
void tim_hoang_hau(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (max_dg_cheo(f, dong, cot, i, j) && max_dong_cot(f, dong, cot, i, j))
            {
                cout << "ptu hoang hau lon nhat trong ma tran: " << f[i][j] << " tai vi tri a[" << i << "]" << "[" << j << "]" << endl;
            }
        }
    }
}
bool yen_ngua(int f[][50], int dong, int cot, int x, int y)
{
    bool max_dc = max_dong_cot(f, dong, cot, x, y);
    bool max_cheo = max_dg_cheo(f, dong, cot, x, y);
    return max_dc && max_cheo;
}
void tim_yen_ngua(int f[][50], int dong, int cot)
{
    int max_yen_ngua = f[0][0]; //gia su ptu dau tien la lon nhat
    int dem_max = 0; //so luong ptu yen ngua lon nhat
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (yen_ngua(f, dong, cot, i, j))
            {
                if (f[i][j] > max_yen_ngua)
                {
                    max_yen_ngua = f[i][j];
                    dem_max = 1; //dat lai dem_max vi da tim thay ptu lon hon
                }
                else if (f[i][j] == max_yen_ngua)
                {
                    dem_max++; //tang so luong ptu yen ngua lon nhat
                }
            }
        }
    }
    if (dem_max > 0)
    {
        for (int i = 0; i < dong; i++)
        {
            for (int j = 0; j < cot; j++)
            {
                if (yen_ngua(f, dong, cot, i, j) && f[i][j] == max_yen_ngua)
                {
                    cout << "ptu yen ngua lon nhat trong ma tran : " << max_yen_ngua << " tai vi tri a[" << i << "][" << j << "]" << endl;
                }
            }
        }
    }
    else
    {
        cout << "khong co ptu yen ngua trong ma tran " << endl;
    }
}

//tinh tong ptu nho nhat tren cac dong va lon nhat tren cac cot
int tong_nho_nhat_tren_dong(int f[][50], int dong, int cot)
{
    int tong = 0;
    for (int i = 0; i < dong; i++)
    {
        int min_dong = f[i][0];
        for (int j = 1; j < cot; j++)
        {
            if (f[i][j] < min_dong)
            {
                min_dong = f[i][j];
            }
        }
        tong += min_dong;
    }
    return tong;
}
int tong_lon_nhat_tren_cot(int f[][50], int dong, int cot)
{
    int tong = 0;
    for (int j = 0; j < cot; j++)
    {
        int max_cot = f[0][j];
        for (int i = 1; i < dong; i++)
        {
            if (f[i][j] > max_cot)
            {
                max_cot = f[i][j];
            }
        }
        tong += max_cot;
    }
    return tong;
}

//sap xep tang theo ziczac
void zic_zac(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot - 1; j++)
        {
            if (i % 2 == 0) //neu hang chan sap xep tang dan
            {
                for (int k = j + 1; k < cot; k++)
                {
                    if (f[i][j] > f[i][k])
                        swap(f[i][j], f[i][k]);
                }
            }
            else  // Nếu hàng lẻ, sắp xếp giảm dần
            {
                for (int k = j + 1; k < cot; k++)
                {
                    if (f[i][j] < f[i][k])
                        swap(f[i][j], f[i][k]);
                }
            }
        }
    }
}
bool kt_tang_zic_zac(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        if (i % 2 == 0) //neu ham chan kt tang dan
        {
            for (int j = 0; j < cot - 1; j++)
            {
                if(f[i][j]>f[i][j+1])
                {
                    return false;
                }
            }
        }
        else //neu ham le kt giam dan
        {
            for (int j = 0; j < cot - 1; j++)
            {
                if (f[i][j] < f[i][j + 1])
                {
                    return false;
                }
            }
        }
        if (i > 0)
        {
            if (i % 2 == 0)
            {
                if(f[i][0]<=f[i-1][cot-1])
                    {
                        return false;
                    }
            }
            else
            {
                if (f[i][0] >= f[i - 1][cot - 1])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void sap_xep_tang_theo_cot(int f[][50], int dong, int cot)
{
    for (int j = 0; j < cot; j++)
    {
        for (int i = 0; i < dong - 1; i++)
        {
            for (int k = i + 1; k < dong; k++)
            {
                if (f[i][j] > f[k][j])
                {
                    swap(f[i][j], f[k][j]);
                }
            }
        }
    }
}

//sap xep giam dan theo dong
void bubble_sort(int f[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (f[j] < f[j + 1])
            {
                int temp = f[j];
                f[j] = f[i + 1];
                f[j + 1] = temp;
            }
        }
    }
}
void sap_xep_giam_theo_dong(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        bubble_sort(f[i], cot);
    }
}

//sap xep tang theo duong cheo chinh
void sap_xep_tang_theo_dcc(int f[][50], int dong, int cot)
{
    for (int i = 0; i < dong - 1; i++)
    {
        for (int j = 0; j < cot-1; j++)
        {
            for (int k = 1; k < dong; k++)
            {
                for (int l = 1; l < cot; l++)
                {
                    if (i == j&&k==l)
                    {
                        if (f[i][j] > f[k][l])
                        {
                            swap(f[i][j], f[k][l]);
                        }
                    }
                }
            }
        }
    }
}
void xuat_dg_bien(int f[][50], int dong, int cot)
{
    cout << "cac phan tu thuoc duong bien : " << endl;
    for (int j = 0; j < cot; j++)   // xuat hang dau tien 
    {
        cout << "\t" << f[0][j];
    }
    cout << endl;
    if (dong > 1) //xuat hang cuoi cung ( neu co nhiu hon 1 hang )
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "\t" << f[dong - 1][j];
        }
        cout << endl;
    }
    for (int i = 1; i < dong - 1; i++) //xuat cot dau tien ( loai tru ptu o hang dau va hang cuoi )
    {
        cout << "\t" << f[i][0];
    }
    if (cot > 1) //xuat cot cuoi cung ( loai tru ptu dau va hang cuoi )
    {
        for (int i = 1; i < dong - 1; i++)
        {
            cout << "\t" << f[i][cot - 1];
        }
    }
    cout << endl;
}

//ham kt dg cheo tang dan, giam dan
bool kt_dg_cheo_chinh_tang_dan(int f[][50], int dong, int cot)
{
    for (int i = 1; i < dong; i++)
    {
        if (f[i][i] <= f[i - 1][i - 1])
        {
            return false;
        }
    }
    return true;
}
bool kt_giam_dan_theo_cot(int f[][50], int dong, int cot)
{
    for (int j = 0; j < cot; j++)
    {
        for (int i = 1; i < dong; i++)
        {
            if (f[i][j] > f[i - 1][j])
            {
                return false;
            }
        }
    }
    return true;
}

//phan so
struct PhanSo {
    int tuso, mauso;
};
void random_mau_le(PhanSo g[], int n)
{
    srand(static_cast<unsigned int>(time(0))); //seed thoi gian de co gtri ngau nhien sau moi lan chay
    for (int i = 0; i < n; i++)
    {
        g[i].mauso = 1 + rand() % 100;
        g[i].tuso = rand() % g[i].mauso;
    }
}

void random(PhanSo g[], int n)
{
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++)
    {
        g[i].tuso = rand() % 100;  //tao ngau nhien tu so khoang 0 den 99
        do {
            g[i].mauso = rand() % 100;
        } while (g[i].mauso == 0); // lap lai neu mau so = 0
    }
}

void nhap_phan_so(PhanSo g[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nnhap phan so thu " << i << endl;
        cout << "nhap tu so : ";
        cin >> g[i].tuso;
        do
        {
            cout << "nhap mau so :  ";
            cin >> g[i].mauso;
        } while (g[i].mauso == 0);
    }
}
void xuat_phan_so(PhanSo g[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]=" << g[i].tuso << "/" << g[i].mauso << endl;
    }
    cout << endl;
}

//rut gon phan so
int ucln(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ucln(b, a % b);
}
void rut_gon(PhanSo& ps)
{
    int UCLN = ucln(ps.tuso, ps.mauso);
    ps.tuso /= UCLN;
    ps.mauso /= UCLN;
}
void rut_gon_ps(PhanSo g[], int n)
{
    for (int i = 0; i < n; i++)
    {
        rut_gon(g[i]);
    }
}
PhanSo tim_mau_lon_nhat(PhanSo g[], int n)
{
    PhanSo mau_max = g[0];
    for (int i = 1; i < n; i++)
    {
        if (g[i].mauso > mau_max.mauso)
        {
            mau_max = g[i];
        }
    }
    return mau_max;
}


//sap xep tang/giam theo 3 giai thuat
void bubble_sort_ps(PhanSo g[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i -1; j++)
        {
            if (static_cast<double>(g[j].tuso) / g[j].mauso > static_cast<double>(g[j + 1].tuso) / g[j + 1].mauso)
            {
                swap(g[j],g[j+1]);
            }
        }
    }
}
void select_sort_ps(PhanSo g[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (static_cast<double>(g[j].tuso) / g[j].mauso < static_cast<double>(g[min].tuso) / g[min].mauso)
            {
                min = j;
            }
        }
        swap(g[i], g[min]);
    }
}
void inter_sort_ps(PhanSo g[], int n)
{
    for (int i = 1; i < n; i++)
    {
        PhanSo key = g[i];
        int j = i - 1;
        while (j >= 0 && static_cast<double>(g[j].tuso) / g[j].mauso > static_cast<double>(key.tuso) / key.mauso)
        {
            g[j + 1] = g[j];
            j = j - 1;
        }
        g[j + 1] = key;
    }
}
void xoa_tu_so_bang_mot(PhanSo g[], int &n)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].tuso != 1)
        {
            if (i != index)
            {
                g[index] = g[i];
            }
            index++;
        }
    }
    n = index;
}
int dem_ptu_nho_hon(PhanSo g[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        double value = static_cast<double>(g[i].tuso) / g[i].mauso;
        if (value < 1)
        {
            dem++;
        }
    }
    return dem;
}
double tinh_tong_ps(PhanSo g[], int n)
{
    double tong = 0.0;
    for (int i = 0; i < n; i++)
    {
        double value = static_cast<double>(g[i].tuso) / g[i].mauso;
        tong += value;
    }
    return tong;
}
double tinh_tich_ps(PhanSo g[], int n)
{
    double tich = 1.0;
    for (int i = 0; i < n; i++)
    {
        double value = static_cast<double>(g[i].tuso) / g[i].mauso;
        tich *= value;
    }
    return tich;
}

//them pso x vao trc cuc dai cua mang
bool kt_cuc_dai(PhanSo ps)
{
    return ps.tuso * 1.0 / ps.mauso > 0 && ps.mauso != 0; //ktra pso duong va ko phai la 0
}
void them_cuc_dai(PhanSo*& g, int& n,PhanSo x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (kt_cuc_dai(g[i]))
        {
            dem++;
        }
    }
    PhanSo* h = new PhanSo[n + dem]; //tao mang moi lon hon mang cu so ptu = so luong ptu cuc dai
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (kt_cuc_dai(g[i]))
        {
            h[j++] = x; //them pso x vao trc ptu cuc dai
        }
        h[j++] = g[i]; //copy ptu cua mang cu sang mang moi
    }
    delete[] g; //giai phong mang cu
g = h; //gan con tro mang cu sang mang moi
n = n + dem; //cap nhat so luong ptu moi cua mang
}

//xoa ptu cu c tieu
PhanSo tim_min(PhanSo g[], int n)
{
    PhanSo min = g[0];
    for (int i = 1; i < n; i++)
    {
        if (g[i].tuso * min.mauso < min.tuso * g[i].mauso)
        {
            min = g[i];
        }
    }
    return min;
}
int dem_cuc_tieu(PhanSo g[], int n)
{
    PhanSo min = tim_min(g, n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].tuso * min.mauso == min.tuso * g[i].mauso)
        {
            count++;
        }
    }
    return count;
}
PhanSo* xoa_cuc_tieu(PhanSo g[], int& n)
{
    int count = dem_cuc_tieu(g, n);
    PhanSo minValue = tim_min(g, n);
    PhanSo* h = new PhanSo[n - count];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].tuso * minValue.mauso != minValue.tuso * g[i].mauso)
        {
            h[j++] = g[i];
        }
    }
    delete[] g; //giai phong mang cu
    n -= count;
    return h;
}

//struct
struct SanPham
{
    char ma_sp[5], ten_sp[20], nha_sx[30], loai_sx[20];
    int so_luong;
    double don_gia;
};
void nhap_thong_tin(SanPham p[], int n)
{
    cout << "\n**********NHAP THONG TIN**********" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\nnhap ma san pham thu "<<i<<" : ";
        cin.ignore();
        cin >> p[i].ma_sp;

        cout << "nhap ten san pham : ";
        cin >> p[i].ten_sp;

        cout << "nhap so luong trong kho: ";
        cin >> p[i].so_luong;

        cout << "nhap don gia: ";
        cin >> p[i].don_gia;

        cout << "nhap nha san xuat : ";
        cin.ignore();
        cin >> p[i].nha_sx;

        cout << "nhap loai san pham : ";
        cin >> p[i].loai_sx;
    }
}
void xuat_thong_tin(SanPham p[], int n)
{
    cout << "\n**********XUAT THONG TIN**********" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ma san pham: " << p[i].ma_sp << endl;
        cout << "ten san pham: " << p[i].ten_sp << endl;
        cout << "so luong trong kho: " << p[i].so_luong << endl;
        cout << "don gia: " << p[i].don_gia << endl;
        cout << "nha san xuat: " << p[i].nha_sx << endl;
        cout << "loai san pham: " << p[i].loai_sx << endl;
    }
}

//xuat thong tin cua nha sx Laneige
void xuat_tt_laneige(SanPham p[], int n)
{
    cout << "\n**********XUAT THONG TIN**********" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].nha_sx, "Laneige") == 0)
        {
            cout << "ma san pham: " << p[i].ma_sp << endl;
            cout << "ten san pham: " << p[i].ten_sp << endl;
            cout << "so luong trong kho: " << p[i].so_luong << endl;
            cout << "don gia: " << p[i].don_gia << endl;
            cout << "nha san xuat: " << p[i].nha_sx << endl;
            cout << "loai san pham: " << p[i].loai_sx << endl;
        }
    }
}
int tinh_tong_kem(SanPham p[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        string ten_sp_str = p[i].ten_sp;
        if (ten_sp_str.find("Kem") == 0)
        {
            tong += p[i].so_luong;
        }
    }
    return tong;
}
SanPham tim_sp_gia_max(SanPham p[], int n)
{
    SanPham max = p[0];
    for (int i = 0; i < n; i++)
    {
        if (p[i].don_gia > max.don_gia)
        {
            max = p[i];
        }
    }
    return max;
}

//sap xep san pham tang dan them ma san pham
void sap_xep_sp_tang(SanPham p[], int n)
{
    for (int i = 0; i < n -1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (strcmp(p[j].ma_sp, p[j + 1].ma_sp) > 0)
            {
                swap(p[j], p[j + 1]);
            }
        }
    }
}
void xoa_sp_so_luong_0(SanPham p[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (p[i].so_luong == 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                p[j] = p[j + 1];
            }
            n--;
        }
        else
        {
            i++;
        }
    }
}
int dem_sp_senka(SanPham p[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].nha_sx, "Senka") == 0)
        {
            dem++;
        }
    }
    return dem;
}

//ham de qui mang
void nhap_mang_de_quy(int b[], int n, int index)
{
    if (index == n)
    {
        return;
    }
    cout << "A[" << index << "]=";
    cin >> b[index];
    nhap_mang_de_quy(b, n, index + 1);
}

void xuat_mang_de_quy(int b[], int n, int index)
{
    if (index == n)
    {
        return;
    }
    cout << b[index] << " ";
    xuat_mang_de_quy(b, n, index + 1);
}

int tinh_tong_dq(int b[], int n, int index)
{
    if (index == n)
    {
        return 0;
    }
    return b[index] + tinh_tong_dq(b, n, index + 1);
}
int tinh_tich_dq(int b[], int n, int index)
{
    if (index == n)
    {
        return 1;
    }
    return b[index] * tinh_tich_dq(b, n, index + 1);
}
int tim_min_dq(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
int dem_ptu_duong_dq(int b[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
        {
            dem++;
        }
    }
    return dem;
}
int tong_le_dq(int b[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] % 2 != 0)
        {
            tong += b[i];
        }
    }
    return tong;
}
int tim_max_dq(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

//tinh f(n)
int bai_1(int n)
{
    if (n == 0 || n == 1)
    {
        return 2;
    }
    return 2 * bai_1(n - 1) * bai_1(n - 2);
}
int bai_2(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }
    else
    {
        return 2 * bai_2(n - 1) + 4 * bai_2(n - 2);
    }
}
int bai_3(int n)
{
    if (n == 0)
    {
        return 4;
    }
    else if (n == 1)
    {
        return 2;
    }
    else
    {
        return bai_3(n - 1) + 3 * bai_3(n - 2);
    }
}
int bai_4(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return 2 * bai_4(n / 2) + n;
    }
}
int bai_5(int n)
{
    if (n == 0||n == 1)
    {
        return 1;
    }
    else
    {
        return bai_5(n - 1) + bai_5(n - 2);
    }
}
int bai_6(int n)
{
    if (n == 0)
    {
        return 4;
    }
    else
    {
        return 2 * n * bai_6(n - 1);
    }
}

//tinh S(n)
double bai_7(int n)
{
    double result = 0.0;
    for (int i = 1; i <= n; i++)
    {
        result += (double)(i * (i + 1)) / (i + 1) + sqrt(i + 2);
    }
    return result;
}
double bai_8(int n)
{
    double result = 0.0;
    for (int i = 1; i <= n; i++)
    {
        result += (double)i + sqrt(i) + (double)(i + 1) / (i + 1) + sqrt(tgamma(i + 2));
    }
    return result;
}
int tinhY(int n);
int tinhX(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return tinhX(n - 1) + tinhY(n - 1);
}
int tinhY(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 3 * tinhX(n - 1) + 2 * tinhY(n - 1);
}

//tinh A(n)
int tinhAN(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        int sum = 0;
        for (int i = 1; i <= n - 1; ++i)
        {
            sum += tinhAN(i);
        }
        return n * sum;
    }
}
int tinhXN(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 2;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i * tinhXN(i);
    }
    return sum;
}
int tinhAn_mot(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return n + tinhAn_mot(n - 1) + 2;
    }
    else
    {
        return n * n + tinhAn_mot(n - 1) * tinhAn_mot(n) + 1;
    }
}
int tinhAn_hai(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else if (n % 2 == 1)
    {
        return tinhAn_hai(n - 1) + 2 * tinhAn_hai(n - 2);
    }
    else
    {
        return tinhAn_hai(n - 2) + 2 * tinhAn_hai(n - 3);

    }
}

//tinh fibo
int fibo(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0||n == 1)
    {
        return n;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}
int fibo_max(int n)
{
    int i = 0;
    while (fibo(i) < n)
    {
        i++;
    }
    return fibo(i - 1);
}
void fibo_thuoc_khoang(int n, int m)
{
    int i = 0;
    while (fibo(i) <= n)
    {
        int j = fibo(i);
        if (j >= m)
        {
            cout << j << " ";
        }
        i++;
    }
    cout << endl;
}
void main()
{
    int* a = new int;
    int n, chon, x, c, b[50], sodien, m; //cho int c la X cua case so 18 va case so 42
    int f[50][50], dong, cot; //bien nay la bien cua ma tran 
    string d[50], e;//cho stirng e la X cua case 26
    SanPham p[100]; //struct san pham
    int index = 0; //bien nay danh cho case 91 ham de qui

    cout << "========================= MENU ========================= " << endl;

    //+++++++++++++++++++++++BAI SO 1+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 1+++++++++++++++++++++++ " << endl;
    cout << "1. nhap xuat mang ngau nhien " << endl;
    cout << "2. xuat pt tu co so nguyen to " << endl;
    cout << "3. xuat ptu co thap phan " << endl;
    cout << "4. dem ptu co chua so 2 " << endl;
    cout << "5. xoa ptu co phan nguyen la le " << endl;
    cout << "6. tim trong a co ptu X " << endl;
    cout << "7. xoa ptu max " << endl;
    cout << "8. xoa ptu min " << endl;
    cout << "9. them X vao sau so MAX, them X vao truoc so MIN " << endl;
    cout << "10. sap xep tang theo Interchange Sort " << endl;
    cout << "11. sap xep giam theo Interchange Sort " << endl;
    cout << "12. sap xep tang theo Selection Sort " << endl;
    cout << "13. sap xep giam theo Selection Sort  " << endl;
    cout << "14. sap xep tang theo Quick Sort " << endl;
    cout << "15. sap xep giam theo Quick Sort " << endl;

    //+++++++++++++++++++++++BAI SO 2+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 2+++++++++++++++++++++++ " << endl;
    cout << "16. tinh tien dien " << endl;

    //+++++++++++++++++++++++BAI SO 3+++++++++++++++++++++++
    //mang 1 a chua n so nguyen sau 8  5  3  0  7  11  4 
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 3+++++++++++++++++++++++ " << endl;
    cout << "17. tim X=3, X=6 trong a theo Linear Search " << endl;
    cout << "18. sap xep mang A tang theo Interchange Sort " << endl;
    cout << "19. sap xep mang A giam theo Interchange Sort  " << endl;
    cout << "20. sap xep mang A tang theo Selection Sort " << endl;
    cout << "21. sap xep mang A giam theo Selection Sort " << endl;
    cout << "22. sap xep mang A tang theo Quick Sort " << endl;
    cout << "23. sap xep mang A giam theo Quick Sort " << endl;
    cout << "24. tim X=5, X=8, X=1, X=10 trong a theo Binary Search " << endl;

    //+++++++++++++++++++++++BAI SO 4+++++++++++++++++++++++
    //mang 1 a chua n ki tu sau H  K  E  C  L  M  I  B
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 4+++++++++++++++++++++++ " << endl;
    cout << "25. tim x=C, x=D trong a theo Linear Search " << endl;
    cout << "26. sap xep mang A tang theo Interchange Sort " << endl;
    cout << "27. sap xep mang A giam theo Interchange Sort " << endl;
    cout << "28. sap xep mang A tang theo Selection Sort " << endl;
    cout << "29. sap xep mang A giam theo Selection Sort " << endl;
    cout << "30. sap xep mang A tang theo Quick Sort " << endl;
    cout << "31. sap xep mang A giam theo Quick Sort " << endl;
    cout << "32. tim x=H, x=I, x=T, x=Y trong a theo Binary Search " << endl;

    //+++++++++++++++++++++++BAI SO 5+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 5+++++++++++++++++++++++ " << endl;
    cout << "33. tim vt so ng to lon nhat trong mang " << endl;
    cout << "34. tinh tong cac so co hang o vi tri le la chan " << endl;
    cout << "35. sap xep mang chan tang dan, le giu nguyen vi tri " << endl;
    cout << "36. kiem tra mang co tang hay khong " << endl;
    cout << "37. kiem tra mang co cap so cong hay khong  " << endl;
    cout << "38. tim vt cua ptu le lon nhat  " << endl;
    cout << "39. tim vt cua ptu chia het cho 3 " << endl;
    cout << "40. xuat day con tang dai nhat " << endl;
    cout << "41. sap xeo mang cac ptu nho hon 10 giam dan, con lai giu nguyen vi tri " << endl;  //bai nay chua lam 
    cout << "42. tim X trong a theo Linear Search " << endl;
    cout << "43. sap xep mang A tang theo Interchange Sort " << endl;
    cout << "44. sap xep mang A giam theo Interchange Sort " << endl;
    cout << "45. sap xep mang A tang theo Selection Sort " << endl;
    cout << "46. sap xep mang A giam theo Selection Sort " << endl;
    cout << "47. sap xep mang A tang theo Quick Sort " << endl;
    cout << "48. sap xep mang A giam theo Quick Sort " << endl;
    cout << "49. tim X trong a theo Binary Search " << endl;

    //+++++++++++++++++++++++BAI SO 6+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 6+++++++++++++++++++++++ " << endl;
    cout << "50. tinh tong cac ptu nam tren dg cheo phu " << endl;
    cout << "51. tinh tong cac ptu nam tren dg cheo chinh " << endl;
    cout << "52. tinh tong cac ptu tam giac tren " << endl;
    cout << "53. tinh tong cac ptu tam giac duoi " << endl;
    cout << "54. xuat ptu thuoc dg cheo song song voi dg cheo chinh " << endl;
    cout << "55. xuat ptu thuoc dg cheo song song voi dg cheo phu " << endl;
    cout << "56. xuat ptu cuc dai " << endl;
    cout << "57. xuat ptu cuc tieu " << endl;
    cout << "58. xuat ptu hoang hau " << endl;
    cout << "59. xuat ptu yen ngua " << endl;
    cout << "60. tim ptu cuc dai lon nhat " << endl;
    cout << "61. tim ptu cuc tieu lon nhat " << endl;
    cout << "62. tim ptu hoang hau lon nhat " << endl;
    cout << "63. tim ptu yen ngua lon nhat " << endl;
    cout << "64. tong cac ptu nho nhat tren dong " << endl;
    cout << "65. tong cac ptu lon nhat tren cot " << endl;
    cout << "66. sap xep tang theo zic zac theo huong tu trai qua phai, tu tren xuong duoi " << endl;
    cout << "67. kiem tra a co tang theo zic zac khong " << endl;
    cout << "68. sap xep tang dan theo cot " << endl;
    cout << "69. sap xep giam dan theo dong " << endl;
    cout << "70. sap xep tang dan theo duong cheo chinh " << endl;
    cout << "71. xuat cac ptu thuoc duong bien " << endl;
    cout << "72. kiem tra duong cheo chinh tang dan " << endl;
    cout << "73. kiem tra giam dan theo tung cot " << endl;

    //+++++++++++++++++++++++BAI SO 7+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 7+++++++++++++++++++++++ " << endl;
    cout << "74. tao mang ngau nhien voi mau la so le " << endl;
    cout << "75. rut gon phan so " << endl;
    cout << "76. tim ptu co mau lon nhat " << endl;
    cout << "77. xoa tu so bang 1" << endl;
    cout << "78. sap xep tang/giam theo 3 giai thuat " << endl;
    cout << "79. dem ptu nho hon 1 " << endl;
    cout << "80. tinh tong cac ptu " << endl;
    cout << "81. tinh tich cac ptu " << endl;
    cout << "82. them phan so X vao  truoc cuc dai " << endl;
    cout << "83. xoa cac phan tu cuc tieu " << endl;

    //+++++++++++++++++++++++BAI SO 8+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 8+++++++++++++++++++++++ " << endl;
    cout << "84. xuat thong tin cac san pham " << endl;
    cout << "85. xuat thong tin san pham cua nha san xuat 'Laneige' " << endl;
    cout << "86. tinh tong cac san pham co ten bat dau bang tu 'Kem' " << endl;
    cout << "87. tim san pham co don gia cao nhat " << endl;
    cout << "88. sap xep danh sach tang dan theo ma san pham " << endl;
    cout << "89. xoa cac san pham co so luong la 0 " << endl;
    cout << "90. dem so san pham cua cac nha san xuat 'Senka' " << endl;

    //+++++++++++++++++++++++BAI SO 9+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 9+++++++++++++++++++++++ " << endl;
    cout << "91. tinh tong mang 1 chieu" << endl;
    cout << "92. tinh tich mang 1 chieu" << endl;
    cout << "93. tim phan tu nho nhat cua mang 1 chieu " << endl;
    cout << "94. dem so phan tu duong cua mang 1 chieu " << endl;
    cout << "95. tinh tong cac so le trong mang 1 chieu " << endl;
    cout << "96. tim phan tu lon nhat cua mang 1 chieu" << endl;

    cout << "97. tinh f(n) biet f(0)=f(1)=2, f(n)=2*f(n-1)*f(n-2) " << endl;
    cout << "98. tinh f(n) biet f(0) = 1, f(1) = 2, f(n) = 2 * f(n - 1) + 4 * f(n - 2) " << endl;
    cout << "99. tinh f(n) biet f(0) = 4, f(1) = 2, f(n) = f(n - 1) + 3 * f(n - 2) " << endl;
    cout << "100. tinh f(n) biet f(0) = 1, f(n) = 2 * f(⌊n / 2⌋) + n; biet rang (⌊n / 2⌋) la phan nguyen khi chia n cho 2 " << endl;
    cout << "101. tinh f(n) biet f(0) = 1, f(1) = 1, f(n) = f(n - 1) + f(n - 2) " << endl;
    cout << "102. tinh f(n) biet f(0) = 4, f(n) = 2 * n * f(n - 1) " << endl;
    cout << "103. tinh S(n) = 1.2!/2+√3 + 2.3!/3 +√4+ 3.4!/4+√5 +..+ n.(n+1)!/(n+1)+√(n+2) " << endl;
    cout << "104. tinh S(n) = 1 + √1 + 2 / 2 + √3!+ 2 + √2 + 3 / 3 + √4!+ 3 + √3 + 4 / 4 + √5!+ .. + n + √n + n + 1 / (n + 1) + √(n + 2)! " << endl;
   
    //+++++++++++++++++++++++BAI SO 10+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 10+++++++++++++++++++++++ " << endl;
    cout << "105. tinh so hang thu n cua 2 day sau : x0 = 1, y0 = 0, xn = xn-1 + yn-1 voi moi n > 0 yn = 3xn-1 + 2yn-1 voi moi n > n " << endl;

    //+++++++++++++++++++++++BAI SO 11+++++++++++++++++++++++
    //viet ham tinh A(n) va X(n) theo de quy
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 11+++++++++++++++++++++++ " << endl;
    cout << "106. day A(n) duoc cho nhu sau : A1 = 1; An = n(A1 + A2 + ... + An - 1) " << endl;
    cout << "107. cho day so X(n) duoc dinh nghia nhu sau : x0 = 1; x1 = 2; xn = nx0 + (n - 1)x1 + ... + xn - 1  (dk : 𝑛 >= 0) " << endl;

    //+++++++++++++++++++++++BAI SO 12+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 12+++++++++++++++++++++++ " << endl;
    cout << "108. day A(n) duoc cho nhu sau: A1 = 1, A2n = n + An + 2, A2n + 1 = n2 + An.An + 1 + 1 " << endl;
    cout << "109. day A(n) duoc cho nhu sau: A1=A2=1, A2n + 3 = A2n + 2 + 2A2n + 1 " << endl;

    //+++++++++++++++++++++++BAI SO 13+++++++++++++++++++++++
    cout << endl;
    cout << "+++++++++++++++++++++++BAI SO 13+++++++++++++++++++++++ " << endl;
    cout << "110. xuat so Fibonaci thu tu n " << endl;
    cout << "111. xuat so Fibonaci lon nhat va < m voi m la tham so cua ham " << endl;
    cout << "112. xuat cac so Fibonaci thuoc khoang[m, n] voi m, n la tham so cua ham " << endl;

    cout << "\n========================================================= " << endl;
    cout << endl;
    cout << "moi ban chon bai : ";
    cin >> chon;
    switch (chon)
    {
    case 1: cout << "nhap n ptu : ";
        cin >> n;
        a = new int[n];
        nhap_random(a, n);
        cout << "xuat mang : ";
        xuat_mang(a, n);
        delete[] a;
        break;
    case 2: cout << "nhap n ptu : ";
        cin >> n;
        a = new int[n];
        nhap_mang(a, n);
        cout << "xuat mang : ";
        xuat_mang(a, n);
        cout << "so nguyen to la : ";
        liet_ke_ngto(a, n);
        delete[] a;
        break;
    case 3: cout << "nhap n ptu : ";
        cin >> n;
        a = new int[n];
        nhap_mang(a, n);
        cout << "xuat mang : ";
        xuat_mang(a, n);
        cout << "cac so sau phan thap phan la : ";
        xuat_thap_phan(a, n);
        delete[] a;
        break;
    case 4: cout << "nhap n ptu : ";
        cin >> n;
        a = new int[n];
        nhap_mang(a, n);
        cout << "xuat mang : ";
        xuat_mang(a, n);
        cout << "ptu co chua chu so 2 la : " << dem_hai_chu_so(a, n);
        delete[] a;
        break;
    case 5: cout << "nhap n ptu : ";
        cin >> n;
        a = new int[n];
        nhap_mang(a, n);
        cout << "xuat mang : ";
        xuat_mang(a, n);
        xoa_so_le(a, n);
        cout << "mang sau khi da xoa cac so le : ";
        xuat_mang(a, n);
        delete[] a;
        break;
    case 6: cout << "nhap n ptu : ";
        cin >> n;
        a = new int[n];
        nhap_mang(a, n);
        cout << "xuat mang : ";
        xuat_mang(a, n);
        cout << "nhap x : ";
        cin >> x;
        tim_x(a, n, x);
        delete[] a;
        break;
    case 7:
    {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "So luong phan tu phai lon hon 0!" << endl;
            break;
        }
        a = new int[n];
        nhap_mang(a, n);
        cout << "Mang sau khi nhap: ";
        xuat_mang(a, n);
        int vtmax = xoa_max(a, n);
        cout << "Xoa phan tu lon nhat: ";
        xoa(a, n, vtmax);
        xuat_mang(a, n);
        delete[] a;
        break;
    }
    case 8:
    {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "So luong phan tu phai lon hon 0!" << endl;
            break;
        }
        a = new int[n];
        nhap_mang(a, n);
        cout << "Mang sau khi nhap: ";
        xuat_mang(a, n);
        int vtmin = xoa_min(a, n);
        cout << "Xoa phan tu nho nhat: ";
        xoa(a, n, vtmin);
        xuat_mang(a, n);
        delete[] a;
        break;
    }
    case 9: cout << "nhap n ptu : ";
        cin >> n;
        a = new int[n];
        nhap_mang(a, n);
        xuat_mang(a, n);
        cout << "nhap x: ";
        cin >> x;
        them_x_max(a, n, x);
        cout << "mang sau khi them x vao sau so lon nhat: ";
        xuat_mang(a, n);

        them_x_min(a, n, x);
        cout << "mang sau khi them x vao sau so nho nhat: ";
        xuat_mang(a, n);
        break;

    case 10: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang(a, n);
        cout << "mang vua nhap : ";
        xuat_mang(a, n);
        inter_sort_tang(a, n);
        cout << "mang sap xep tang : ";
        xuat_mang(a, n);
        break;
    case 11: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang(a, n);
        cout << "mang vua nhap : ";
        xuat_mang(a, n);
        inter_sort_giam(a, n);
        cout << "mang sap xep giam : ";
        xuat_mang(a, n);
        break;
    case 12: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang(a, n);
        cout << "mang vua nhap : ";
        xuat_mang(a, n);
        select_sort_tang(a, n);
        cout << "mang sap xep tang : ";
        xuat_mang(a, n);
        break;
    case 13: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang(a, n);
        cout << "mang vua nhap : ";
        xuat_mang(a, n);
        select_sort_giam(a, n);
        cout << "mang sap xep giam : ";
        xuat_mang(a, n);
        break;
    case 14: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang(a, n);
        cout << "mang vua nhap : ";
        xuat_mang(a, n);
        quick_sort_tang(a, 0, n - 1);
        cout << "mang sap xep tang : ";
        xuat_mang(a, n);
        break;
    case 15: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang(a, n);
        cout << "mang vua nhap : ";
        xuat_mang(a, n);
        quick_sort_giam(a, 0, n - 1);
        cout << "mang sap xep giam : ";
        xuat_mang(a, n);
        break;
        //BAI SO 2: tinh tien dien 
    case 16: cout << "nhap so tien dien can tinh : ";
        cin >> sodien;
        cout << tinh_tien(sodien);
        break;

        //BAI SO 3: sap xep mang theo SO NGUYEN
    case 17: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        cout << "nhap X : ";
        cin >> c;
        cout << "tim duoc x tai vi tri : " << Linear_Search(b, c, n);
        break;
    case 18: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Inter_Sort_Tang(b, n);
        cout << "mang sap xep tang : ";
        Xuat_Mang(b, n);
        break;
    case 19: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Inter_Sort_Giam(b, n);
        cout << "mang sap xep giam : ";
        Xuat_Mang(b, n);
        break;
    case 20: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Select_Sort_Tang(b, n);
        cout << "mang sap xep tang : ";
        Xuat_Mang(b, n);
        break;
    case 21: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Select_Sort_Giam(b, n);
        cout << "mang sap xep giam : ";
        Xuat_Mang(b, n);
        break;
    case 22: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Quick_Sort_Tang(b, 0, n - 1);
        cout << "mang sap xep tang : ";
        Xuat_Mang(b, n);
        break;
    case 23: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Quick_Sort_Giam(b, 0, n - 1);
        cout << "mang sap xep giam : ";
        Xuat_Mang(b, n);
        break;
    case 24: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        cout << "nhap X : ";
        cin >> c;
        cout << "tim duoc x tai vi tri : " << Binary_Search(b, n, c);
        break;

        //BAI SO 4: sap xep mang theo KI TU
    case 25: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        cout << "nhap X : ";
        cin >> e;
        cout << "tim duoc x tai vi tri : " << linear_Serach(d, n, e);
        break;
    case 26: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        inter_Sort_tang(d, n);
        cout << "mang sap xep tang : ";
        xuat_Mang(d, n);
        break;
    case 27: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        inter_Sort_giam(d, n);
        cout << "mang sap xep giam : ";
        xuat_Mang(d, n);
        break;
    case 28: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        select_Sort_tang(d, n);
        cout << "mang sap xep tang : ";
        xuat_Mang(d, n);
        break;
    case 29: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        select_Sort_giam(d, n);
        cout << "mang sap xep giam : ";
        xuat_Mang(d, n);
        break;
    case 30: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        quick_Sort_tang(d, 0, n - 1);
        cout << "mang sap xep tang : ";
        xuat_Mang(d, n);
        break;
    case 31: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        quick_Sort_giam(d, 0, n - 1);
        cout << "mang sap xep giam : ";
        xuat_Mang(d, n);
        break;
    case 32: cout << "nhap n ptu : ";
        cin >> n;
        nhap_Mang(d, n);
        cout << "mang vua nhap : ";
        xuat_Mang(d, n);
        cout << endl;
        cout << "nhap X : ";
        cin >> e;
        cout << "tim duoc x tai vi tri : " << binary_Search(d, n, e);
        break;

        //BAI SO 5: mang 1 chieu
    case 33: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        cout << "vi tri lon nhat : " << vi_tri(b, n);
        break;
    case 34: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        tinh_tong_chan(b, n);
        break;
    case 35: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        cout << "mang sau khi sap xep : ";
        sap_xep(b, n);
        Xuat_Mang(b, n);
        break;
    case 36: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        kt_tang(b, n);
        break;
    case 37: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        if (cap_so_cong(b, n) == 1)
        {
            cout << "cac ptu trong mang lap thanh CSC voi cong sai " << d;
        }
        else
        {
            cout << "khong thoa dieu kien ";
        }
        break;
    case 38: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        cout << "vt lon nhat ptu le trong mang : " << tim_vt_max(b, n);
        break;
    case 39: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        if (tim_vt_chia(b, n) != -1)
            cout << "vi tri chia het cho 3 : " << tim_vt_chia(b, n);
        else
            cout << "khong tim thay vi tri ";
        break;
    case 40: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        mang_con_tang(b, n);
        break;
    case 41: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        sap_xep_nho_hon_10(b, n);
        cout << endl;
        cout << "mang sau khi sap xep: ";
        Xuat_Mang(b, n);
        break;
    case 42: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        cout << "nhap X : ";
        cin >> c;
        cout << "tim duoc x tai vi tri : " << LinearSearch(b, c, n);
        break;
    case 43: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        InterSortTang(b, n);
        cout << "mang sap xep tang : ";
        Xuat_Mang(b, n);
        break;
    case 44: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        InterSortGiam(b, n);
        cout << "mang sap xep giam : ";
        Xuat_Mang(b, n);
        break;
    case 45: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Select_Sort_Tang(b, n);
        cout << "mang sap xep tang : ";
        Xuat_Mang(b, n);
        break;
    case 46: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Select_Sort_Giam(b, n);
        cout << "mang sap xep giam : ";
        Xuat_Mang(b, n);
        break;
    case 47: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Quick_Sort_Tang(b, 0, n - 1);
        cout << "mang sap xep tang : ";
        Xuat_Mang(b, n);
        break;
    case 48: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        Quick_Sort_Giam(b, 0, n - 1);
        cout << "mang sap xep giam : ";
        Xuat_Mang(b, n);
        break;
    case 49: cout << "nhap n ptu : ";
        cin >> n;
        Nhap_Mang(b, n);
        cout << "mang vua nhap : ";
        Xuat_Mang(b, n);
        cout << endl;
        cout << "nhap X : ";
        cin >> c;
        cout << "tim duoc x tai vi tri : " << BinarySearch(b, n, c);
        break;

        //BAI SO 6: mang 2 chieu
    case 50: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        dg_cheo_phu(f, dong, cot);
        break;
    case 51: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        dg_cheo_chinh(f, dong, cot);
        break;
    case 52: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        tam_giac_tren(f, dong, cot);
        break;
    case 53: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        tam_giac_duoi(f, dong, cot);
        break;
    case 54: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        xuat_dg_cheo_ss_chinh(f, dong, cot);
        break;
    case 55: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        xuat_dg_cheo_ss_phu(f, dong, cot);
        break;
    case 56: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << "ptu cuc dai trong ma tran : ";
        xuat_cuc_dai(f, dong, cot);
        break;
    case 57: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << "ptu cuc tieu trong ma tran : ";
        xuat_cuc_tieu(f, dong, cot);
        break;
    case 58: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << "ptu hoang hau trong ma tran : ";
        xuat_hoang_hau(f, dong, cot);
        break;
    case 59: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << "ptu yen ngua trong ma tran : ";
        xuat_yen_ngua(f, dong, cot);
        break;
    case 60:  nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        tim_cuc_dai(f, dong, cot);
        break;
    case 61:  nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        tim_cuc_tieu(f, dong, cot);
        break;
    case 62:  nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        tim_hoang_hau(f, dong, cot);
        break;
    case 63:  nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        tim_yen_ngua(f, dong, cot);
        break;
    case 64:  nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << "tong cac ptu nho nhat tren cac dong : " << tong_nho_nhat_tren_dong(f, dong, cot);
        break;
    case 65:  nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << "tong cac ptu lon nhat tren cac cot : " << tong_lon_nhat_tren_cot(f, dong, cot);
        break;
    case 66: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << endl;
        zic_zac(f, dong, cot);
        cout << "mang sau khi zic zac : " << endl;
        xuat_hai_chieu(f, dong, cot);
        break;
    case 67: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << endl;
        zic_zac(f, dong, cot);
        cout << "mang sau khi zic zac : " << endl;
        xuat_hai_chieu(f, dong, cot);
        if (kt_tang_zic_zac(f, dong, cot))
        {
            cout << "mang tang zic zac";
        }
        else
        {
            cout << "mang khong tang zic zac";
        }
        break;
    case 68: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << endl;
        sap_xep_tang_theo_cot(f, dong, cot);
        cout << "mang sau khi sap xep tang theo cot : " << endl;
        xuat_hai_chieu(f, dong, cot);
        break;
    case 69: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << endl;
        sap_xep_giam_theo_dong(f, dong, cot);
        cout << "mang sau khi sap xep giam theo dong : " << endl;
        xuat_hai_chieu(f, dong, cot);
        break;
    case 70: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << endl;
        sap_xep_tang_theo_dcc(f, dong, cot);
        cout << "mang sau khi sap xep giam theo dong : " << endl;
        xuat_hai_chieu(f, dong, cot);
        break;
    case 71: nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        cout << endl;
        xuat_dg_bien(f, dong, cot);
        break;
    case 72: 
    {
        nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        bool tang_dan = kt_dg_cheo_chinh_tang_dan(f, dong, cot);
        if (tang_dan)
        {
            cout << "duong cheo chinh cua mang tang dan " << endl;
        }
        else
        {
            cout << "duong cheo chinh cua mang khong tang dan " << endl;
        }
        break;
    }
    case 73:
    {
        nhap_hai_chieu(f, dong, cot);
        cout << "Noi dung cua mang : " << endl;
        xuat_hai_chieu(f, dong, cot);
        bool giam_dan = kt_giam_dan_theo_cot(f, dong, cot);
        if (kt_giam_dan_theo_cot(f, dong, cot))
        {
            cout << "mang hai chieu giam dan theo tung cot." << endl;
        }
        else
        {
            cout << "mang hai chieu khong giam dan theo tung cot." << endl;
        }
        break;
    }

     //BAI SO 7: phan so  
    case 74:
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random_mau_le(g, n);
        cout << "xuat mang phan so : "<<endl;
        xuat_phan_so(g, n);
        delete[] g;
        break;
    }
    case 75:
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        rut_gon_ps(g, n);
        cout << "phan so da rut gon : " << endl;
        xuat_phan_so(g, n);
        delete[] g;
        break;
    }
    case 76: 
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        PhanSo mau_max = tim_mau_lon_nhat(g, n);
        cout << "phan so co mau lon nhat : " << mau_max.tuso << "/" << mau_max.mauso << endl;
        break;
    }
    case 77:
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        nhap_phan_so(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        xoa_tu_so_bang_mot(g, n);
        cout << "mang sau khi xoa cac tu so bang 1 : " << endl;
        xuat_phan_so(g, n);
        break;
    }
    case 78:
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);

        cout << "sap xep theo bubble sort : " << endl;
        bubble_sort_ps(g,n);
        xuat_phan_so(g, n);

        cout << "sap xep theo inter sort : " << endl;
        inter_sort_ps(g, n);
        xuat_phan_so(g, n);

        cout << "sap xep theo select sort : " << endl;
        select_sort_ps(g, n);
        xuat_phan_so(g, n);
    }
    case 79: 
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        cout<<"so ptu phan so nho hon 1 trong mang : "<<dem_ptu_nho_hon(g, n);
        break;
    }
    case 80:
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        cout << "tong cac ptu phan so : " << tinh_tong_ps(g, n);
        break;
    }
    case 81:
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        cout << "tich cac ptu phan so : " << tinh_tich_ps(g, n);
        break;
    }
    case 82:
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        PhanSo x;
        cout << "nhap phan so X can them : "<<endl;
        cout << "nhap tu so : ";
        cin >> x.tuso;
        do
        {
            cout << "nhap mau so : ";
            cin >> x.mauso;
        } while (x.mauso==0);
        cout << endl;
        them_cuc_dai(g, n, x);
        cout << "mang sau khi them phan so X truoc cuc dai : " << endl;
        xuat_phan_so(g, n);
        break;
    }
    case 83: 
    {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        PhanSo* g = new PhanSo[n];
        random(g, n);
        cout << "xuat mang phan so : " << endl;
        xuat_phan_so(g, n);
        PhanSo* h = xoa_cuc_tieu(g, n);
        cout << "Mang sau khi xoa cac phan tu cuc tieu: " << endl;
        xuat_phan_so(h, n);
        delete[] h; // giai phong mang moi sau khi xoa
        break;
    }
    
    //BAI SO 8: struct
    case 84: cout << "nhap so luong san pham : ";
        cin >> n;
        nhap_thong_tin(p, n);
        xuat_thong_tin(p, n);
        break;
    case 85:  cout << "nhap so luong san pham : ";
        cin >> n;
        nhap_thong_tin(p, n);
        cout << "\ncac san pham cua nha san xuat 'Laneige' : ";
        xuat_tt_laneige(p, n);
        break;
    case 86: cout << "nhap so luong san pham : ";
        cin >> n;
        nhap_thong_tin(p, n);
        xuat_thong_tin(p, n);
        cout<<"\ntong so luong san pham co ten bat dau bang 'Kem' : " << tinh_tong_kem(p, n);
        break;
    case 87: cout << "nhap so luong san pham : ";
        cin >> n;
        nhap_thong_tin(p, n);
        xuat_thong_tin(p, n);
        SanPham sp_max = tim_sp_gia_max(p, n);
        cout << "\n**********SAN PHAM CO DON GIA CAO NHAT********** " << endl;
        cout << "ma san pham : " << sp_max.ma_sp << endl;
        cout << "ten san pham : " << sp_max.ten_sp << endl;
        cout << "so luong trong kho : " << sp_max.so_luong << endl;
        cout << "don gia : " << sp_max.don_gia << endl;
        cout << "nha san xuat : " << sp_max.nha_sx << endl;
        cout << "loai san pham : " << sp_max.loai_sx << endl;
        break;
    case 88: cout << "nhap so luong san pham : ";
        cin >> n;
        nhap_thong_tin(p, n);
        sap_xep_sp_tang(p, n);
        cout << "**********DANH SACH SAN PHAM SAU KHI SAP XEP**********" << endl;
        xuat_thong_tin(p, n);
        break;
    case 89: cout << "nhap so luong san pham : ";
        cin >> n;
        nhap_thong_tin(p, n);
        xoa_sp_so_luong_0(p, n);
        cout << "**********DANH SACH SAN PHAM SAU KHI XOA SO LUONG LA 0**********" << endl;
        xuat_thong_tin(p, n);
        break;
    case 90: cout << "nhap so luong san pham : ";
        cin >> n;
        nhap_thong_tin(p, n);
        xuat_thong_tin(p, n);
        cout << "so san pham cua nha san xuat 'Senka' : " << dem_sp_senka << endl;
        break;

    //BAI SO 9: de qui
    case 91: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang_de_quy(b, n, index);
        cout << "xuat mang : ";
        xuat_mang_de_quy(b, n, index);
        cout << "\ntong cac ptu : " << tinh_tong_dq(b, n, index);
        break;
    case 92: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang_de_quy(b, n, index);
        cout << "xuat mang : ";
        xuat_mang_de_quy(b, n, index);
        cout << "\ntich cac ptu : " << tinh_tich_dq(b, n, index);
        break;
    case 93: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang_de_quy(b, n, index);
        cout << "xuat mang : ";
        xuat_mang_de_quy(b, n, index);
        cout << "\nptu nho nhat : " << tim_min_dq(b, n);
        break;
    case 94: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang_de_quy(b, n, index);
        cout << "xuat mang : ";
        xuat_mang_de_quy(b, n, index);
        cout<<"\ncac ptu duong : " << dem_ptu_duong_dq(b, n);
        break;
    case 95: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang_de_quy(b, n, index);
        cout << "xuat mang : ";
        xuat_mang_de_quy(b, n, index);
        cout << "\nso ptu duong: " << tong_le_dq(b, n);
        break;
    case 96: cout << "nhap n ptu : ";
        cin >> n;
        nhap_mang_de_quy(b, n, index);
        cout << "xuat mang : ";
        xuat_mang_de_quy(b, n, index);
        cout << "\nptu lon nhat : " << tim_max_dq(b, n);
        break;

    //tinh f(n)
    case 97: cout << "nhap gia tri n : ";
        cin >> n;
        cout<<"gia tri cua f(n) : "<<bai_1(n);
        break;
    case 98: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua f(n) : " << bai_2(n);
        break;
    case 99: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua f(n) : " << bai_3(n);
        break;
    case 100: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua f(n) : " << bai_4(n);
        break;
    case 101: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua f(n) : " << bai_5(n);
        break;
    case 102: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua f(n) : " << bai_6(n);
        break;
    case 103: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua S(n) : " << bai_7(n);
        break;
    case 104: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua S(n) : " << bai_8(n);
        break;
    
    //BAI SO 10 tinh so hang thu n
    case 105: cout << "nhap gia tri n : ";
        cin >> n;
        if (n < 0) {
            cout << "gia tri khong hop le! " << endl;
        }
        else {
            cout << "x" << n << " = " << tinhX(n) << endl;
            cout << "y" << n << " = " << tinhY(n) << endl;
        }
        break;

    //BAI SO 11 tinh A(n) và X(n)
    case 106: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua A(n) : " << tinhAN(n);
        break;
    case 107: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua A(n) : " << tinhXN(n);
        break;
    case 108: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua A(" << n <<"): " << tinhAn_mot(n);
        break;
    case 109: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "gia tri cua A(" << n << "): " << tinhAn_hai(n);
        break;

    //BAI SO 12 tinh fibo
    case 110: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "day so Fibonacci : " << fibo(n);
        break;
    case 111: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "so Fibonacci lon nhat nho hon " << n << " la: " << fibo_max(n) << endl;
        break;
    case 112: cout << "nhap gia tri n : ";
        cin >> n;
        cout << "nhap gia tri m : ";
        cin >> m;
        cout << "cac so Fibonacci thuoc khoang [" << m << ", " << n << "] la: ";
        fibo_thuoc_khoang(m, n);
        break;
    default: cout << "ban nhap sai cu phap .Vui long nhap lai . ";
        break;
    }
}