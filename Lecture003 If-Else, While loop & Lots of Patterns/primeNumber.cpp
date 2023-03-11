// Check if a number is Prime or not

# include <iostream>
using namespace std;

int main() {

  int n, i=2;
  cout <<"Enter to check if a number is Prime = ";
  cin >>n;

  while (i<n) {
    if (n%i==0) {
      cout <<"Number is not Prime" <<endl;
      return 0;
    }
    else {
      i = i+1;
    }
  }

  cout <<"Number is Prime" <<endl;
}
