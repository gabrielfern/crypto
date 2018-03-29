#include "crypto.hh"


int main(int argc, char** argv)
{
    using namespace std;

    fstream key("k");
    fstream input(argv[1]);
    fstream output(argv[2]);

    char b, k;
    while (input >> b)
    {
        key >> k;
        b ^= k;
        output << b;
    }
}
