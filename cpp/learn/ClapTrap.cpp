#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string name;
    unsigned int hitPoints = 10; // Health
    unsigned int energyPoints = 10; // Energy
    unsigned int attackDamage = 0;

public:
    // Constructor
    ClapTrap(std::string name) : name(name) {
        std::cout << "Constructor: ClapTrap " << name << " created." << std::endl;
    }

    // Destructor
    ~ClapTrap() {
        std::cout << "Destructor: ClapTrap " << name << " destroyed." << std::endl;
    }

    // Getter and Setter for Name
    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    // Getter and Setter for Hit Points
    unsigned int getHitPoints() const { return hitPoints; }
    void setHitPoints(unsigned int newHitPoints) { 
        if (newHitPoints > 0 && newHitPoints <= 100) {
            hitPoints = newHitPoints;
        } else {
            std::cerr << "Error: Invalid hit points value." << std::endl;
        }
    }

    // Getter and Setter for Energy Points
    unsigned int getEnergyPoints() const { return energyPoints; }
    void setEnergyPoints(unsigned int newEnergyPoints) { 
        if (newEnergyPoints >= 0 && newEnergyPoints <= 100) {
            energyPoints = newEnergyPoints;
        } else {
            std::cerr << "Error: Invalid energy points value." << std::endl;
        }
    }

    // Getter and Setter for Attack Damage
    unsigned int getAttackDamage() const { return attackDamage; }
    void setAttackDamage(unsigned int newAttackDamage) { 
        if (newAttackDamage >= 0) {
            attackDamage = newAttackDamage;
        } else {
            std::cerr << "Error: Invalid attack damage value." << std::endl;
        }
    }

    // Member Functions
    void attack(const std::string& target) {
        if (energyPoints > 0) {
            energyPoints--;
            std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        } else {
            std::cout << "ClapTrap " << name << " cannot attack due to lack of energy points." << std::endl;
        }
    }

    void takeDamage(unsigned int amount) {
        if (hitPoints > 0) {
            hitPoints -= amount;
            std::cout << "ClapTrap " << name << " takes " << amount << " points of damage, now has " << hitPoints << " hit points left." << std::endl;
        } else {
            std::cout << "ClapTrap " << name << " cannot take damage because it has no hit points left." << std::endl;
        }
    }

    void beRepaired(unsigned int amount) {
        if (energyPoints > 0) {
            energyPoints--;
            hitPoints += amount;
            std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points, now has " << hitPoints << " hit points left." << std::endl;
        } else {
            std::cout << "ClapTrap " << name << " cannot repair itself due to lack of energy points." << std::endl;
        }
    }
};

int main() {
    ClapTrap claptrap1("Clappy");
    ClapTrap claptrap2("Crunchy");

    // Simulate battle
    for (unsigned int i = 0; i < 5; ++i) {
        claptrap1.attack(claptrap2.getName());
        claptrap2.takeDamage(claptrap1.getAttackDamage());

        claptrap2.attack(claptrap1.getName());
        claptrap1.takeDamage(claptrap2.getAttackDamage());
    }

    // Determine winner
    if (claptrap1.getHitPoints() > claptrap2.getHitPoints()) {
        std::cout << "Winner: ClapTrap " << claptrap1.getName() << " with " << claptrap1.getHitPoints() << " hit points left." << std::endl;
    } else if (claptrap2.getHitPoints() > claptrap1.getHitPoints()) {
        std::cout << "Winner: ClapTrap " << claptrap2.getName() << " with " << claptrap2.getHitPoints() << " hit points left." << std::endl;
    } else {
        std::cout << "Draw between ClapTrap " << claptrap1.getName() << " and ClapTrap " << claptrap2.getName() << "." << std::endl;
    }

    return 0;
}
