#ifndef PINWATCHER_HPP
#define PINWATCHER_HPP

#include "pinnums.hpp"

#define N_PINS_DIGITAL 11
#define N_PINS_ANALOG 2
#define N_PINS 100
#define RESOLUTION_ANALOG 0x4
#define DELAY_DEBOUNCE 50
#define DELAY_DEBOUNCE_ANALOG 5

class PinWatcher {
private:
    static const int digitalPinNums[N_PINS_DIGITAL];
    static const int analogPinNums[N_PINS_ANALOG];
    int state[N_PINS];
    unsigned long lastDebounceTime[N_PINS];
    const int analogResolution = RESOLUTION_ANALOG;

public:
    PinWatcher();
    ~PinWatcher();

    void updateState();
};

#endif
