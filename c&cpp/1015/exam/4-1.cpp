#include <iostream>
#include <string>
using namespace std ;

class Testing
{
private:
	string words; 
	int number ;
public:
	Testing(const string & s = "Testing")
	{
		words = s ;
		number = words.length();
		if (words.compare("Testing")==0)
			cout << 1;
		else if (words.compare("Heap1")==0)
			cout << 2;
		else
			cout << 3;
	}
	~Testing()
	{
		cout << 0;
	}
	void show() const
	{
		cout << number;
	}
};
int main()
{
	Testing *pc1 , *pc2;
	pc1 = new Testing ;          //1
	pc2 = new Testing("Heap1");  //2
	pc1->show();   //3
	delete pc1 ;   //4
	delete pc2 ;   //5
	return 0;
}