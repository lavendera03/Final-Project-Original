#ifndef CLOSET_H
#define CLOSET_H

#include "Clothing.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

template <typename T>
class Closet{
    public:
        void addClothing(string itemType, vector<T> itemAttributes);
        void removeItem(int idx);
        void showCloset();
        vector<Clothing> generateOutfit(int dressiness, int avgTemp);
        void saveOutfit();
        void showOutfits();
        Closet();

    private:
        vector<vector<Clothing>> savedOutfits;
        vector <Clothing> closetItems;


};

#endif