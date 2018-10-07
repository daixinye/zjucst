#include <iostream>
using namespace std;

bool isUpper(char c){
    return c <= 90 && c>= 65;
}

int main(){
    string s,r;
    // cin>>s;
    s = "This is an  Example Ia with one    , mistake .";

    int len = s.length();
    for(int i = 0; i < len; i++){
        char c = s[i]; 
        if(i == 0 ){
            // 检查首字符是否大写
            if(s[i] > 90){
                c = char(s[i]-32);
            }
        }else if(i == len-1){
            // do nothing
            if(s[i] == '.'){
                if(r[r.length()-1] == ' '){
                    r[r.length()-1] = s[i];
                    continue;
                }
            }
        }else{
            // 检查为空格时，前一个是否是空格
            if(s[i] == ' '){
                if(s[i-1] == ' '){
                    continue;
                }else{
                    c = ' ';
                }
            }
            // 检查中间是否有大写的情况
            if(s[i] <= 90 && s[i]>= 65){
                // 检查是I的情况
                if (s[i] == 'I'){
                    if(s[i-1] == ' ' && s[i+1] == ' '){
                        c = 'I';
                    }else {
                        c = s[i] + 32; 
                    }
                }else {
                    c = s[i] + 32;
                }
            }
            

            // 检查, .
            if(s[i] == '.' || s[i] == ','){
                if(r[r.length()-1] == ' '){
                    r[r.length()-1] = s[i];
                    continue;
                }
            }
        }
        r += c;
    }

    cout<<r<<endl;

    return 0;
}