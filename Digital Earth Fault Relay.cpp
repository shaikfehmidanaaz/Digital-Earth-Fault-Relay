#include <iostream>
using namespace std;

class DigitalEarthFaultRelay {
private:
    double earthFaultCurrent;
    double pickupCurrent;
    bool relayStatus;
    bool breakerStatus;

public:
    DigitalEarthFaultRelay(double limit) {
        pickupCurrent = limit;
        relayStatus = false;
        breakerStatus = true;
    }

    void measureCurrent(double current) {
        earthFaultCurrent = current;
    }

    void detectFault() {
        cout << "\nMeasured Earth Fault Current: "
             << earthFaultCurrent << " A" << endl;

        cout << "Relay Pickup Current: "
             << pickupCurrent << " A" << endl;

        if (earthFaultCurrent > pickupCurrent) {

            relayStatus = true;
            breakerStatus = false;

            cout << "\nEARTH FAULT DETECTED!" << endl;
            cout << "Relay: OPERATED" << endl;
            cout << "Circuit Breaker: TRIPPED" << endl;
            cout << "Load: DISCONNECTED" << endl;
        }
        else {

            relayStatus = false;
            breakerStatus = true;

            cout << "\nSystem Status: NORMAL" << endl;
            cout << "Relay: NOT OPERATED" << endl;
            cout << "Circuit Breaker: CLOSED" << endl;
            cout << "Load: CONNECTED" << endl;
        }
    }

    void displayStatus() {

        cout << "\n----- FINAL STATUS -----" << endl;

        if (relayStatus)
            cout << "Relay Status: TRIPPED" << endl;
        else
            cout << "Relay Status: NORMAL" << endl;

        if (breakerStatus)
            cout << "Breaker Status: CLOSED" << endl;
        else
            cout << "Breaker Status: OPEN" << endl;
    }
};

int main() {

    double pickupLimit;
    double measuredCurrent;

    cout << "======================================" << endl;
    cout << "      DIGITAL EARTH FAULT RELAY" << endl;
    cout << "======================================" << endl;

    cout << "\nEnter earth fault pickup current (A): ";
    cin >> pickupLimit;

    cout << "Enter measured earth fault current (A): ";
    cin >> measuredCurrent;

    DigitalEarthFaultRelay relay(pickupLimit);

    relay.measureCurrent(measuredCurrent);
    relay.detectFault();
    relay.displayStatus();

    return 0;
}
