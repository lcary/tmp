#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    cout << "fill vector..." << endl;
    for (int i = 0; i < 100; i++)
        v.push_back(i);
    cout << "show vector:" << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    cout << "show vector (c++11 extension style):" << endl;
    for (int i: v)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}
