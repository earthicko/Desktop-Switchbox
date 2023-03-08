#include "PinWatcher.hpp"
#include "debugPrintf.hpp"

const int PinWatcher::digitalPinNums[N_PINS_DIGITAL] = {
    PINNUM_TOGGLE_1,
    PINNUM_TOGGLE_2,
    PINNUM_TOGGLE_3,
    PINNUM_TOGGLE_4,
    PINNUM_TOGGLE_5,
    PINNUM_TOGGLE_6,
    PINNUM_KEY_1,
    PINNUM_KEY_2,
    PINNUM_PUSH_1,
    PINNUM_PUSH_2,
    PINNUM_EMERGENCY
};
const int PinWatcher::analogPinNums[N_PINS_ANALOG] = {
    PINNUM_POT_1,
    PINNUM_POT_2
};

PinWatcher::PinWatcher()
{
    DEBUG_PRINT("PinWatcher Constructor\n");
    for (int i = 0; i < N_PINS_DIGITAL; i++) {
        int pinNum = digitalPinNums[i];
        pinMode(pinNum, INPUT);
        state[pinNum] = digitalRead(pinNum);
        DEBUG_PRINTF("pinMode(%d, INPUT);\n", digitalPinNums[i]);
    }
    for (int i = 0; i < N_PINS_ANALOG; i++) {
        int pinNum = analogPinNums[i];
        pinMode(pinNum, INPUT);
        state[pinNum] = analogRead(pinNum);
        DEBUG_PRINTF("pinMode(%d, INPUT);\n", analogPinNums[i]);
    }
    unsigned long now = millis();
    for (int i = 0; i < N_PINS_DIGITAL; i++)
        lastDebounceTime[digitalPinNums[i]] = now;
    for (int i = 0; i < N_PINS_ANALOG; i++)
        lastDebounceTime[analogPinNums[i]] = now;
}

PinWatcher::~PinWatcher()
{
}

void PinWatcher::updateState()
{
    static int reading[N_PINS];
    static int lastReading[N_PINS];
    unsigned long now = millis();
    for (int i = 0; i < N_PINS_DIGITAL; i++) {
        int pinNum = digitalPinNums[i];
        reading[pinNum] = digitalRead(pinNum);
        if (reading[pinNum] != lastReading[pinNum])
            lastDebounceTime[pinNum] = now;
        if (now - lastDebounceTime[pinNum] > DELAY_DEBOUNCE) {
            if (reading[pinNum] != state[pinNum]) {
                state[pinNum] = reading[pinNum];
                DEBUG_PRINTF("New state at pin %d: %d\n", pinNum, state[pinNum]);
            }
        }
        lastReading[pinNum] = reading[pinNum];
    }
    for (int i = 0; i < N_PINS_ANALOG; i++) {
        int pinNum = analogPinNums[i];
        reading[pinNum] = analogRead(pinNum);
        if (abs(reading[pinNum] - state[pinNum]) >= RESOLUTION_ANALOG)
        {
            DEBUG_PRINTF("New state pin %d: %d\n", pinNum, reading[pinNum]);
            state[pinNum] = reading[pinNum];
        }
    }
}
