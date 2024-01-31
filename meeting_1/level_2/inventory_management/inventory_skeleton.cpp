#include <string>
#include <cstddef>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cctype>

// size_t is just a data type of `unsigned int`

const std::size_t INVENTORY_SIZE = 32;
// number of rows shown when printing (must divide INVENTORY_SIZE)
const std::size_t INVENTORY_ROWS = 4;
const std::size_t MAX_STACK_SIZE = 64;
const std::string EMPTY_NAME = "";

struct Item
{
    std::string name;
    size_t stackSize;
};

class GameInventory
{
    Item items[INVENTORY_SIZE];
    size_t numItems;

public:
    // Initializes the inventory with empty elements of stackSize = 0
    GameInventory()
    {
        // TODO
    }

    // Adds the given item name to the inventory if space is available,
    // updating the inventory class appropriately and returning true, otherwise
    // if the given name is not found returns false.
    bool addToInventory(std::string itemName)
    {
        // TODO
        return 0;
    }

    // Removes the given item name from the inventory, updating the inventory
    // class appropriately and returning true, otherwise if the given name is
    // not found return false.
    bool removeFromInventory(std::string itemName)
    {
        // TODO
        return 0;
    }

    // Do not need to modify (unless you want to)
    std::string str()
    {
        size_t maxStringSize = std::max_element(items, items + numItems,
        [](const Item& lhs, const Item& rhs)
        {
            return lhs.name.length() < rhs.name.length();
        })->name.length() + 4;

        std::stringstream ss;
        ss << std::left;
        for (size_t i = 0; i < INVENTORY_ROWS; ++i)
        {
            ss << '|';
            for (size_t j = 0; j < INVENTORY_SIZE / INVENTORY_ROWS; ++j)
            {
                Item item = items[i * (INVENTORY_SIZE / INVENTORY_ROWS) + j];

                std::stringstream concatName;
                if (item.name == EMPTY_NAME)
                    concatName << item.name;
                else
                    concatName << item.stackSize << ' ' << item.name <<
                    (item.stackSize > 1 ? "s" : "");

                ss << ' ' << std::setw(maxStringSize) << concatName.str()
                << std::setw(0) << " |";
            }
            ss << '\n';
        }

        return ss.str();
    }
};

using namespace std;

// Do not need to modify (unless you want to)
int main()
{
    GameInventory inv;
    
    std::string userInput;
    do
    {
        std::cout << "Enter an option (add, remove, print, quit): ";
        std::getline(std::cin, userInput);
        std::transform(
            userInput.begin(),
            userInput.end(),
            userInput.begin(),
            [](unsigned char c)
            {
                return std::tolower(c);
            }
        );

        if ("add" == userInput)
        {
            std::string addItem;
            bool added = false;
            while (!added)
            {
                std::cout << "Enter an item to add: ";
                std::getline(std::cin, addItem);
                std::transform(
                    addItem.begin(),
                    addItem.end(),
                    addItem.begin(),
                    [](unsigned char c)
                    {
                        return std::tolower(c);
                    }
                );

                added = inv.addToInventory(addItem);
                if (!added)
                    std::cout << "Not enough room for item '" << addItem <<
                    "'.\n";
            }
            std::cout << "Added item '" << addItem << "'.\n";
        }
        else if ("remove" == userInput)
        {
            std::string removeItem;
            std::cout << "Enter an item to remove: ";
            std::getline(std::cin, removeItem);
            std::transform(
                removeItem.begin(),
                removeItem.end(),
                removeItem.begin(),
                [](unsigned char c)
                {
                    return std::tolower(c);
                }
            );

            bool removed = inv.removeFromInventory(removeItem);
            if (removed)
                std::cout << "Item '" << removeItem << "' removed from "
                << "inventory.\n";
            else
                std::cout << "Item '" << removeItem << "' not present in "
                << "inventory.\n";
        }
        else if ("print" == userInput)
        {
            std::cout << "Game Inventory:\n";
            std::cout << inv.str() << '\n';
        }
        else if ("quit" == userInput);
        else
            std::cout << "Invalid input.\n";
    }
    while (userInput != "quit");
    
    std::cout << "Bye!\n";
}
