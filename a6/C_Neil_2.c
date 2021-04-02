#include <stdio.h>

int main() {
  int no_of_machines;//3
  long long no_of_watermellon, ans;//7,ans
  scanf("%d%lld", &no_of_machines, &no_of_watermellon);
  long long machines_time[no_of_machines];
  for (int i = 0; i < no_of_machines; i++) {
    scanf("%lld", &machines_time[i]);//arr[n] = 3 2 5
  }
  long long low = 1;
  long long high = 1e9;
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long done = 0;
    for (int i = 0; i < no_of_machines; i++) {
      done += mid / machines_time[i];//done = ((1e18+1)/2)/3
      if (done >= no_of_watermellon)
        break;
    }
    if (done >= no_of_watermellon) {
      high = mid - 1;
      ans = mid;
    } else
      low = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}