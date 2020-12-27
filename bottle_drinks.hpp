#ifndef BOTTLE_DRINKS_HPP
#define BOTTLE_DRINKS_HPP

#include <string>
#include <utility>


enum class Type {
    COCKTAIL,
    WHISKEY,
    COGNAC,
    VODKA,
    WINE,
    GIN,
    BEER,
    UNDEFINED,
};


class BottleDrinks {
    std::string name;
    int kcal_amount;
    int volume;
    int cost;

protected:
    BottleDrinks(std::string  name, const int& kcal_amount, const int& volume, const int& cost)
        : name(std::move(name)), kcal_amount(kcal_amount), volume(volume), cost(cost) { }

public:
    virtual void setName(const std::string& name) {
        this->name = name;
    }

    [[nodiscard]] virtual const std::string& getName() const {
        return this->name;
    }

    virtual void setVolume(const int& volume) {
        this->volume = volume;
    }

    [[nodiscard]] virtual const int& getVolume() const {
        return this->volume;
    }

    virtual void clear() = 0;
};


class AlcoholicDrinks : virtual public BottleDrinks {
    int alcoholic_degree;
    Type type;
    const int current_year = 2020;

protected:
    AlcoholicDrinks(const int& alcoholic_degree, const Type& type)
        : alcoholic_degree(alcoholic_degree), type(type) { }

public:
    [[nodiscard]] virtual const int& getAlcoholicDegree() const {
        return this->alcoholic_degree;
    }

    [[nodiscard]] virtual const Type& getType() const {
        return this->type;
    }

    virtual const int& getCurrentYear() {
        return this->current_year;
    }
};


class NonAlcoholicDrinks : virtual public BottleDrinks {
    int sugar_amount;
    bool useful_for_body;

protected:
    NonAlcoholicDrinks(const int& sugar_amount, const bool& useful_for_body)
        : sugar_amount(sugar_amount), useful_for_body(useful_for_body) { }

public:
    [[nodiscard]] virtual const int& getSugarAmount() const {
        return this->sugar_amount;
    }

    virtual void setSugarAmount(const int& sugar_amount) {
        this->sugar_amount = sugar_amount;
    }

    [[nodiscard]] virtual const bool& usefulForBody() const {
        return this->useful_for_body;
    }
};


class AlcoholicDrinksAgingException: public std::exception {
public:
    virtual const char* what() const throw() {
        return "alcoholic drink year aging exception";
    }
};


#endif