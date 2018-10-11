#include <iostream>
using namespace std;

int main(){
    int operand_1, operand_2;
    char opt;

    cin>>operand_1>>opt>>operand_2;

    int result;
    bool error = false;

    switch(opt){
        case '+':
            result = operand_1 + operand_2;
            break;
        case '-':
            result = operand_1 - operand_2;
            break;
        case '*':
            result = operand_1 * operand_2;
            break;
        case '/':
            result = operand_1 / operand_2;
            break;
        case '%':
            result = operand_1 % operand_2;
            break;
        default:
            error = true;
    }
    
    if(error){
        cout<<"ERROR"<<endl;
    }else{
        cout<<result<<endl;
    }
    return 0;
}