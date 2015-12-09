#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

typedef union {
    size_t st;
    float f;
} IEEE754Union;

int main(int argc, char *argv[]) {

    IEEE754Union u;

    if (argc < 2 || 0 == sscanf(argv[1], "%f", &u.f)) {
        cerr << "Please supply a float as the first argument." << endl;
        return EXIT_FAILURE;
    }

    int width = 40;
    width = (strlen(argv[1]) > width) ? (int) strlen(argv[1]) + 1 : width;

    string bitString = bitset<32>(u.st).to_string();
    bitString.insert(9, ":");
    bitString.insert(1, ":");

    cout << setfill('.');
    cout << left << setw(width) << argv[1]                    << "(base 10 argument)" << endl;
    cout << left << setw(width) << u.f                        << "(base 10 internal float)" << endl;
    cout << left << setw(width) << hex << (u.st & 0xFFFFFFFF) << "(ieee754 hexadecimal)" << endl;
    cout << left << setw(width) << bitString                  << "(ieee754 sign:exponent:mantissa)" << endl;

    return EXIT_SUCCESS;
}