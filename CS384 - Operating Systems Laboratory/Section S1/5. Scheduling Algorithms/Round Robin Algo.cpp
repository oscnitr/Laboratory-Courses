#include <bits/stdc++.h>
using namespace std;
int main() {
  int arrival[4] = {0, 0, 0, 0};
  int burst[4] = {53, 17, 68, 24};
  int burst1[4] = {53, 17, 68, 24};
  
  int ts = 20;

  int slicetime[4];
  for (int i = 0; i < 4; i++) slicetime[i] = ts;
  int executedtime[4];
  for (int i = 0; i < 4; i++) executedtime[i] = 0;

  int n = 4;
  cout << "0 ";
  int tt = 0;
  int waiting[100];
  int count = 0;
  for (int i = 0; i < n; i++) tt += burst[i];
  while (count < tt) {
    for (int i = 0; i < n; i++) {
      if (burst[i] == INT_MAX) continue;
      if (executedtime[i] == 0)
        slicetime[i] = ts;
      else
        slicetime[i] = ts + (count - arrival[i] - executedtime[i]);
      if (slicetime[i] <= 0) continue;
      if (arrival[i] <= count && burst[i] > slicetime[i]) {
        count += slicetime[i];
        cout << "P" << i << " " << count << " ";
        burst[i] -= slicetime[i];
        executedtime[i] += slicetime[i];
      } else if (arrival[i] <= count && burst[i] <= slicetime[i]) {
        count += burst[i];
        cout << "P" << i << " " << count << " ";
        waiting[i] = count - arrival[i] - burst1[i];
        burst[i] = INT_MAX;
      }
    }
  }
  int tw = 0;
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << i << " " << waiting[i] << endl;
    tw += waiting[i];
  }
  cout << (double)tw / (double)n;
  cout << endl;
}
