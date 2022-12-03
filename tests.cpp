#include <array>
using std::array;
#include <iostream>
using std::cout;

int main()
{
    array<int, 4> a{10, 20, 30, 40};

    for (int x : a)
        cout << x << "\t";

    cout << std::endl;

    a = {0};

    for (int x : a)
        cout << x << "\t";

    return 0;
}