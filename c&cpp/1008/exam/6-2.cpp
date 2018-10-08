#include<iostream>
using namespace std;

/* 请在这里填写答案 */

class Student {
  public:
    void display(){
      if(score > 0){
        cout<<no<<" "<<"Pass"<<endl;
      }else{
        cout<<no<<" "<<"Fail"<<endl;
      }
    }
    Student(int n, int s){
      no = n;
      score = s;
      count++;
    }
    Student(Student &s){
      no = s.no + 1;
      score = s.score;
      count++;
    }
    static int count;
  private:
    int no;
    int score;
};

int Student::count = 0;

int main(){
    const int size=100;
    int i, N, no, score;
    Student *st[size];
    cin>>N;
    for(i=0; i<N; i++){
        cin>>no;
        if(no>0){
            cin>>score;
            st[i]=new Student(no, score);
        }
        else
            st[i]=new Student(*st[i-1]);
    }
    cout<<Student::count<<" Students"<<endl;
    for(i=0;i<N;i++) st[i]->display();
    for(i=0;i<N;i++) delete st[i];
    return 0;
}