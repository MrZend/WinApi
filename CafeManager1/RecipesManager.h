#pragma once
#include "PCH.h"
#include "Recipe.h"


class RecipesManager
{
	std::vector<Recipe> recipes;
public:
	RecipesManager();
	~RecipesManager();
	void ScanRecipes();
	void AddRecipe(const Recipe &r);
	void EditRecipe(const Recipe& r);
};

