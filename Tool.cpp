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

void Tool::setYearChange(int yearc){
    yearchange = yearc;
}

void Tool::addAmount(int tamount) {
    amount += tamount;
}

void Tool::removeAmount(int tamount) {
    amount -= tamount;
    if (amount < 0) {
        amount = 0;
    }
}

bool Tool::ReplaceTool(int year) {
    int yearsSincePurchase = year - yearbought;
    return yearsSincePurchase >= yearchange;
}

void Tool::displayTool() const {
    std::cout << "\nTool: " << name << "\n";
    std::cout << "Amount: " << amount << "\n";
    std::cout << "Year Bought: " << yearbought << "\n";
    std::cout << "Replace After (years): " << yearchange << "\n";
}