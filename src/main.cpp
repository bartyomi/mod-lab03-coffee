// Copyright 2024 Artyom Burdeyny

#include "../include/Automata.h"

int main() {
    Automata machine;
    machine.on();
    machine.coin(25);
    machine.coin(50);
    machine.choice("Cappuccino");
    machine.check();
    machine.cook();
    machine.coin(50);
    machine.cook();
    machine.finish();
    machine.off();
}
