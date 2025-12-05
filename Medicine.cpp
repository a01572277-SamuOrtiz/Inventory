
#include "Medicine.h"
#include <iostream>

Medicine::Medicine(std::string mname, int mamount, std::string exmonth, int exyear)
    : name(mname), amount(mamount), expirationmonth(exmonth), expirationyear(exyear) {
}

std::string Medicine::getName() const {
    return name;
}

int Medicine::getAmount() const {
    return amount;
}

std::string Medicine::getExpirationMonth() const {
    return expirationmonth;
}

int Medicine::getExpirationYear() const {
    return expirationyear;
}

void Medicine::setName(const std::string& mname) {
    name = mname;
}

void Medicine::setAmount(int mamount) {
    amount = mamount;
}

void Medicine::setExpirationMonth(const std::string& exmonth) {
    expirationmonth = exmonth;
}

void Medicine::setExpirationYear(int exyear) {
    expirationyear = exyear;
}

void Medicine::addAmount(int mamount) {
    amount += mamount;
}

void Medicine::removeAmount(int mamount) {
    amount -= mamount;
    if (amount < 0) {
        amount = 0;
    }
}

// Helper function to convert month name to number
int Medicine::monthToNumber(const std::string& month) const {
    if (month == "January") return 1;
    if (month == "February") return 2;
    if (month == "March") return 3;
    if (month == "April") return 4;
    if (month == "May") return 5;
    if (month == "June") return 6;
    if (month == "July") return 7;
    if (month == "August") return 8;
    if (month == "September") return 9;
    if (month == "October") return 10;
    if (month == "November") return 11;
    if (month == "December") return 12;
    return 0; // Invalid month
}

bool Medicine::Expired(std::string month, int year) {
    // Check if medicine has expired based on current date
    if (year > expirationyear) {
        return true;
    }
    if (year == expirationyear) {
        // Convert month names to numbers for proper comparison
        return monthToNumber(month) > monthToNumber(expirationmonth);
    }
    return false;
}

void Medicine::displayMedicine() const {
    std::cout << "\nMedicine: " << name << "\n";
    std::cout << "Amount: " << amount << "\n";
    std::cout << "Expiration: " << expirationmonth << " " << expirationyear << "\n";
}