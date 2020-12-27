#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include "drinks.hpp"

int main() {

    Beer obj1("x", BeerType::BURN, 12, 300, 1000, 4);
    Wine obj2("x1", WineType::FORTIFIED, 21, 234, 700, 6, 1995);
    Cognac obj3("x2", 41, 400, 500, 250, 1940);

    Milk obj4("milk", 100, 1000, 5, 100, true, 50);
    Limonade obj5("limonade", 100, 1000, 5, 100, true, true);

    std::cout << obj1.getName() << " " << obj1.getAlcoholicDegree() << " " << obj1.getVolume() << " " << obj1.getCurrentYear() << "\n";
    obj1.setName("beer 1");
    obj1.setVolume(899);
    std::cout << obj1.getName() << " " << obj1.getAlcoholicDegree() << " " << obj1.getVolume() << " " << obj1.getCurrentYear() << "\n";

    std::cout << obj2.getName() << " " << obj2.getAlcoholicDegree() << " " << obj2.getVolume() << " " << obj2.getCurrentYear() << "\n";
    obj2.setWineType(WineType::PLAYING);

    std::cout << obj4.getName() << " " << obj4.getFatness() << " " << obj4.getVolume() << " " << obj4.getSugarAmount() << "\n";
    obj4.setFatness(44);
    obj4.setSugarAmount(1000);

    std::cout << obj4.getName() << " " << obj4.getFatness() << " " << obj4.getVolume() << " " << obj4.getSugarAmount() << "\n";

    return 0;
}