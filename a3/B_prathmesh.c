#include <stdio.h>
#include <stdlib.h>
#define ll long long

void merge(ll arr[], ll brr[], ll l, ll m, ll r)
{
    ll n1 = m - l + 1;
    ll n2 = r - m;

    ll L[n1], R[n2], LL[n1], RR[n2];

    for (ll i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        LL[i] = brr[l + i];
    }
    for (ll i = 0; i < n2; i++)
    {
        R[i] = arr[m + i + 1];
        RR[i] = brr[m + i + 1];
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
            brr[k] = LL[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            brr[k] = RR[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        brr[k] = LL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        brr[k] = RR[j];
        j++;
        k++;
    }
}

void merge_sort(ll arr[], ll brr[], int l, int r)
{
    if (l < r)
    {
        ll m = l + (r - l) / 2;
        merge_sort(arr, brr, l, m);
        merge_sort(arr, brr, m + 1, r);
        merge(arr, brr, l, m, r);
    }
}

ll binary_search(ll arr[], ll l, ll r, ll target)
{
    ll mid = l + (r - l) / 2;
    if (l == mid || r == mid)
    {
        if (arr[mid] > target)
        {
            return mid - 1;
        }
        return mid;
    }
    if (arr[mid] > target)
    {
        return binary_search(arr, l, mid, target);
    }
    else if (arr[mid] < target)
    {
        return binary_search(arr, mid, r, target);
    }
    return mid;
}

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll a[n], g[m], b[m], gg[m];
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (ll i = 0; i < m; i++)
    {
        scanf("%lld %lld", &b[i], &g[i]);
    }
    merge_sort(b, g, 0, m);
    gg[0] = g[0];
    for (ll i = 1; i < n; i++)
    {
        gg[i] = gg[i - 1] + g[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll x = binary_search(b, 0, m, a[i]);
        printf("%lld ", gg[x]);
    }
}