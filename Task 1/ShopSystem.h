#ifndef SHOP_SYSTEM_H
#define SHOP_SYSTEM_H

#include <iostream>

using namespace std;

class ShopSystem {
public:
    void showShop() {
        cout << "[SHOP] offered: Bonus (+2) cost 2\n";
        cout << "[SHOP] skipped\n";
    }
};

#endif