#ifndef ALCOHOLIC_DRINKS_HPP
#define ALCOHOLIC_DRINKS_HPP

#include "bottle_drinks.hpp"


enum class BeerType {
    BURN,
    LUCKY,
    GINGER,
    UNDEFINED,
};


enum class WineType {
    RED,
    WHITE,
    PLAYING,
    FORTIFIED,
    PINK,
    UNDEFINED,
};


class Beer: public AlcoholicDrinks {
    BeerType type;

public:
    explicit Beer(const std::string& name, const BeerType& type = BeerType::UNDEFINED,
         const int& alcoholic_degree = 0,
         const int& kcal_amount = 0,
         const int& volume = 0,
         const int& cost = 0)
            : BottleDrinks(name, kcal_amount, volume, cost),
              AlcoholicDrinks(alcoholic_degree, Type::BEER), type(type) { }

    [[nodiscard]] const BeerType& getBeerType() const {
        return this->type;
    }

    void setBeerType(const BeerType& type) {
        this->type = type;
    }

    void clear() override {
        this->type = BeerType::UNDEFINED;
    }
};


class Wine: public AlcoholicDrinks {
    WineType type;

public:
    explicit Wine(const std::string& name, const WineType& type = WineType::UNDEFINED,
         const int& alcoholic_degree = 0,
         const int& kcal_amount = 0,
         const int& volume = 0,
         const int& cost = 0,
         const int& year_of_aging = 0)
            : BottleDrinks(name, kcal_amount, volume, cost),
              AlcoholicDrinks(alcoholic_degree, Type::WINE), type(type) { }

    [[nodiscard]] const WineType& getWineType() const {
        return this->type;
    }

    void setWineType(const WineType& type) {
        this->type = type;
    }

    void clear() override {
        this->type = WineType::UNDEFINED;
    }
};


class Cognac: public AlcoholicDrinks {
    int year_of_aging;

public:
    explicit Cognac(const std::string& name,
         const int& alcoholic_degree = 0,
         const int& kcal_amount = 0,
         const int& volume = 0,
         const int& cost = 0,
         const int& year_of_aging = 0)
            : BottleDrinks(name, kcal_amount, volume, cost),
              AlcoholicDrinks(alcoholic_degree, Type::COGNAC) {
        this->setYearOfAging(year_of_aging);
    }

    [[nodiscard]] const int& getYearOfAging() const {
        return this->year_of_aging;
    }

    void setYearOfAging(const int& year_of_aging) {
        if (year_of_aging > this->getCurrentYear()) {
            throw new AlcoholicDrinksAgingException();
        }
        this->year_of_aging = year_of_aging;
    }

    [[nodiscard]] std::string calcRarity() const {
        const int current_year = 2020;
        if (current_year - this->year_of_aging <= 2) {
            return "VS";
        } else if (current_year - this->year_of_aging <= 4) {
            return "VSOP";
        } else {
            return "XO";
        }
    }

    void clear() override {
        this->year_of_aging = 0;
    }
};


#endif