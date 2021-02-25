#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define new_max(x, y) ((x >= y) ? x : y)

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
        R[i] = arr[m + i + 1];
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
int is_feasible(ll arr[], ll distance, ll n, ll m)
{
    ll pos = arr[0];
    ll count = 1;
    for (ll i = 1; i < m; i++)
    {
        if (arr[i] - pos >= distance)
        {
            pos = arr[i];
            count++;
        }
        if (count == n)
        {
            return 1;
        }
    }
    return 0;
}

ll solve(ll arr[], ll n, ll m)
{
    ll result = -1;
    ll left = 1, right = arr[m - 1];
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        if (is_feasible(arr, mid, n, m))
        {
            result = new_max(mid, result);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll x[m];
    for (ll i = 0; i < m; i++)
    {
        scanf("%lld", &x[i]);
    }
    merge_sort(x, 0, m - 1);
    ll result = solve(x, n, m);
    printf("%lld", result);
    return 0;
}