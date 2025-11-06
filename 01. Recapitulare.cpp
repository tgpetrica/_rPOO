#include <iostream>
using namespace std;

void interschimbare(int&, int&);

int main()
{
    //int x;

    //// std::cout << "Hello World!\n";
    //cout << "Hello World!\n";
    //// << operator de insertie
    //// >> operator de extractie

    //int a, b;
    //cin >> a >> b;
    //interschimbare(a, b);
    //cout << a << " " << b;

    int* cod = new int;

    cout << "cod: ";
    cin >> *cod;
    cout << *cod << " " << cod << " " << &cod;
        // valoarea pe care o are pointerul cod
                    // adresa unde se afla cod
                                        // adresa la care se afla in stiva variabila cod
    
    delete cod;
    _CrtDumpMemoryLeaks();



}

// :: operator de rezolutie

void interschimbare(int& a, int& b)
{
    // tip& referinta
    int c = a;
    a = b;
    b = c;
}
