#ifndef CLOTHING_H
#define CLOTHING_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Clothing{
    public:
        Clothing(string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness);
        Clothing();
        string getColor();
        bool getPattern();
        int getWarmth();
        bool getRaining();
        int getDressiness();
        virtual string itemDescription();

    private:
        string color;
        bool pattern;
        int warmth_Level;
        bool raining;
        bool basic;
        int dressiness;

};

#endif

class Top : public Clothing{
    public:
        Top(string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, int sleeve_length);
        int getSleeveLength();
        string itemDescription();
    private:
        int sleeve_length;
};

class Bottom : public Clothing{
    public:
        Bottom(string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, bool shorts, bool skirt);
        bool getShort();
        bool getSkirt();
        string itemDescription();

    private:
        bool shorts;
        bool skirt;

};

class Dress : public Clothing{
    public:
        Dress(string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string length);
        string getLength();
        string itemDescription();
    private:
        string length;
    
};

class Coat : public Clothing{
    public:
        Coat(string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string length, bool waterproof);
        string getLength();
        bool getWaterpoof();
        string itemDescription();

    private:
        string length;
        bool waterproof;
};


class Shoes : public Clothing{
    public:
        Shoes(string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, bool openToe, bool heel, bool sneaker);
        bool getOpenToe();
        bool getHeel();
        bool getSneaker();
        string itemDescription();

    private:
        bool openToe;
        bool heel;
        bool sneaker;
};

class Accessories : public Clothing{
    public:
        Accessories(string color, bool pattern, int warmth_Level, bool raining, bool basic, int dressiness, string type);
        string itemDescription();
        string getType();

    private:
        string type;
};

