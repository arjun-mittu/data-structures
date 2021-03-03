#include <iostream>
#include "hastable.h"
#include <cstring>
#include <string>
using namespace std;

int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("BurgerPizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 120);
    price_menu.print();

    int *price = price_menu.search("Noodles");
    if (price == NULL)
    {
        cout << "Not found";
    }
    else
    {
        cout << "price is " << *price << endl;
    }

    //insert
    price_menu["Dosa"] = 60;
    price_menu["Dosa"] += 10;
    cout << "price of Dosa" << price_menu["Dosa"] << endl;
    return 0;
}