#include "Clothing.h"

#include <iostream>
#include <string>

using namespace std;

//clothing constructor
Clothing::Clothing(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness): name(name), type(type), color(color), pattern(pattern), warmth_Level(warmth_Level), raining(raining), basic(basic), dressiness(dressiness){}

//clothing methods

string Clothing::getColor(){
    /* returns color of a clothing item
    */
    return color;
}

bool Clothing::getPattern(){
    /* returns true if a clothing item is patterned
    */
    return pattern;
}

bool Clothing::getBasic() {
    /* returns true if a clothing item is a basic
    */
    return basic;
}

int Clothing::getWarmth(){
    /* returns the warmth level of a piece of clothing
    */
    return warmth_Level;
}

bool Clothing::getRaining(){
    /* returns true if the item would be worn in the rain
    */
    return raining;
}

int Clothing::getDressiness(){
    /* returns the level of dressiness an item is
    */
    return dressiness;
}

string Clothing::getType(){
    /* returns the type of an item
    */
    return type;
}

string Clothing::getName(){
    /* returns the name of a clothing item
    */
    return name;
}

//subclass constructors + methods 

Top::Top(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string sleeve_length)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      sleeve_length(sleeve_length) {}

string Top::getSleeveLength(){
    /* returns the sleeve length of a shirt
    */
    return sleeve_length;
}

string Top::itemDescription(){
    /* returns the item description for a top
    */
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
    /* returns a serialized version of top
    */
    return "Top," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + sleeve_length;
}

Bottom::Bottom(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, bool shorts, bool skirt)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      shorts(shorts), skirt(skirt) {}

bool Bottom::getShort(){
    /* returns true if a bottom is a short
    */
    return shorts;
}

bool Bottom::getSkirt(){
    /* returns true if a bottom is a skirt
    */
    return skirt;
}

string Bottom::itemDescription(){
    /* returns the item description of a bottom
    */
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
    /* Returns a serialized version of bottom
    */
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
    /* returns a string holding the length of a dress
    */
    return length;
}

string Dress::itemDescription(){
    /* returns an item description of dress
    */
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
    /* returns a serialized version of dress
    */
    return "Dress," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + length;
}

Coat::Coat(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string length, bool waterproof)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      length(length), waterproof(waterproof){}

string Coat::getLength(){
    /* returns a string version of the length of a dress
    */
    return length;
}

bool Coat::getWaterproof(){
    /* returns true if a coat is waterproof
    */
    return waterproof;
}

string Coat::itemDescription(){
    /* returns an itemp description of coat
    */
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
    /* returns a serialized version of coat
    */
    return "Coat," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + length + "," + to_string(waterproof);
}

Shoes::Shoes(string name, string type, string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, bool openToe, bool heel, bool sneaker)
    : Clothing(name, type, color, pattern, warmth_Level, raining, basic, dressiness),
      openToe(openToe), heel(heel), sneaker(sneaker) {}

bool Shoes::getOpenToe(){
    /* returns true if a shoe is open toed
    */
    return openToe;
}

bool Shoes::getHeel(){
    /* returns true if a shoe is a heel
    */
    return heel;
}

bool Shoes::getSneaker(){
    /* returns true if a shoe is a sneaker
    */
    return sneaker;
}

string Shoes::itemDescription(){
    /* returns an item description of shoes
    */
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
    /* returns a serialized version of shoes
    */
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
    /* returns specific type of accesory
    */
    return typeAC;
}

string Accessories::itemDescription(){
    /* returns item description for accessory
    */
    string desc = "This accesory is a ";
    desc += getColor();
    desc += getType();
   
    return desc;
}

string Accessories::serialize() {
    /* returns serialized version of an accessory
    */
    return "Accessories," + getName() + "," + getType() + "," + getColor() + "," +
           to_string(getPattern()) + "," + to_string(getWarmth()) + "," +
           to_string(getRaining()) + "," + to_string(getBasic()) + "," +
           to_string(getDressiness()) + "," + typeAC;
}