#include <iostream>
#include "Device.h"
#include "Connection.h"
#include "Network.h"

using namespace std;

int main() {

    Network network;

    // Create devices
    network.addDevice(Device(1, "Computer"));
    network.addDevice(Device(2, "Router"));
    network.addDevice(Device(3, "Server"));
    network.addDevice(Device(4, "Router 2"));
    network.addDevice(Device(5, "Computer 2"));

    // Connect devices
    network.addConnection(1, 2);
    network.addConnection(2, 3);
    network.addConnection(1, 4);
    network.addConnection(4, 3);
    network.addConnection(3, 5);

    cout << "\n===== DIGITAL NETWORK FAILURE SIMULATOR =====\n";

    cout << "\n1. Normal Network:\n";
    network.showDevices();

    cout << "\n2. BFS Before Failure:\n";
    network.BFS(1);

    cout << "\n3. Simulating Device Failure:\n";
    network.failDevice(2);

    cout << "\n4. Network After Failure:\n";
    network.showDevices();

    cout << "\n5. BFS After Failure:\n";
    network.BFS(1);

    cout << "\n6. Restoring Device:\n";
    network.restoreDevice(2);

    cout << "\n7. Network After Recovery:\n";
    network.showDevices();

    cout << "\n8. BFS After Recovery:\n";
    network.BFS(1);

    cout << "\n===== SIMULATION FINISHED =====\n";

    return 0;
}
