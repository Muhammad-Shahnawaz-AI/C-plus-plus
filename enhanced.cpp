#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// === Abstract Base Class ===
class CityObject {
public:
    virtual void operate() = 0;
    virtual double monitorPollution() = 0;
    virtual std::string getName() const = 0;
    virtual ~CityObject() {}
};

// === Building Classes ===
class Building : public CityObject {
protected:
    std::string name;
    int energyConsumption;
    double basePollution;
public:
    Building(const std::string& name, int energy, double pollution)
        : name(name), energyConsumption(energy), basePollution(pollution) {}

    void operate() override {
        std::cout << name << " consumes " << energyConsumption << " energy.\n";
    }

    double monitorPollution() override {
        double fluctuation = (rand() % 10 - 5) / 10.0;
        return basePollution + fluctuation;
    }

    std::string getName() const override {
        return name;
    }

    int getEnergyConsumption() const {
        return energyConsumption;
    }
};

class Residential : public Building {
public:
    Residential(const std::string& name, int energy, double pollution)
        : Building(name, energy, pollution) {}

    void operate() override {
        std::cout << "Residential " << name << " operates.\n";
    }
};

class Commercial : public Building {
public:
    Commercial(const std::string& name, int energy, double pollution)
        : Building(name, energy, pollution) {}

    void operate() override {
        std::cout << "Commercial " << name << " operates.\n";
    }
};

class Industrial : public Building {
public:
    Industrial(const std::string& name, int energy, double pollution)
        : Building(name, energy, pollution) {}

    void operate() override {
        std::cout << "Industrial " << name << " operates.\n";
    }
};

// === Transport Classes ===
class Transport : public CityObject {
protected:
    std::string type;
    double basePollution;
public:
    Transport(const std::string& type, double pollution) : type(type), basePollution(pollution) {}

    virtual void move() {
        std::cout << type << " moves.\n";
    }

    void operate() override {
        move();
    }

    double monitorPollution() override {
        double fluctuation = (rand() % 10 - 5) / 10.0;
        return basePollution + fluctuation;
    }

    std::string getName() const override {
        return type;
    }
};

class EV : public Transport {
public:
    EV() : Transport("Electric Vehicle", 1.0) {}

    void move() override {
        std::cout << "EV glides silently.\n";
    }
};

class DieselBus : public Transport {
public:
    DieselBus() : Transport("Diesel Bus", 5.0) {}

    void move() override {
        std::cout << "Diesel Bus rumbles loudly.\n";
    }
};

// === Grid Tile ===
struct Tile {
    CityObject* object = nullptr;
    char symbol = '.';
};

const int MAP_SIZE = 5;
Tile cityMap[MAP_SIZE][MAP_SIZE];
int turnCount = 0;

void displayMap() {
    std::cout << "\nCity Map:\n";
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            std::cout << cityMap[i][j].symbol << ' ';
        }
        std::cout << '\n';
    }
}

int calculatePopulation() {
    int pop = 0;
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            if (cityMap[i][j].symbol == 'R') pop += 10;
        }
    }
    return pop;
}

int calculatePowerUsage() {
    int power = 0;
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            if (cityMap[i][j].object) {
                Building* b = dynamic_cast<Building*>(cityMap[i][j].object);
                if (b) power += b->getEnergyConsumption();
            }
        }
    }
    return power;
}

void monitorPollution() {
    double total = 0.0;
    std::cout << "\n--- Pollution Report ---\n";
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            if (cityMap[i][j].object) {
                double p = cityMap[i][j].object->monitorPollution();
                std::cout << "Tile (" << i << "," << j << ") - " << cityMap[i][j].object->getName()
                          << " Pollution: " << p << " ppm\n";
                total += p;
            }
        }
    }
    std::cout << "Total Pollution: " << total << " ppm\n";
    if (total > 100.0) {
        std::cout << "⚠️  High pollution warning! Take action.\n";
    }
}

void collectTaxes(int& budget) {
    int income = 0;
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            if (cityMap[i][j].object) {
                std::string name = cityMap[i][j].object->getName();
                if (name.find("Home") != std::string::npos) income += 10;
                if (name.find("Shop") != std::string::npos) income += 20;
                if (name.find("Factory") != std::string::npos) income += 30;
            }
        }
    }
    std::cout << "\nCollected Taxes: $" << income << "\n";
    budget += income;
}

void triggerDisaster() {
    int x = rand() % MAP_SIZE;
    int y = rand() % MAP_SIZE;
    if (cityMap[x][y].object) {
        std::cout << "\n🔥 Disaster at (" << x << "," << y << ")! "
                  << cityMap[x][y].object->getName() << " destroyed.\n";
        delete cityMap[x][y].object;
        cityMap[x][y].object = nullptr;
        cityMap[x][y].symbol = '.';
    }
}

int main() {
    srand(time(0));
    int budget = 1000;
    bool running = true;

    while (running) {
        ++turnCount;
        displayMap();
        int population = calculatePopulation();
        int powerUsed = calculatePowerUsage();

        std::cout << "\nTurn: " << turnCount
                  << "\nPopulation: " << population
                  << "\nPower Usage: " << powerUsed
                  << "\nBudget: $" << budget
                  << "\n1. Build Residential ($100)"
                  << "\n2. Build Commercial ($200)"
                  << "\n3. Build Industrial ($300)"
                  << "\n4. Add EV ($50)"
                  << "\n5. Add Diesel Bus ($150)"
                  << "\n6. Monitor Pollution"
                  << "\n7. End Turn"
                  << "\n8. Exit\nChoice: ";

        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= 5) {
            int x, y;
            std::cout << "Enter coordinates (x y): ";
            std::cin >> x >> y;

            if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || cityMap[x][y].object) {
                std::cout << "Invalid or occupied tile.\n";
                continue;
            }

            CityObject* newObj = nullptr;
            char sym = '?';
            int cost = 0;

            switch (choice) {
                case 1: newObj = new Residential("Home", 30, 2.0); sym = 'R'; cost = 100; break;
                case 2: newObj = new Commercial("Shop", 100, 3.5); sym = 'C'; cost = 200; break;
                case 3: newObj = new Industrial("Factory", 200, 6.0); sym = 'I'; cost = 300; break;
                case 4: newObj = new EV(); sym = 'E'; cost = 50; break;
                case 5: newObj = new DieselBus(); sym = 'D'; cost = 150; break;
            }

            if (budget >= cost) {
                cityMap[x][y].object = newObj;
                cityMap[x][y].symbol = sym;
                budget -= cost;
            } else {
                delete newObj;
                std::cout << "Not enough budget!\n";
            }

        } else if (choice == 6) {
            monitorPollution();
        } else if (choice == 7) {
            collectTaxes(budget);
            if (rand() % 10 == 0) triggerDisaster();
        } else if (choice == 8) {
            running = false;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            delete cityMap[i][j].object;
        }
    }

    std::cout << "Thanks for playing SimCity Console Edition!\n";
    return 0;
}
