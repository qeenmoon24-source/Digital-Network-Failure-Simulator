#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {

private:
    int from;
    int to;

public:

    Connection(int f, int t) {
        from = f;
        to = t;
    }

    int getFrom() {
        return from;
    }

    int getTo() {
        return to;
    }
};

#endif
