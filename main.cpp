// Program features a simple dynamic array of structs.
// The struct definition itself should ALSO include a dynamic array, + other member variables.
// Model the program off of a real-world scenario.

/*
Idea:

Create a Dish struct, which contains a: string name, double price, string* ingredients. The ingredients is the dynamic array.

In the main program:
Declare a menu, which is a pointer to a dynamic array of NUM_DISH Dish objects.
menu = newDish[NUM_DISH]

Then call a function to populate the menu with dishes:
populateMenu(menu, NUM_DISHES); << takes: a Dish ptr, an int

Then call a function to display the menu:
displayMenu(menu, NUM_DISHES); takes: a Dish ptr, an int

Remember to make the parameters const if appropriate

populateMenu will go through each element in the menu.
	It will fill each dish with data (probably calling a separate function to do this work).

displayMenu will go through each dish of the menu, and output that dish's attributes

Do not forget to deallocate memory used by both the dishes in the menu, and the strings in each dish.

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

	// TODO: deallocate memory

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
		cout << "ERROR: The number of ingredients most be greater than 0. Try again: ";
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