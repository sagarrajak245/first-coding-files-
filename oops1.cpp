#include <iostream>
using namespace std;

class human
{

private:
    int hp;
    char petname;
    int stamina;

public:
    void sethp(int a) { hp = a; }
    int gethp() { return hp; }
};

int main()
{

    human sagar;
    sagar.sethp(200);

    cout << "sagar's hp level is " << sagar.gethp();

    return 0;
}