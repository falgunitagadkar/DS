#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(2);
    s.push(4);
    int a=s.top();

    
    cout << a << endl;
    return 0;
}