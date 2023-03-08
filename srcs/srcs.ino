#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_sv_SE.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>

#include "PinWatcher.hpp"
#include "debugPrintf.hpp"
#include "defaults.hpp"
#include "pinnums.hpp"

PinWatcher* pinWatcher;

void setup()
{
    pinWatcher = new PinWatcher();
#ifdef _DEBUG
    Serial.begin(9600);
    while (!Serial)
        ; // Leonardo: wait for Serial Monitor
#endif
}

void loop()
{
    pinWatcher->updateState();
}
