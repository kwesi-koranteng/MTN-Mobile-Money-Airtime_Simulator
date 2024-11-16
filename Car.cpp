// Car.h (header file)

#ifndef CAR_H //Header guards (#ifndef, #define, #endif): Prevents the file from being included multiple times by mistake.
#define CAR_H

#include <string>
using namespace std;

class Car {
public:
    string color;
    float speed;

    void drive();
    void stop();
};

#endif

