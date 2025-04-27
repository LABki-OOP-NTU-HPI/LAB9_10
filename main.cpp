#include "Include/Vector.h"

int main()
{
    try
    {
        Vector v;
        v++;
        ++v;
        v++;

        v.print();

        v[0] = 10;
        v[1] = 20;
        v[2] = 30;
        v.print();
        v[3] = 10;
        v.print();

    }
    catch (const exception& e)
    {
        cout << "Error " << e.what() << endl;
    }
    cin.get();
    return 0;
}
