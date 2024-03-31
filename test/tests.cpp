// Copyright 2024 Artyom Burdeyny

#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(test, on) {
    Automata machine;
    machine.on();
    EXPECT_EQ(STATE::WAIT, machine.getState());
}

TEST(test, incorrectAction) {
    Automata machine;
    machine.coin(50);
    EXPECT_EQ(STATE::OFF, machine.getState());
}

TEST(test, off) {
    Automata machine;
    machine.on();
    machine.off();
    EXPECT_EQ(STATE::OFF, machine.getState());
}

TEST(test, coin) {
    Automata machine;
    machine.on();
    machine.coin(20);
    EXPECT_EQ(STATE::ACCEPT, machine.getState());
}

TEST(test, notEnoughMoney) {
    Automata machine;
    machine.on();
    machine.coin(30);
    machine.choice("Cappuccino");
    EXPECT_EQ(false, machine.check());
}

TEST(test, enoughMoney) {
    Automata machine;
    machine.on();
    machine.coin(100);
    machine.choice("Cappuccino");
    EXPECT_EQ(true, machine.check());
}

TEST(test, cancel) {
    Automata machine;
    machine.on();
    machine.coin(200);
    machine.cancel();
    EXPECT_EQ(STATE::WAIT, machine.getState());
}

TEST(test, cook) {
    Automata machine;
    machine.on();
    machine.coin(100);
    machine.choice("Latte");
    machine.cook();
    EXPECT_EQ(STATE::COOK, machine.getState());
}

TEST(test, finish) {
    Automata machine;
    machine.on();
    machine.coin(100);
    machine.choice("Latte");
    machine.cook();
    machine.finish();
    EXPECT_EQ(STATE::WAIT, machine.getState());
}

TEST(test, cancel2) {
    Automata machine;
    machine.on();
    machine.coin(100);
    machine.choice("Cappuccino");
    machine.cancel();
    machine.coin(100);
    machine.choice("Espresso");
    EXPECT_EQ(STATE::CHECK, machine.getState());
}
