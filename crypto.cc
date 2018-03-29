#include "crypto.hh"


int main(int argc, char** argv)
{
    using namespace std;

    if (argc < 3)
    {
        cerr << "Missing arguments\n";
        return 1;
    }

    fstream key(argv[1]);
    fstream input(argv[2]);
    fstream output;
    if (argc < 4)
        output = fstream(argv[2]);
    else
        output = fstream(argv[3], output.out);

    if (!key.is_open() || !input.is_open() || !output.is_open())
    {
        cerr << "No such file\n";
        return 1;
    }

    char b, k = 0;
    while (input >> b)
    {
        if (!(key >> k))
        {
            key.clear();
            key.seekg(0);
            key >> k;
        }
        b ^= k;
        output << b;
    }
}
