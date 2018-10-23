#import <Foundation/Foundation.h>

int main(int argc, char* argv[]){
    int num = 99;
    BOOL equal = num < 100 && num > 0;
    NSLog(@"%i", equal);
    return 0;
}