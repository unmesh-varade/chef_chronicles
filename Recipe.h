#ifndef RECIPE_H
#define RECIPE_H

#include "Ingredient.h"
#include <vector>
#include <iostream>
using namespace std;

class Recipe : public NamedEntity {
public:
    vector<Ingredient> ingredients;
    string procedure;

    Recipe() : NamedEntity(), procedure("") {}
    Recipe(string n, vector<Ingredient> ing, string proc) : NamedEntity(n), ingredients(ing), procedure(proc) {}

    vector<Ingredient> scaleIngredients(double factor) const {
        vector<Ingredient> scaledIngredients;
        for (const auto &ing : ingredients) {
            scaledIngredients.push_back(ing.multiply(factor));
        }
        return scaledIngredients;
    }

    friend ostream &operator<<(ostream &os, const Recipe &recipe);
};

ostream &operator<<(ostream &os, const Recipe &recipe) {
    os << "Recipe: " << recipe.name << "\nIngredients: ";
    for (const auto &ing : recipe.ingredients) {
        os << ing.name << " " << ing.quantity << " " << ing.unit << ", ";
    }
    os << "\nProcedure: " << recipe.procedure << "\n";
    return os;
}

#endif