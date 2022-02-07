#include <iostream>
#include <string>

using namespace std;

// STRONG RELATIONSHIP
// Human has a Heart

class Heart
{
public:
    string type;
    Heart()
    {
        type = "Normal";
    }
    Heart(string t)
    {
        type = t;
    }
    ~Heart()
    {
        cout << "Heart destroyed" << endl;
    }
};