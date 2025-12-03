#ifndef INVENTORY_H
#define INVENTORY_H

#include "Medicine.h"
#include "Tool.h"
#include <vector>
#include <string>

class Inventory {
    private:
        std::vector<Medicine> medicines;
        std::vector<Tool> tools;

    public:
        Inventory();

        void displayAllMedicines() const;
        void displayAllTools() const;
        void displayInventory() const;

        Medicine* findMedicine(const std::string& name);
        Tool* findTool(const std::string& name);

        void addMedicine(const Medicine& medicine);
        void addTool(const Tool& tool);

        void removeMedicine(const std::string& name);
        void removeTool(const std::string& name);

        bool removeMedicineAmount(const std::string& name, int amount);
        bool removeToolAmount(const std::string& name, int amount);

        const std::vector<Medicine>& getMedicines() const;
        const std::vector<Tool>& getTools() const;
};

#endif //INVENTORY_H