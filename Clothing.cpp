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

bool Clothing::getBasic() {
    return basic;
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
    string desc = "This top is ";
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

string Top::serialize() {
    return "Top," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + sleeve_length;
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
    string desc = "This bottom is ";
    desc += getColor();
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";
    desc += ", with a warmth level of " + to_string(getWarmth());
    if(getShort()){
        desc += " and is a pair of shorts";
    }
    if(getSkirt()){
        desc += " and is a skirt";
    }

    return desc;
}

string Bottom::serialize() {
    return "Bottom," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," +
           to_string(shorts) + "," + to_string(skirt);
}

Dress::Dress(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string length)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      length(length) {}

string Dress::getLength(){
    return length;
}

string Dress::itemDescription(){
    string desc = "This dress is ";
    desc += getColor();
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";
    desc += ", with a warmth level of " + to_string(getWarmth());
    //desc += " and is " to_string(getLength());

    return desc;
}

string Dress::serialize() {
    return "Dress," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + length;
}

Coat::Coat(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string length, bool waterproof)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      length(length), waterproof(waterproof){}

string Coat::getLength(){
    return length;
}

bool Coat::getWaterproof(){
    return waterproof;
}

string Coat::itemDescription(){
    string desc = "This coat is ";
    desc += getColor();
    if (getPattern())
        desc += ", and patterned";
    else
        desc += ", and solid";
    desc += ", with a warmth level of " + to_string(getWarmth());
    if(getWaterproof()){
        desc += " and is waterproof";
    }

    return desc;
}

string Coat::serialize() {
    return "Coat," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + length + "," + to_string(waterproof);
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
    string desc = "These shoes are ";
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

string Shoes::serialize() {
    return "Shoes," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," +
           to_string(openToe) + "," + to_string(heel) + "," + to_string(sneaker);
}

Accessories::Accessories(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string typeAC)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      typeAC(typeAC) {}

string Accessories::getType(){
    return typeAC;
}

string Accessories::itemDescription(){
    string desc = "This accesory is a ";
    desc += getColor();
    desc += getType();
   
    return desc;
}

string Accessories::serialize() {
    return "Accessories," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + typeAC;
}