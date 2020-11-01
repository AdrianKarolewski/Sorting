#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void bubble_sort(int* wsk_tab, const int & how_m)
{
    int buffer;
    for (int i = 0; i < how_m; i++)
    {
        for (int j = how_m - 1; j >= 1 + i; j--)
        {
            if (wsk_tab[j] < wsk_tab[j - 1])
            {
                buffer = wsk_tab[j];
                wsk_tab[j] = wsk_tab[j - 1];
                wsk_tab[j - 1] = buffer;
            }
        }
    }
}
void quick_sort(int* wsk_tab, int p, int q)
{
    int help_p = p;
    int help_q = q;
    int pivot_i = wsk_tab[(p + q) / 2];
    int buffer;
    do
    {
        while (wsk_tab[help_p] < pivot_i) help_p++;
        while (wsk_tab[help_q] > pivot_i) help_q--;

        if (help_p <= help_q)
        {
            buffer = wsk_tab[help_p];
            wsk_tab[help_p] = wsk_tab[help_q];
            wsk_tab[help_q] = buffer;
            help_p++;
            help_q--;


        }
    } while (help_p <= help_q);
    if (help_q > p) quick_sort(wsk_tab, p, help_q);
    if (help_p < q) quick_sort(wsk_tab, help_p, q);

}
void heap_sort(int* wsk_tab, int n, const int & how_m)
{
    for (int i = 0; i < how_m - 1; i++)
    {
        n = how_m - 1 - i;
        int parent, parent_2, left, right;
        int biggest;
        do
        {
            right = n;
            left = n - 1;

            parent = (right - 1) / 2;
            parent_2 = (left - 1) / 2;

            biggest = wsk_tab[parent];
            n--;
            if (parent_2 == parent)
            {
                n--;
                if (wsk_tab[left] > biggest)
                {
                    wsk_tab[parent] = wsk_tab[left];
                    wsk_tab[left] = biggest;
                    biggest = wsk_tab[parent];
                }

            }
            if (wsk_tab[right] > biggest)
            {
                wsk_tab[parent] = wsk_tab[right];
                wsk_tab[right] = biggest;
                biggest = wsk_tab[parent];
            }

        } while (0 <= ((n - 1) / 2));

        biggest = wsk_tab[how_m - 1 - i];
        wsk_tab[how_m - 1 - i] = wsk_tab[0];
        wsk_tab[0] = biggest;
    }

}
void insertion_sort(int* wsk_tab, int n)
{
    int elem;
    for (int i = 0; i < n; i++)
    {
        elem = wsk_tab[i + 1];
        for (int j = i; j >= 0; j--)
        {
            if (elem <= wsk_tab[j])
            {
                wsk_tab[j + 1] = wsk_tab[j];
            }
            if (elem > wsk_tab[j])
            {
                wsk_tab[j + 1] = elem;
                break;
            }
            else if (j == 0)
            {
                wsk_tab[1] = wsk_tab[0];
                wsk_tab[0] = elem;
            }
        }

    }
}
void counting_sort(int* wsk_tab, int n, int* help_a, const int & how_big)
{
    for (int i = 0; i <= n; i++)
    {
        help_a[i] = wsk_tab[i];
    }
    int* tab_zer = new int[how_big];
    for (int i = 0; i < how_big; i++)
    {
        tab_zer[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        tab_zer[wsk_tab[i]]++;
    }
    for (int i = 1; i < how_big; i++)
    {
        tab_zer[i] += tab_zer[i - 1];
    }
    for (int i = 0; i <= n; i++)
    {
        tab_zer[help_a[i]] --;
        wsk_tab[tab_zer[help_a[i]]] = help_a[i];

    }
    delete[] tab_zer;
}
void select_sort(int* wsk_tab, int n)
{
    int minimal, index;
    for (int i = 0; i <= n; i++)
    {
        minimal = wsk_tab[i];
        index = i;
        for (int j = i; j <= n; j++)
        {
            if (wsk_tab[j] < minimal)
            {
                minimal = wsk_tab[j];
                index = j;
            }
        }
        wsk_tab[index] = wsk_tab[i];
        wsk_tab[i] = minimal;
    }

}
void shell_sort(int* wsk_tab, int n)
{
    int d;
    int elem;
    d = n / 2;
    while (d > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (i + d > n) break;
            elem = wsk_tab[i + d];
            for (int j = i; j >= 0; j -= d)
            {
                if (elem <= wsk_tab[j])
                {
                    wsk_tab[j + d] = wsk_tab[j];
                }
                if (elem > wsk_tab[j])
                {
                    wsk_tab[j + d] = elem;
                    break;
                }
                else if (j <= d)
                {
                    wsk_tab[j + d] = wsk_tab[j];
                    wsk_tab[j] = elem;
                }
            }
        }
        d = d / 2;
    }
    if (d == 1)insertion_sort(wsk_tab, n);
}
void merge_s(int* wsk, int p, int mid, int n, int* help_a)
{
    for (int i = p; i <= n; i++)
    {
        help_a[i] = wsk[i];
    }
    int help_mid = mid + 1;
    int current = p;
    while ((p <= mid) && (help_mid <= n))
    {
        if (help_a[p] <= help_a[help_mid])
        {
            wsk[current] = help_a[p];
            p++;
        }
        else
        {
            wsk[current] = help_a[help_mid];
            help_mid++;
        }
        current++;
    }
    while (p <= mid)
    {
        wsk[current] = help_a[p];
        p++;
        current++;
    }
    while (help_mid <= n)
    {
        wsk[current] = help_a[help_mid];
        help_mid++;
        current++;
    }
}
void merge_sort(int* wsk_tab, int p, int n, int* help_a)
{
    int mid;
    mid = (p + n) / 2;
    if (p != n)
    {
        merge_sort(wsk_tab, p, mid, help_a);
        merge_sort(wsk_tab, mid + 1, n, help_a);
        merge_s(wsk_tab, p, mid, n, help_a);
    }
}
int main()
{
    clock_t start;

    int how_m, how_big;
    int prefer;

    cout << "Ile liczb posortowac?: ";  cin >> how_m;
    cout << "Wybierz zakres: ";        cin >> how_big;

    int* digits = new int[how_m];
    int* help_arr = new int[how_m];

    srand(time(NULL));

    for (int i = 0; i < how_m; i++)
    {
        *digits = rand() % how_big;
        cout << *digits << " ";
        digits++;
    }
    digits -= how_m;
    cout << "Jak sortowac ? " << endl;
    cout << "1. bubble_sort" << endl;
    cout << "2. quick_sort" << endl;
    cout << "3. heap_sort" << endl;
    cout << "4. insertion_sort" << endl;
    cout << "5. counting_sort" << endl;
    cout << "6. select_sort" << endl;
    cout << "7. shell_sort" << endl;
    cout << "8. merge_sort" << endl;
    cout << "Wybierz nr: ";       cin >> prefer;

    switch (prefer)
    {
    case 1:
        start = clock();
        bubble_sort(digits,how_m);
        cout << "Czas bubble_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s" << endl;
        break;

    case 2:
        start = clock();
        quick_sort(digits, 0, how_m - 1);
        cout << "Czas quick_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC  << endl;
        break;

    case 3:
        start = clock();
        heap_sort(digits, how_m - 1,how_m);
        cout << "Czas heap_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
        break;

    case 4:
        start = clock();
        insertion_sort(digits, how_m - 1);
        cout << "Czas insertion_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
        break;

    case 5:
        start = clock();
        counting_sort(digits, how_m - 1, help_arr, how_big);
        cout << "Czas counting_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
        break;

    case 6:
        start = clock();
        select_sort(digits, how_m - 1);
        cout << "Czas select_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
        break;

    case 7:
        start = clock();
        shell_sort(digits, how_m - 1);
        cout << "Czas shell_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
        break;

    case 8:
        start = clock();
        merge_sort(digits, 0, how_m - 1, help_arr);
        cout << "Czas merge_sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
        break;
    }

    for (int i = 0; i < how_m; i++)
    {
        cout << *digits << " ";
        digits++;
    }
    digits -= how_m;
    delete[] digits;
    delete[] help_arr;
    return 0;
}
