#ifndef NON_ALCOHOLIC_DRINKS_HPP
#define NON_ALCOHOLIC_DRINKS_HPP

#include "bottle_drinks.hpp"


class Milk: public NonAlcoholicDrinks {
    int fatness;

public:
    explicit Milk(const std::string& name,
         const int& kcal_amount = 0,
         const int& volume = 0,
         const int& cost = 0,
         const int& sugar_amount = 0,
         const bool& useful_for_body = false,
         const int& fatness = 0)
            : BottleDrinks(name, kcal_amount, volume, cost),
              NonAlcoholicDrinks(sugar_amount, useful_for_body), fatness(fatness) { }

    [[nodiscard]] bool getFatness() const {
        return this->fatness;
    }

    void setFatness(const int& fatness) {
        this->fatness = fatness;
    }

    void clear() override {
        this->fatness = 0;
    }
};

class [[maybe_unused]] Limonade: public NonAlcoholicDrinks {
    bool cold;

public:
    explicit Limonade(const std::string& name,
         const int& kcal_amount = 0,
         const int& volume = 0,
         const int& cost = 0,
         const int& sugar_amount = 0,
         const bool& useful_for_body = false,
         const bool& isCold = true)
            : BottleDrinks(name, kcal_amount, volume, cost),
              NonAlcoholicDrinks(sugar_amount, useful_for_body), cold(cold) { }

    [[nodiscard]] bool getIsCold() const {
        return this->cold;
    }

    void setIsCold(const bool& cold) {
        this->cold = cold;
    }


    void clear() override {
        this->cold = false;
    }
};


#endif