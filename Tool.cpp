#include "Tool.h"
#include <iostream>

Tool::Tool(std::string tname, int tamount, int yearb, int yearc)
    : name(tname), amount(tamount), yearbought(yearb), yearchange(yearc) {
}

std::string Tool::getName() const {
    return name;
}

int Tool::getAmount() const {
    return amount;
}

int Tool::getYearBought() const {
    return yearbought;
}

int Tool::getYearChange() const {
    return yearchange;
}

void Tool::setName(const std::string& tname){
    name = tname;
}

void Tool::setAmount(int tamount){
    amount = tamount;
}

void Tool::setYearBought(int yearb){
    yearbought = yearb;
}