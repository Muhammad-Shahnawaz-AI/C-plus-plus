#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <thread>
#include <chrono>
#include <cstdlib>
#include<stdlib.h>
// === Abstract Base Class ===
class CityObject {
public:
    virtual void operate() = 0;
    virtual double monitorPollution() = 0; // Simulate real-time pollution
    virtual ~CityObject() {}
};
// === Inheritance and Polymorphism ===
class Building : public CityObject {
protected:
    std::string name;
    int energyConsumption;
    double basePollution; // New
public:
    Building(const std::string& name, int energy, double pollution)
        : name(name), energyConsumption(energy), basePollution(pollution) {}

    virtual void operate() override {
        std::cout << name << " consumes " << energyConsumption << " units of energy.\n";
    }

    double monitorPollution() override {
        // Pollution fluctuates randomly
        double fluctuation = (rand() % 10 - 5) / 10.0;
        return basePollution + fluctuation;
    }
};
class Residential : public Building {
public:
    Residential(const std::string& name, int energy, double pollution)
        : Building(name, energy, pollution) {}

    void operate() override {
        std::cout << "Residential " << name << " consumes " << energyConsumption << " units.\n";
    }
};
class Commercial : public Building {
public:
    Commercial(const std::string& name, int energy, double pollution)
        : Building(name, energy, pollution) {}

    void operate() override {
        std::cout << "Commercial " << name << " consumes " << energyConsumption << " units.\n";
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
        std::cout << type << " is moving...\n";
    }

    void operate() override {
        move();
    }

    double monitorPollution() override {
        double fluctuation = (rand() % 10 - 5) / 10.0;
        return basePollution + fluctuation;
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
// === Pollution Sensor ===
class PollutionSensor {
public:
    static void readSensors(const std::vector<CityObject*>& cityObjects) {
        std::cout << "\n--- Pollution Monitoring ---\n";
        for (const auto& obj : cityObjects) {
            double pollution = obj->monitorPollution();
            std::cout << "Object Pollution Level: " << pollution << " ppm\n";
        }
    }
};
// === Custom Exception ===
class UpgradeException : public std::exception {
private:
    std::string message;
public:
    explicit UpgradeException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
int main() {
    try {
        std::vector<CityObject*> city;

        // Add buildings and transport to the city
        city.push_back(new Residential("GreenVille Home", 30, 2.0));
        city.push_back(new Commercial("EcoMall", 120, 3.5));
        city.push_back(new EV());
        city.push_back(new DieselBus());

        std::cout << "=== City Simulation Start ===\n";
        for (CityObject* obj : city) {
            obj->operate();
        }

        // Simulate real-time pollution monitoring (e.g., 5 intervals)
        for (int i = 0; i < 10000; ++i) {
            PollutionSensor::readSensors(city);
            std::this_thread::sleep_for(std::chrono::seconds(1)); // simulate real-time delay
            std::cout << "\033[2J\033[1;1H";
        }

        // Clean up
        for (CityObject* obj : city) {
            delete obj;
        }

        // Simulate an exception
        throw UpgradeException("Upgrade failed: Insufficient budget.");

    } catch (const UpgradeException& ex) {
        std::cerr << "\nException: " << ex.what() << "\n";
    }
    return 0;
}

