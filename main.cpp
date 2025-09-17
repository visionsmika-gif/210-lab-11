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
using namespace std;

struct Dish {
	string name;
	double price;
};

int main() {

	return 0;
}