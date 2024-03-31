#include "../include/Automata.h"

using namespace std;

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
        cout << "Automata is on" << endl;
    } else {
        cout << "Impossible action" << endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        cout << "Automata is off" << endl;
    } else {
        cout << "Impossible action" << endl;
    }
}

void Automata::coin(int value) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += value;
        cout << "Added " << cash << endl;
    } else {
        cout << "Impossible action" << endl;
    }
}

void Automata::choice(string value) {
    if (state == ACCEPT) {
        coffee = value;
        state = CHECK;
    } else {
        cout << "Impossible action" << endl;
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= menu[coffee]) return true;
        cout << "Not enough money" << endl;
    } else {
        cout << "Impossible action" << endl;
    }
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        cout << "Operation canceled" << endl;
    } else {
        cout << "Impossible action" << endl;
    }
}


void Automata::cook() {
    if (state == CHECK) {
        if (!check()) return;
        cash -= menu[coffee];
        state = COOK;
        cout << "Cooking..." << endl;
    } else {
        cout << "Impossible action" << endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        cout << "Your " << coffee << " is done" << endl;
        cout << "Take " << cash << " back" << endl;
        cash = 0;
        state = WAIT;
    } else {
        cout << "Impossible action" << endl;
    }
}

void Automata::getMenu() {
    for (string name, int price)
        cout << name << " - " << price << endl;
}

STATE Automata::getState() {
    return state;
}
