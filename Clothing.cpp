#include "Clothing.h"

#include <iostream>
#include <string>

using namespace std;

//clothing constructor
Clothing::Clothing(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness): name(name), type(type), color(color), pattern(pattern), warmth_Level(warmth_Level), raining(raining), basic(basic), dressiness(dressiness){}

//clothing methods

string Clothing::getColor(){
    return color;
}

bool Clothing::getPattern(){
    return pattern;
}

int Clothing::getWarmth(){
    return warmth_Level;
}

bool Clothing::getRaining(){
    return raining;
}

int Clothing::getDressiness(){
    return dressiness;
}

string Clothing::getType(){
    return type;
}

string Clothing::getName(){
    return name;
}

//subclass constructors + methods 

Top::Top(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string sleeve_length)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      sleeve_length(sleeve_length) {}

string Top::getSleeveLength(){
    return sleeve_length;
}

string Top::itemDescription(){
    string desc = "This top is: ";
    desc += getColor();
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";
    desc += ", with a warmth level of " + to_string(getWarmth());
    desc += ", and is " + sleeve_length;
    desc += " sleeved,";

    return desc;
}

Bottom::Bottom(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, bool shorts, bool skirt)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      shorts(shorts), skirt(skirt) {}

bool Bottom::getShort(){
    return shorts;
}

bool Bottom::getSkirt(){
    return skirt;
}

string Bottom::itemDescription(){
    string desc = "This bottom is: ";
    desc += getColor();
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";
    desc += ", with a warmth level of " + to_string(getWarmth());
    if(getShort){
        desc += " and is a pair of shorts";
    }
    if(getSkirt){
        desc += " and is a skirt";
    }

    return desc;
}

Dress::Dress(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string length)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      length(length) {}

string Dress::getLength(){
    return length;
}

string Dress::itemDescription(){
    string desc = "This dress is: ";
    desc += getColor();
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";
    desc += ", with a warmth level of " + to_string(getWarmth());
    //desc += " and is " to_string(getLength());

    return desc;
}

Coat::Coat(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string length, bool waterproof)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      length(length), waterproof(waterproof){}

string Coat::getLength(){
    return length;
}

bool Coat::getWaterpoof(){
    return waterproof;
}

string Coat::itemDescription(){
    string desc = "This coat is: ";
    desc += getColor();
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";
    desc += ", with a warmth level of " + to_string(getWarmth());
    if(getWaterpoof()){
        desc += " and is waterproof";
    }

    return desc;
}

Shoes::Shoes(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, bool openToe, bool heel, bool sneaker)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      openToe(openToe), heel(heel), sneaker(sneaker) {}

bool Shoes::getOpenToe(){
    return openToe;
}

bool Shoes::getHeel(){
    return heel;
}

bool Shoes::getSneaker(){
    return sneaker;
}

string Shoes::itemDescription(){
    string desc = "These shoes are: ";
    desc += getColor();
    if(getHeel()){
        desc += " heels, ";
    }
    if(getOpenToe()){
        desc += " open toe, ";
    }if(getSneaker()){
        desc += " sneakers, ";
    }
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";


    return desc;
}

Accessories::Accessories(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string typeAC)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      typeAC(typeAC) {}

string Accessories::getType(){
    return typeAC;
}

string Accessories::itemDescription(){
    string desc = "This accesory is : ";
    desc += getColor();
    desc += " and ";
    desc += getType();
   
    return desc;
}