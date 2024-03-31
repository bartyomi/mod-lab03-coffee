#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <map>
#include <string>
#include <iostream>

enum STATE { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    string[] menu;
    int[] prices;
    STATE state;
 public:
    Automata();
    void on();
    void off();
    void coin(int value);
    void choice(string value);
    void cancel();
    bool check();
    void cook();
    void finish();
    void getMenu();
    STATE getState();
};

#endif  // INCLUDE_AUTOMATA_H_
