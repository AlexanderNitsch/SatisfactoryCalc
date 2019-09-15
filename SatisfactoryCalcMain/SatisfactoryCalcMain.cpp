// SatisfactoryCalcMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "../SatisfactoryCalc/Resource.h"
#include "../SatisfactoryCalc/Factory.h"


int main()
{
	Factory myFactory;
	std::map<ResourceType, double> desiredResources = {
		{HeavyModularFrame, 2},
		{SteelPipe, 15},
		{Motor, 3},
		{IronPlate, 100},
		{ReinforcedIronPlate, 30},
		{SteelBeam, 15},
		{Cable, 30},
		{ModularFrame, 5}
		};
	std::map<ResourceType, double> allResources = myFactory.calcAllIngredients(desiredResources);

	std::map<ResourceType, double> productionConstraints = {
		{IronOre, 480},
		{LimeStone, 480},
		{Coal, 480}
	};

	std::map<ResourceType, double> possibleResources = myFactory.calcPossibleIngredients(productionConstraints, allResources);

	std::map<ResourceType, double> necessaryFactories = myFactory.calcNecessaryFactories(possibleResources);

	for (auto& pair : allResources) {
		std::cout << "Type: " << resourceNames[pair.first] << " Amount: " << pair.second << std::endl;
	}

	std::cout << "POSSIBLE:" << std::endl;

	for (auto& pair : possibleResources) {
		std::cout << "Type: " << resourceNames[pair.first] << " Amount: " << pair.second << std::endl;
	}

	std::cout << "FACTORIES:" << std::endl;
	for (auto& pair : necessaryFactories) {
		std::cout << "Type: " << resourceNames[pair.first] << " Amount: " << pair.second << std::endl;
	}

	std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
