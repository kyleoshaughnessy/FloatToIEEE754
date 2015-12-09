#include <iostream>

using namespace std;

typedef union {
    size_t st;
    float f;
} ieee754Union;

int main(int argc, char* argv[]) {

	if (argc < 2) {
		cerr << "Please supply a float as the first argument." << endl;
        return EXIT_FAILURE;
	}

    ieee754Union u;

    if(sscanf(argv[1], "%f", &u.f) == 0) {
        cerr << "Please supply a float as the first argument." << endl;
        return EXIT_FAILURE;
    }

    string bitString = bitset<32>(u.st).to_string().insert(9, ":").insert(1, ":");

    cout << argv[1] << " (base 10 argument)" << endl;
    cout << u.f << " (base 10 internal float)" << endl;
    cout << hex << (((1 << 31) - 1) & u.st) << " (ieee754 hexadecimal)" << endl;
    cout << bitString << " (ieee754 sign:exponent:mantisa)" << endl;

    return EXIT_SUCCESS;
}