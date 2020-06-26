#include <iostream>
using namespace std;
int main()
{
    int TC;
    cin >> TC;
    while (TC--)
    {
        long a, b, m;
        cin >> a >> b >> m;

        cout << m * (2 * a - b) / (a + b) << '\n';
    }
    return 0;
}
