#ifndef TOOL_H
#define TOOL_H

#include <string>

class Tool {
    private:
        std::string name;
        int amount;
        int yearbought;
        int yearchange;

    public:
        Tool(std::string tname, int tamount, int yearb, int yearc);

        std::string getName() const;
        int getAmount() const;
        int getYearBought() const;
        int getYearChange() const;

        void setName(const std::string& tname);
        void setAmount(int tamount);
        void setYearBought(int yearb);
        void setYearChange(int yearc);

        void addAmount(int tamount);
        void removeAmount(int tamount);
        bool ReplaceTool(int year);
        
        void displayTool() const;
};

#endif // TOOL_H