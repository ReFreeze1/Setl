#include <iostream>
#include <string>
#include <vector>

struct build {
    std::string name;
    double square;
};
struct Room {
    std::string name;
    double square;
};
struct Floors {
    int rooms = 1;
    std::vector<Room> ro;
};
struct house {
    int floor = 1;
    std::vector<Floors>flo;
};
struct sector {
    double square;
    std::vector<build> Build;
    house home;
};
struct Setlement {
    std::string name;
    std::vector<sector>sec;
};


void add(Setlement& set) {
    std::cout << "Input square of sector: ";
    double temp;
    std::cin >> temp;
    set.sec.push_back({ temp });
    std::cout << "Input amount floor of house: ";
    std::cin >> set.sec[set.sec.size() - 1].home.floor;
    for (int i = 0; i < set.sec[set.sec.size() - 1].home.floor; i++) {//проходим по этажам
        int t = 0;
        std::cout << "Input amount rooms on the floor" << i + 1 << ": ";
        std::cin >> t;
        set.sec[set.sec.size() - 1].home.flo.push_back({ t });
        for (int j = 0; j < t; j++) {//проходим по комнатам
            std::cout << "Input name of room" << j + 1 << ": ";
            std::string name = "";
            std::cin >> name;
            set.sec[set.sec.size() - 1].home.flo[i].ro.push_back({ name });
            std::cout << "Input square of room" << j + 1 << ": ";
            std::cin >> set.sec[set.sec.size() - 1].home.flo[i].ro.back().square;
        }
    }
    std::string ch = "";
    std::cout << "Builds on the sector (yes/no): ";
    std::cin >> ch;
    if (ch == "yes") {
        int t;
        std::cout << "How many builds on the sector?: ";
        std::cin >> t;
        for (int i = 0; i < t; i++) {
            std::string name;
            std::cout << "Input name of the build: ";
            std::cin >> name;
            set.sec.back().Build.push_back({ name });
            std::cout << "Input square of the " << name << ": ";
            std::cin >> set.sec.back().Build[i].square;
        }
    }

}
void sum(Setlement& set) {
    double square = 0;
    for (int i = 0; i < set.sec.size(); i++) {
        square += set.sec[i].square;
    }
    std::cout << "The square of setlement is: " << square << "m.\n";
}

int main()
{
    Setlement set;
    std::cout << "Input name of the setlement: ";
    std::cin >> set.name;
    std::string choose;
    do {
        std::cout << "choose action (add, sum, exit): ";
        std::cin >> choose;
        if (choose == "add") add(set);
        if (choose == "sum") sum(set);
    } while (choose != "exit");


}
