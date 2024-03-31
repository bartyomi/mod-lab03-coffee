// Copyright 2024 Artyom Burdeyny

#include "../include/Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = {
        {"Latte", 90},
        {"Cappuccino", 90},
        {"Moccachino", 100},
        {"Espresso", 60},
        {"Tea", 70}
    };
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Automata is on" << std::endl;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Automata is off" << std::endl;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
}

void Automata::coin(int value) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += value;
        std::cout << "Added " << cash << std::endl;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
}

void Automata::choice(string value) {
    if (state == ACCEPT) {
        coffee = value;
        state = CHECK;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= menu[coffee]) return true;
        std::cout << "Not enough money" << std::endl;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        std::cout << "Operation canceled" << std::endl;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
}


void Automata::cook() {
    if (state == CHECK) {
        if (!check()) return;
        cash -= menu[coffee];
        state = COOK;
        std::cout << "Cooking..." << std::endl;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        std::cout << "Your " << coffee << " is done" << std::endl;
        std::cout << "Take " << cash << " back" << std::endl;
        cash = 0;
        state = WAIT;
    } else {
        std::cout << "Impossible action" << std::endl;
    }
}

void Automata::getMenu() {
    for (string name, int price)
        std::cout << name << " - " << price << std::endl;
}

STATE Automata::getState() {
    return state;
}
