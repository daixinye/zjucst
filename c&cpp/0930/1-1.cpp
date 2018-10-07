#include <iostream>
using namespace std;

string mergeSpace(string s){
    bool flag = false;
    string result;

    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            flag = true;
        }
        if(s[i] == '.'){
            result+='.';
            flag = false;
        }

        if(flag){
            if(s[i] == ' ' && result[result.length()-1] == ' '){
                continue;
            }else{
                result += s[i];
            }
        }
    }
    return result;
}

bool isLower(char c){
    return int(c) >= 97 && int(c) <=122;
}

bool isUpper(char c){
    return int(c) >= 65 && int(c) <=90;
}

char lower(char c) {
    return isUpper(c) ? char(int(c)+32) : c;
}

char upper(char c) {
    return isLower(c) ? char(int(c)-32) : c;
}

string mergePuncSpace(string s){
    string result;

    for(int i = 0;i<s.length(); i++){
        if(s[i] == ',' || s[i] == '.'){
            if(result[result.length()-1] == ' '){
                result[result.length()-1] = s[i];
                continue;
            }
        }
        // if(s[i]== ' ' && (s[i-1] == ',' || s[i-1] == '.')){
        //     continue;
        // }

        result += s[i];
    }
    return result;
}

string fixLetter(string s){
   string result;

   for(int i = 0; i < s.length(); i++){
       if(i == 0){
          result += upper(s[i]);
       }else{
           if(s[i] == 'I' && s[i-1] == ' ' && s[i+1] == ' '){
               result += 'I';
           }else{
               result += lower(s[i]);
           }
       }
   } 
   return result;
}


int main(){
    // cout<<isLower('t')<<endl;
    // cout<<isUpper('T')<<endl;
    // cout<<lower('T')<<endl;
    // cout<<upper('t')<<endl;

    string input, output;
    // cin>>input;
    input = "  This is an  I Example Ia with one   ,   mistake .  ";
    output = input;

    // 第一步 合并所有空格
    output = mergeSpace(output);
    // cout<<output<<endl;
    // 第二步 去掉逗号句号前的空格
    output = mergePuncSpace(output);
    // cout<<output<<endl;
    // 第三步 修正大小写
    output = fixLetter(output);
    // 第四步
    cout<<output<<endl;



    return 0;
}