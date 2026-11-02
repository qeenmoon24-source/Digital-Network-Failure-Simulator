#ifndef DEVICE_H
#define DEVICE_H

#include <string>
using namespace std;

class Device {

private:
    int id;
    string name;
    bool active;

public:

    // Constructor
    Device(int i, string n) {
        id = i;
        name = n;
        active = true;
    }

    // Get device ID
    int getId() {
        return id;
    }

    // Get device name
    string getName() {
        return name;
    }

    // Check device status
    bool isActive() {
        return active;
    }

    // Simulate device failure
    void fail() {
        active = false;
    }

    // Restore device
    void restore() {
        active = true;
    }
};

#endif
