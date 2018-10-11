#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int years, time;
  cin>>years>>time;
  
  double pay = years >= 5 ? 50 : 30;
  
  double total = time >= 40 ? pay * 40 + pay * 1.5 * (time - 40) : pay * time;
  
  printf("%.2f\n", total);
  
  return 0;
}