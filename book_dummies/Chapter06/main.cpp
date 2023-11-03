#include <iostream>

using namespace std;

void First();
void PrintNames(const string& name1, const string& name2);
void Second();
void Third(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    First();
    cout << "-------------------------" << endl;
    Second();
    cout << "-------------------------" << endl;
    Third(argc, argv);
    cout << "-------------------------" << endl;
    return 0;
}

void First()
{
    string name1 = "John";
    string name2 = "Jane";
    PrintNames(name1, name2);
}

void PrintNames(const string& name1, const string& name2)
{
    cout << "Name 1: " << name1 << endl;
    cout << "Name 2: " << name2 << endl;
}

void Second()
{
    string phrase = "my picnic table is green";
    cout << "starting: " << phrase << endl;
    phrase.insert(3, "big ");
    // redundant is: phrase = phrase.insert(3, "big ");
    cout << "after insert: " << phrase << endl;
    phrase.replace(3, 4, "small ");
    cout << "after replace: " << phrase << endl;
    phrase.erase(3, 6);
    cout << "after erase: " << phrase << endl;
}

void Third(int argc, char* argv[])
{
    cout << "argc: " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
}