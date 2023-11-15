#include <iostream>
#include "includes\various.h"
#include "includes\VectorStruct.h"
#include "includes\Vector.h"
using namespace std;

int main()
{
    action1();
    //bool answer = accept3();
    //examineReference();

    // This is a test for Vector struct
    VectorStruct v = { 0, nullptr };
    vector_init(v, 5);
    cout << "v.sz = " << v.sz << endl;
    cout << "v.elem = " << v.elem << endl;
    show_all(v);
    cout << "destroy(v)" << endl;
    vector_destroy(v);
    cout << "v.sz = " << v.sz << endl;
    cout << "----------------------------------------" << endl;

    double sum = read_and_sum(3);
    cout << "sum = " << sum << endl;
    cout << "----------------------------------------" << endl;

    VectorStruct v1 = { 0, nullptr };
    vector_init(v1, 5);
    VectorStruct v2 = { 0, nullptr };
    vector_init(v2, 5);
    VectorStruct v3 = { 0, nullptr };
    vector_init(v3, 5);
    vector_action(v1, v2, &v3);
    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    cout << "----------------------------------------" << endl;

    Vector v4(3);
    cout << "input " << v4.size() << " elements: " << endl;
    for (int i = 0; i < v4.size(); ++i)
    {
        cin >> v4[i];
    }
    cout << "sum = " << v4.sum() << endl;
    cout << "----------------------------------------" << endl;
    try
    {
        cout << v4[7] << endl;
    }
    catch (out_of_range& e)
    {
        cerr << "out of range error " << e.what() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "error when calling " << e.what() << '\n';
    }
    catch (...)
    {
        cerr << "unknown error" << endl;
    }


    return 0;
}