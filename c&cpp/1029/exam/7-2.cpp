#include <iostream>
using namespace std;

int main()
{
    string num;
    cin >> num;

    string year = num.substr(0, 4);
    string department = num.substr(4, 2);
    string cls = num.substr(6, 2);

    cout << "year:" << year << endl;
    cout << "department:" << department << endl;
    cout << "class:" << cls << endl;
    return 0;
}