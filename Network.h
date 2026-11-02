#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <queue>
#include "Device.h"
#include "Connection.h"

using namespace std;

class Network {

private:
    vector<Device> devices;
    vector<Connection> connections;

public:

    // Add new device
    void addDevice(Device d) {
        devices.push_back(d);
    }

    // Add connection
    void addConnection(int from, int to) {
        connections.push_back(Connection(from, to));
    }

    // Find device by ID
    int findDevice(int id) {
        for (int i = 0; i < devices.size(); i++) {
            if (devices[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }

    // Display devices
    void showDevices() {
        for (int i = 0; i < devices.size(); i++) {
            cout << devices[i].getId() << " - "
                 << devices[i].getName() << " : ";

            if (devices[i].isActive())
                cout << "Active";
            else
                cout << "Failed";

            cout << endl;
        }
    }

    // Simulate failure
    void failDevice(int id) {
        int index = findDevice(id);

        if (index != -1) {
            devices[index].fail();
            cout << "Device " << id << " failed!" << endl;
        }
    }

    // Restore device
    void restoreDevice(int id) {
        int index = findDevice(id);

        if (index != -1) {
            devices[index].restore();
            cout << "Device " << id << " restored!" << endl;
        }
    }

    // BFS algorithm
    void BFS(int startID) {

        int start = findDevice(startID);

        if (start == -1 || !devices[start].isActive()) {
            cout << "Invalid starting device!" << endl;
            return;
        }

        vector<bool> visited(devices.size(), false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Connected devices: ";

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            cout << devices[current].getId() << " ";

            for (int i = 0; i < connections.size(); i++) {

                int nextID = -1;

                if (connections[i].getFrom() ==
                    devices[current].getId()) {

                    nextID = connections[i].getTo();
                }
                else if (connections[i].getTo() ==
                         devices[current].getId()) {

                    nextID = connections[i].getFrom();
                }

                int next = findDevice(nextID);

                if (next != -1 &&
                    devices[next].isActive() &&
                    !visited[next]) {

                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        cout << endl;

        cout << "Disconnected devices: ";

        for (int i = 0; i < devices.size(); i++) {
            if (devices[i].isActive() && !visited[i]) {
                cout << devices[i].getId() << " ";
            }
        }

        cout << endl;
    }
};

#endif
