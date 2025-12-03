#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {

}

void Inventory::displayAllMedicines() const {
    if (medicines.empty()) {
        std::cout << "No medicines in stock";
        return;
    }

    std::cout << "===== Medicines in Inventory =====";
    for (const auto& med : medicines) {
        med.displayMedicine();
        std::cout << "================================";
    }
}

void Inventory::displayAllTools() const {
    if (tools.empty()) {
        std::cout << "No tools in inventory";
        return;
    }

    std::cout << "======= Tools in Inventory =======";
    for (const auto& tool : tools) {
        tool.displayTool();
        std::cout << "================================";
    }
}

void Inventory::displayInventory() const {
    std::cout << "------------- Inventory -------------";
    displayAllMedicines();
    displayAllTools();
    std::cout << "-------------------------------------";
}

Medicine* Inventory::findMedicine(const std::string& name) {
    for(auto& med : medicines) {
        if (med.getName() == name) {
            return &med;
        }
    }
    return nullptr;
}


Tool* Inventory::findTool(const std::string& name) {
    for(auto& tool : tools) {
        if (tool.getName() == name) {
            return &tool;
        }
    }
    return nullptr;
}

void Inventory::addMedicine(const Medicine& medicine) {
    Medicine* existing = findMedicine(medicine.getName());
    if (existing != nullptr) {
        existing->addAmount(medicine.getAmount());
        std::cout << "Added: " << medicine.getAmount() <<" to medicine: " << medicine.getName();
    } else {
        medicines.push_back(medicine);
        std::cout << "New medicine added: " << medicine.getName();
    }
}

void Inventory::addTool(const Tool& tool) {
    Tool* existing = findTool(tool.getName());
    if (existing != nullptr) {
        existing->addAmount(tool.getAmount());
        std::cout << "Added: " << tool.getAmount() << " to tool: " << tool.getName();
    } else {
        tools.push_back(tool);
        std::cout << "New tool added: " << tool.getName();
    }
}

void Inventory::removeMedicine(const std::string& name){
    for (auto it = medicines.begin(); it != medicines.end(); ++it) {
        if (it->getName() == name){
            medicines.erase(it);
            std::cout << "Removed medicine: " << name;
            return; 
        }
    }
    std::cout << "Medicine not found: " << name;
}

void Inventory::removeTool(const std::string& name) {
    for ( auto it = tools.begin(); it != tools.end(); ++it) {
        if(it->getName() == name) {
            tools.erase(it);
            std::cout << "Removed tool: " << name;
            return;
        }
    }
    std::cout << "Tool not found: " << name;
}

bool Inventory::removeMedicineAmount(const std::string& name, int amount) {
    Medicine* med = findMedicine(name);
    if (med == nullptr) {
        std::cout << "Medicine not found: " << name << "\n";
        return false;
    }
    
    if (med->getAmount() < amount) {
        std::cout << "Not enough " << name << " in inventory. Available: " 
                  << med->getAmount() << "\n";
        return false;
    }
    
    med->removeAmount(amount);
    std::cout << "Removed " << amount << " of " << name << "\n";
    
 
    if (med->getAmount() == 0) {
        removeMedicine(name);
        std::cout << name << " is now out of stock and removed from inventory.\n";
    }
    
    return true;
}

bool Inventory::removeToolAmount(const std::string& name, int amount) {
    Tool* tool = findTool(name);
    if (tool == nullptr) {
        std::cout << "Tool not found: " << name << "\n";
        return false;
    }
    
    if (tool->getAmount() < amount) {
        std::cout << "Not enough " << name << " in inventory. Available: " 
                  << tool->getAmount() << "\n";
        return false;
    }
    
    tool->removeAmount(amount);
    std::cout << "Removed " << amount << " of " << name << "\n";

    if (tool->getAmount() == 0) {
        removeTool(name);
        std::cout << name << " is now out of stock and removed from inventory.\n";
    }
    
    return true;
}

const std::vector<Medicine>& Inventory::getMedicines() const {
    return medicines;
}

const std::vector<Tool>& Inventory::getTools() const {
    return tools;
}