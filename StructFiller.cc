// A very short program intended for students learning
// about multithreading and locks.
// StructFiller spins up two threads to increment members
// NUM1 and NUM2 to the K_NUM_FULL threshold.

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <ctime>

using namespace std;

static const int K_NUM_FULL = 200000;

struct Data {
    int num1 = 0;
    int num2 = 0;
};


void fillStruct (struct Data &d) {
    while (true) {
        if (d.num1 < K_NUM_FULL) {
            d.num1++;
        } else if (d.num2 < K_NUM_FULL) {
            d.num2++;
        } else {
            break;
        }
    }
}

/**
 * MAIN() spins up 2 threads. These threads must work together
 * to fill the numbers in DATA to K_NUM_FULL.
*/
int main() {

    // Timer setup.
    clock_t start = clock();

    thread arr[2]; // Unused!
    Data usr_data;


    // Fill struct here!
    fillStruct(usr_data);
    
    clock_t end = clock();

    cout << "All done! Here is the state of usr_data now..." << endl;
    cout << "{ "<< usr_data.num1 << ", " << usr_data.num2 << " }" << endl;
    
    cout << "This operation took " << end - start << " cycles." << endl;

    return 0;
}
