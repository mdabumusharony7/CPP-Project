#include <iostream>
#include <vector>
#include <string>

class Vehicle
{
private:
    std::string type;
    float price;
    int count;

public:
    Vehicle(std::string _type, float _price) : type(std::move(_type)), price(_price), count(0) {}

    void enterVehicle()
    {
        count++;
    }

    int getCount() const
    {
        return count;
    }

    float getPrice() const
    {
        return price;
    }

    const std::string &getType() const
    {
        return type;
    }

    void resetCount()
    {
        count = 0;
    }
};

class VehicleManagementSystem
{
private:
    std::vector<Vehicle> vehicles;
    int totalVehicles;
    float totalGainAmount;

public:
    VehicleManagementSystem() : totalVehicles(0), totalGainAmount(0)
    {
        vehicles.emplace_back("Truck", 10.0f);
        vehicles.emplace_back("Bus", 8.0f);
        vehicles.emplace_back("Car", 5.0f);
        vehicles.emplace_back("Bike", 2.0f);
        vehicles.emplace_back("Cycle", 1.0f);
    }

    void enterVehicle(int vehicleType)
    {
        if (vehicleType >= 1 && vehicleType <= 5)
        {
            vehicles[vehicleType - 1].enterVehicle();
            totalVehicles++;
            totalGainAmount += vehicles[vehicleType - 1].getPrice();
            std::cout << "Vehicle entered successfully!\n";
        }
        else
        {
            std::cout << "Invalid choice\n";
        }
    }

    void showStatus()
    {
        std::cout << "\n--- Vehicle Status ---\n";
        for (const auto &vehicle : vehicles)
        {
            std::cout << vehicle.getType() << ": " << vehicle.getCount() << '\n';
        }
        std::cout << "Total Vehicles: " << totalVehicles << '\n';
        std::cout << "Total Gain Amount: $" << totalGainAmount << '\n';
    }

    void deleteData()
    {
        for (auto &vehicle : vehicles)
        {
            vehicle.resetCount();
        }
        totalVehicles = 0;
        totalGainAmount = 0.0f;
        std::cout << "\nAll data deleted!\n";
    }
};

int main()
{
    VehicleManagementSystem vms;

    int choice;
    do
    {
        std::cout << "\nVehicle Management System\n";
        std::cout << "1. Enter Vehicle\n";
        std::cout << "2. Show Status\n";
        std::cout << "3. Delete Data\n";
        std::cout << "4. Exit Program\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            int vehicleType;
            std::cout << "\nEnter Vehicle Type (1-5): ";
            std::cin >> vehicleType;
            vms.enterVehicle(vehicleType);
            break;
        case 2:
            vms.showStatus();
            break;
        case 3:
            vms.deleteData();
            break;
        case 4:
            std::cout << "Exiting... Thank you!\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
