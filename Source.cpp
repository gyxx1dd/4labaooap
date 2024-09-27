#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Car {
public:
    string engineType;
    double engineCapacity;
    bool hasABS;
    bool hasESP;
    int airbags;
    bool hasBoardComputer;
    string climateControl;
    string interior;

    void showInfo() const {
        cout << "Engine Type: " << engineType << "\n";
        cout << "Engine Capacity: " << engineCapacity << " L\n";
        cout << "ABS: " << (hasABS ? "Yes" : "No") << "\n";
        cout << "ESP: " << (hasESP ? "Yes" : "No") << "\n";
        cout << "Airbags: " << airbags << "\n";
        cout << "Board Computer: " << (hasBoardComputer ? "Yes" : "No") << "\n";
        cout << "Climate Control: " << climateControl << "\n";
        cout << "Interior: " << interior << "\n";
    }
};

class CarBuilder {
public:
    virtual ~CarBuilder() = default;
    virtual void buildEngineType() = 0;
    virtual void buildEngineCapacity() = 0;
    virtual void buildABS() = 0;
    virtual void buildESP() = 0;
    virtual void buildAirbags() = 0;
    virtual void buildBoardComputer() = 0;
    virtual void buildClimateControl() = 0;
    virtual void buildInterior() = 0;
    virtual Car* getCar() = 0;
};

class BasicCarBuilder : public CarBuilder {
private:
    Car* car;
public:
    BasicCarBuilder() {
        car = new Car();
    }

    void buildEngineType() override {
        car->engineType = "Gasoline";
    }

    void buildEngineCapacity() override {
        car->engineCapacity = 1.6;
    }

    void buildABS() override {
        car->hasABS = true;
    }

    void buildESP() override {
        car->hasESP = false;
    }

    void buildAirbags() override {
        car->airbags = 2;
    }

    void buildBoardComputer() override {
        car->hasBoardComputer = false;
    }

    void buildClimateControl() override {
        car->climateControl = "Air Conditioning";
    }

    void buildInterior() override {
        car->interior = "Fabric";
    }

    Car* getCar() override {
        return car;
    }
};

class PremiumCarBuilder : public CarBuilder {
private:
    Car* car;
public:
    PremiumCarBuilder() {
        car = new Car();
    }

    void buildEngineType() override {
        car->engineType = "Diesel";
    }

    void buildEngineCapacity() override {
        car->engineCapacity = 2.0;
    }

    void buildABS() override {
        car->hasABS = true;
    }

    void buildESP() override {
        car->hasESP = true;
    }

    void buildAirbags() override {
        car->airbags = 6;
    }

    void buildBoardComputer() override {
        car->hasBoardComputer = true;
    }

    void buildClimateControl() override {
        car->climateControl = "Climate Control";
    }

    void buildInterior() override {
        car->interior = "Leather";
    }

    Car* getCar() override {
        return car;
    }
};

class Director {
private:
    CarBuilder* builder;
public:
    void setBuilder(CarBuilder* newBuilder) {
        builder = newBuilder;
    }

    Car* buildCar() {
        builder->buildEngineType();
        builder->buildEngineCapacity();
        builder->buildABS();
        builder->buildESP();
        builder->buildAirbags();
        builder->buildBoardComputer();
        builder->buildClimateControl();
        builder->buildInterior();
        return builder->getCar();
    }
};
int main() {
    Director director;
    BasicCarBuilder basicBuilder;
    director.setBuilder(&basicBuilder);
    Car* basicCar = director.buildCar();
    cout << "Basic Car Configuration:\n";
    basicCar->showInfo();
    cout << "\n";
    PremiumCarBuilder premiumBuilder;
    director.setBuilder(&premiumBuilder);
    Car* premiumCar = director.buildCar();
    cout << "Premium Car Configuration:\n";
    premiumCar->showInfo();
    delete basicCar;
    delete premiumCar;

    return 0;
}
