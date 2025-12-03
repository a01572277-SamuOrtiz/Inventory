#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>

class Medicine{
    private:
        std::string name;
        int amount;
        std::string expirationmonth;
        int expirationyear;

    public:
        Medicine(std::string mname, int mamount, std::string exmonth, int exyear);

        std::string getName() const;
        int getAmount() const;
        std::string getExpirationMonth() const;
        int getExpirationYear() const;

        void setName(const std::string& mname);
        void setAmount(int amount);
        void setExpirationMonth(const std::string& exmonth);
        void setExpirationYear (int exyear);

        void addAmount(int mamount);
        void removeAmount(int mamount);
        bool Expired(std::string month, int year);

        void displayMedicine() const;

}
#endif // MEDICINE_H