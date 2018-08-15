#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


int main(int argc, char **argv) {
    using namespace std;

    if (argc < 2) {
        cerr << "Missing arguments\ncrypto [key] input\n";
        return 1;
    }

    fstream input;
    fstream output;
    stringstream sstream;
    if (argc < 3) {
        input = fstream(argv[1], ios_base::in | ios_base::binary);
        output = fstream(argv[1], ios_base::in | ios_base::out | ios_base::binary);

        if (!input.is_open() || !output.is_open()) {
            cerr << "No such file\n";
            return 1;
        }

        sstream << cin.rdbuf();
    } else {
        fstream key(argv[1], ios_base::in | ios_base::binary);
        input = fstream(argv[2], ios_base::in | ios_base::binary);
        output = fstream(argv[2], ios_base::in | ios_base::out | ios_base::binary);

        if (!key.is_open() || !input.is_open() || !output.is_open()) {
            cerr << "No such file\n";
            return 1;
        }

        sstream << key.rdbuf();
    }

    char k = 0, b;
    int i = 0;
    while (input.get(b)) {
        if (sstream.str().length() > 0) {
            if (i >= sstream.str().length()) i = 0;
            k = sstream.str()[i];
            i++;
        }
        b ^= k;
        output.put(b);
    }
}
