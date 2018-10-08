/* 请在这里填写答案 */
#include <iostream>
#include <cstdio>
using namespace std;

enum CPU__Rank {P1=1,P2,P3,P4,P5,P6,P7};

class CPU{
    private:
        CPU__Rank rank;
        int freq;
        double vol;
    public:
        CPU(CPU__Rank r, int f, double v){
            cout<<"create a CPU!"<<endl;
            rank = r;
            freq = f;
            vol = v;
        }
        CPU(CPU &cpu){
            cout<<"copy create a CPU!"<<endl;
            rank = cpu.rank;
            freq = cpu.freq;
            vol = cpu.vol;
        }
        CPU(){
            cout<<"create a CPU!"<<endl;
            rank = P1;
            freq = 2;
            vol = 100;
        }
        void showinfo(){
            cout<<"rank:"<<rank<<endl;
            cout<<"frequency:"<<freq<<endl;
            printf("voltage:%.0f\n", vol);
        }
        ~CPU(){
            cout<<"destruct a CPU!"<<endl;
        }
};

int main()
{
	CPU a(P6,3,300); 
	
	cout<<"cpu a's parameter"<<endl;
	a.showinfo(); //显示性能参数

	CPU b; 
	cout<<"cpu b's parameter"<<endl;
	b.showinfo(); //显示性能参数

	CPU c(a); 
	cout<<"cpu c's parameter"<<endl;
	c.showinfo(); //显示性能参数
}