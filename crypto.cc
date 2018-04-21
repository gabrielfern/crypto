#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char **argv) {
    using namespace std;

    if (argc < 3) {
        cerr << "Missing arguments\ncrypto key input [output]\n";
        return 1;
    }

    fstream key(argv[1], ios_base::in | ios_base::binary);
    fstream input(argv[2], ios_base::in | ios_base::binary);
    fstream output;
    if (argc < 4 || string(argv[2]) == argv[3])
        output = fstream(argv[2], ios_base::in | ios_base::out
                                | ios_base::binary);
    else
        output = fstream(argv[3], ios_base::out | ios_base::binary);

    if (!key.is_open() || !input.is_open() || !output.is_open()) {
        cerr << "No such file\n";
        return 1;
    }

    char k = 0, b;
    while (input.get(b)) {
        if (!key.get(k)) {
            key.clear();
            key.seekg(0);
            key.get(k);
        }
        b ^= k;
        output.put(b);
    }
}
