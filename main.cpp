// COMSC-210 | Lab 11 | Mika Aquino
// IDE used: Visual Studio 2022

/* DESCRIPTION:

My application is used to create a menu for a restaurant.

A menu can contain any number of dishes. I have a struct to represent a dish.
I ask the user how many dishes they want to have on their menu -- this menu is represented by a dynamic array of dishes.

Each dish has a name, a price, and ingredients. These are all member variables of the Dish struct.
A dish can have various ingredients in it. Every time the user adds a new dish to their menu, I ask

I store these ingredients in a dynamic array of strings.

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// This struct represents a dish in a menu.
struct Dish {
	string name;
	double price;
	int numIngredients;
	string* ingredients = nullptr; // This dynamic array represents the ingredients used in a dish.
								   // The number of ingredients used in a dish is variable, which is why the array is dynamic.
};

Dish createDish(); // This function creates and returns a single dish.
void displayDish(Dish dish); // This function takes a dish and displays its attributes.
void populateMenu(Dish* menu, const int NUM_DISHES); // This function takes a dynamic array of dishes and populates it by calling createDish() for each element.
void displayMenu(const Dish* menu, const int NUM_DISHES); // This function takes a dynamic array of dishes and displays each dish.
void deallocateMenu(Dish* menu, const int NUM_DISHES); // This function goes through a dynamic array of dishes, deallocates each dish's ingredients member, and then deallocates the dishes array itself.

int main() {
	int numDishes;
	const int UPPER_LIMIT = 10; // This prevents the user from having an absurdly large number of dishes on their menu.
	const int LOWER_LIMIT = 1; // The menu must have at least 1 dish.
	Dish* menu = nullptr;

	// Set numDishes
	cout << "Enter the number of dishes on your menu: ";
	cin >> numDishes;
	while (numDishes < LOWER_LIMIT || numDishes > UPPER_LIMIT) {
		cout << "ERROR: The number of dishes must be between " << LOWER_LIMIT << " and " << UPPER_LIMIT << ". Try again: ";
		cin >> numDishes;
	}
	cin.ignore();
	cout << "\n";

	menu = new Dish[numDishes]; // Allocate memory for dishes

	populateMenu(menu, numDishes); // Populate the menu with dishes
	displayMenu(menu, numDishes); // Display the menu's dishes

	deallocateMenu(menu, numDishes); // Deallocate memory

	return 0;
}

Dish createDish() {
	Dish dish;

	// Set dish name
	cout << "Enter dish name: ";
	getline(cin, dish.name);

	// Set dish price
	cout << "Enter the dish price: ";
	cin >> dish.price;
	while (dish.price < 0) {
		cout << "ERROR: The dish price must a positive value. Try again: ";
		cin >> dish.price;
	}

	// Set number of ingredients
	cout << "Enter the number of ingredients: ";
	cin >> dish.numIngredients;
	while (dish.numIngredients <= 0) {
		cout << "ERROR: The number of ingredients must be greater than 0. Try again: ";
		cin >> dish.numIngredients;
	}
	cin.ignore();

	// Set ingredients
	dish.ingredients = new string[dish.numIngredients]; // allocate memory for ingredients
	for (int i = 0; i < dish.numIngredients; ++i) {
		cout << "\t> Ingredient " << i + 1 << ": ";
		getline(cin, *(dish.ingredients + i));
	}

	return dish;
}

void displayDish(Dish dish) {
	const int CENT_DIGITS = 2; // Used to display 2 digits for cents

	cout << dish.name << " - ";
	cout << "$" << fixed << setprecision(CENT_DIGITS) << dish.price << "\n";
	cout << dish.numIngredients << " ingredients: ";
	for (int i = 0; i < dish.numIngredients; ++i) {
		cout << *(dish.ingredients + i);
		if (i != dish.numIngredients - 1) { // Output a comma for every ingredient except the last one.
			cout << ", ";
		}
	}
	cout << "\n";
}

void populateMenu(Dish* menu, const int NUM_DISHES) {
	for (int i = 0; i < NUM_DISHES; ++i) {
		cout << "CREATING DISH " << i + 1 << "...\n";
		*(menu + i) = createDish();
		cout << "\n";
	}
}

void displayMenu(const Dish* menu, const int NUM_DISHES) {
	cout << "Menu:\n";
	for (int i = 0; i < NUM_DISHES; ++i) {
		displayDish(*(menu + i));
		cout << "\n";
	}
}

void deallocateMenu(Dish* menu, const int NUM_DISHES) {
	for (int i = 0; i < NUM_DISHES; ++i) {
		// This deallocates the ingredients member of each dish element.
		delete[] (menu + i)->ingredients;
		(menu + i)->ingredients = nullptr;
	}

	// This deallocates the dynamic array of dishes.
	delete[] menu; 
	menu = nullptr;
}