#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include "Recipe.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class RecipeBook {
public:
    unordered_map<string, Recipe> recipes;

public:
    // Adds a recipe to the recipe book
    virtual void addRecipe(const Recipe &recipe) {
        recipes[recipe.name] = recipe;
    }

    // Searches for a recipe by name
    Recipe *searchRecipe(const string &name) {
        if (recipes.find(name) != recipes.end()) {
            return &recipes[name];
        }
        return nullptr;
    }

    // Displays all recipes in the book
    void displayAllRecipes() const {
        cout << left << setw(20) << "Recipe Name" << "Ingredients\n";
        cout << "---------------------------------------\n";
        for (const auto &pair : recipes) {
            cout << left << setw(20) << pair.first << pair.second.ingredients.size() << " items\n";
        }
    }

    // Define the virtual updateRecipe method
    virtual void updateRecipe(const string &name) {
        cout << "Update functionality not implemented.\n";
    }

    // Define the virtual deleteRecipe method
    virtual bool deleteRecipe(const string &name) {
        return recipes.erase(name) > 0;
    }

    // Returns the recipes in the recipe book
    unordered_map<string, Recipe> getRecipes() const {
        return recipes;
    }
};

#endif
