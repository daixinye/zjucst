#include <iostream>
using namespace std;

const string PI = "314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";

int main(){
    int n;
    cin>>n;
    int rows = n;

    int pos = 0;

    while(n){
        int space_len = n -1, pi_len = (rows - space_len)*2 - 1;
        // cout<<space_len<<' '<<pi_len<<endl;
        for(int i = 0; i < space_len; i++){
            cout<<' ';
        }
        for(int j = pos; j < pos + pi_len; j++){
            cout<< PI[j];
        }
        cout<<endl;
        pos+= pi_len;
        n--;
    }

    return 0;
}