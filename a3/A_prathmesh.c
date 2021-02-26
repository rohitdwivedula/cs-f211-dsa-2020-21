#include <stdio.h>
#include <stdlib.h>
#define ll long long

void merge(ll arr[], ll l, ll m, ll r)
{
    ll n1 = m - l + 1;
    ll n2 = r - m;
    ll L[n1], R[n2];
    for (ll i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (ll i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    ll i, j, k;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(ll arr[], int l, int r)
{
    if (l < r)
    {
        ll m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    ll n, m, kk;
    scanf("%lld %lld %lld", &n, &m, &kk);
    ll a[n], s[m];
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (ll i = 0; i < m; i++)
    {
        scanf("%lld", &s[i]);
    }
    merge_sort(a, 0, n - 1);
    merge_sort(s, 0, m - 1);

    ll i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (s[j] <= a[i] + kk && s[j] >= a[i] - kk)
        {
            count++;
            i++;
            j++;
        }
        else if (s[j] < a[i] - kk)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    printf("%lld", count);
}