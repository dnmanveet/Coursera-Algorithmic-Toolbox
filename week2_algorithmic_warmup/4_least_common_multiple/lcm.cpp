#include <iostream>

int gcd(int a,int b){
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}
   

long long lcm_naive(long a, long b) {  
  return a * b/gcd(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
