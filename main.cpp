#include "Include/Vector.h"

int main()
{
    try
    {
        Vector<int> v;
        Vector<string> v2;
        Vector<bool> v3;
        ++v;
        v++;
        v2++;
        ++v2;
        // v3++;
        // ++v3;

        v2[0] = "Hello";
        v2[1] = "World";
        //v2[2] = "Error";
        v2.print();
        v[0] = 10;
        v[1] = 20;
        v.print();
    }
    catch (const exception& e)
    {
        cout << "Error " << e.what() << endl;
    }
    cin.get();
    return 0;
}
