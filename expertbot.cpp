/* 
    Code by Sydney Reis
    Date: 1/27
    Program Description:
        This program is designed to be an expert chat bot on Taylor Swift. Users can input questions on Taylor Swift and the bot has a variety of key
        words that prompt answers to different who, what, where, when questions. If the bot does not understand the input it randomly will tell the user 
        a fun fact or point them in the direction of something it does know.

*/


#include <iostream>         // for cout, cin, endl
#include <stdlib.h>         // for rand, srand
#include <time.h>           // for time (seeding rand)
#include <algorithm> 
#include <cctype> 
#include <fstream>
using namespace std;


// ----- GLOBAL VARIABLES AND FUNCTIONS ----- //

string USER_NAME = "USER";
string input = "blank";

//prints big pic of TS
string pic (){
    //cout << R"(
    return R"(
⣿⣟⠀⠀⠀⠀⣿⣜⡱⣏⢶⣫⢝⢮⣜⣣⢏⡶⣙⡮⣵⣩⢞⠶⣍⢮⣱⢣⡞⣬⠳⣜⣲⢣⡝⣣⢛⡜⣦⡙⢾⡿⣮⣗⡜⢮⡱⢎⣽⣡⣷⠾⠿⢷⣽⣰⢣⠹⣑⠮⣹⣴⠿⣟⠛⠿⢦⣗⢬⡒⣍⠳⣌⣿⠟⠛⠛⠛⢷⣮⡒⣌⢣⣣⠙⣌⡱⢃⡎⢆⠳⣌⠓⣌⢣⠜⢢⢃⠧⡱⢡⢎⢢⡑⣊⠥⡘⢤⢃⡱⢈⠴⡁⠆⡉⣿⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⢲⡝⢮⣓⡞⣮⢳⢎⡗⣏⢾⡱⣏⠶⣹⢎⡻⣜⡣⣗⡫⢞⣥⠻⡜⣥⢳⣍⠳⣍⡞⢦⣙⣾⠁⠀⠙⢿⣦⠹⣼⠟⠉⠀⠐⣦⠀⡌⠙⢷⣝⢢⢓⣿⠁⠀⠈⠳⣄⠀⠉⠳⣎⡔⢣⡿⠁⠀⠀⠀⣦⡀⠈⢳⣌⢆⢣⡹⢤⢣⢣⠜⣊⠕⣠⢋⡔⢣⠚⡥⢊⠖⣡⢃⠎⢢⠱⣈⠲⣉⠒⢆⡑⢊⠴⡁⠎⡐⣿⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⣿⢣⢞⡝⣎⢷⣊⢧⣫⢼⣙⢦⣓⢮⣛⢴⢫⣕⢣⣓⢮⡙⢧⢎⣳⢹⣌⡳⣌⡛⢦⡹⢦⣹⡿⠀⠀⠀⠀⣿⢹⡏⠀⠀⠀⢀⣈⣿⡄⠀⠀⢹⡇⢾⡇⠃⠀⣠⡶⢻⣇⠀⠀⢻⡎⢽⡇⠀⠀⣠⡾⡙⣷⠀⠀⢹⣎⠆⡵⢊⠤⣃⠎⡔⢣⠐⣌⠸⢦⣉⠜⡡⢊⡔⡉⠎⢥⠓⣌⠲⡌⡜⢢⢁⠋⡔⠱⣈⠐⣿⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⠭⡮⣝⢞⡼⡹⢆⡯⢶⡩⣎⠷⣚⡜⢮⡳⢬⡓⢮⠖⣭⢳⡚⡴⢣⢎⡵⢢⡝⢦⡙⡖⣸⡇⠀⠀⠀⣸⡟⣾⡏⠀⠀⢰⣾⣯⣿⠃⠀⠀⢸⣿⢽⡇⠀⠀⣿⣷⡿⠁⠀⠀⣸⡏⢾⡇⠀⠀⣿⠰⢩⡟⠀⠀⢸⣿⠌⡱⢊⠴⣈⠖⡌⢆⠣⢌⠡⡀⢭⠚⡉⠧⢋⠛⢊⠦⡱⣌⢢⠱⡈⢆⠊⡜⢠⠃⡔⢈⣿⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⢣⣛⣬⢳⠼⣹⢭⠺⣥⢻⡜⣣⠳⣜⣣⢝⡣⡝⢮⣙⢦⢣⡝⡼⢩⠞⣬⠓⣬⢣⠝⡦⢹⡇⠀⠀⠀⣿⡱⢹⣇⠀⠀⠈⠛⠛⠃⠀⠀⠀⢸⡏⠼⣧⠀⠀⡿⠋⠀⠀⠀⣰⡟⠌⡌⣷⠀⠀⠻⣇⡿⠁⠀⠀⢸⡟⠨⣅⠉⠦⡑⠪⠔⡩⡘⡄⢃⡉⠦⠡⡀⠑⠬⢌⡡⢆⠱⣀⠋⠤⡑⢌⠱⡈⠅⢎⡐⠄⣿⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⢣⠞⣬⢏⡾⡱⢎⡻⢴⢣⡛⡴⢫⡜⡹⢻⢷⣽⣦⡙⢎⢧⡚⣜⢣⡙⢦⢋⡆⢣⢎⡱⢹⣇⠀⢀⠀⣿⢷⡡⢻⣦⠀⠀⠀⣀⡀⢀⣀⣀⣿⠡⠣⠜⣧⣀⠀⢀⠀⢀⣴⢿⡌⣒⡰⣈⣷⡀⠀⠈⢓⡀⠀⢰⡟⣈⠱⡠⡙⠤⡑⣉⠆⡱⠐⡌⢡⠜⡰⢃⠔⢌⠒⢢⡐⢌⠒⡄⡉⢒⠡⢊⠔⡡⠊⢆⠰⠀⣿⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⢣⠟⣜⠾⣰⣋⢧⡝⢶⣃⡹⡌⢧⡘⣡⠇⣰⢏⡻⠽⣎⡦⡙⣬⢣⠹⣘⠶⣌⠣⣛⣯⢱⣟⣷⡈⢷⡟⣿⣿⢄⣿⡿⣷⣤⣿⣿⡿⠉⣿⣏⣆⠱⣈⡿⠻⣧⣾⢰⡿⠛⢾⣿⣿⡷⣿⣫⡝⣿⠴⣾⠉⣷⣾⣷⣤⣣⠐⡡⢂⠱⡀⢎⡐⡑⢌⠢⡘⠰⡈⠜⡠⢃⠒⡌⠢⡑⢠⢃⡉⠆⡡⢊⠔⣉⠢⡁⠂⣿⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⣿⢣⣛⣬⢳⢣⣽⣻⡼⢳⠫⡵⡙⢣⠼⣀⡐⠻⣦⣵⢩⠜⣰⡑⢦⡩⢳⡑⢎⡔⢣⠜⡋⢾⣯⠈⠳⠾⢷⡾⠿⢚⠻⠿⢿⡇⠻⠛⠳⢀⣿⠛⢋⡐⣼⠃⠀⠻⠇⣾⡛⠒⠘⢿⡝⠃⠛⠻⠁⣿⠁⠙⠓⢻⡿⠉⠿⠇⠠⠑⠌⢢⠑⢂⡐⢌⠂⠱⣈⠱⡈⠌⡑⢂⠥⢈⠱⡈⢆⠰⢀⠣⠐⠢⠌⡄⠒⠠⠁⣟⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⢆⡳⢬⣣⢓⠾⢿⢋⣇⢳⡱⣙⢣⢚⡝⡻⢶⠶⢖⠪⡜⡱⢌⢣⡜⣡⠚⡤⢊⡕⢪⡑⠌⣿⡀⠀⠀⢺⡷⠈⠆⠒⡠⣸⠇⠀⠀⠀⣼⠃⡈⠄⣸⡏⠀⠀⠀⣾⢋⢹⣆⠀⠀⢻⡄⠁⠂⢱⡟⠀⠀⠀⣾⠃⡐⠤⠈⠔⡉⠌⠢⠌⢂⠰⢀⢉⠒⠠⢁⠆⡘⡀⠃⠤⠁⢆⠡⡐⠨⢄⠁⠩⠐⠂⡔⠉⡄⠁⣯⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⡌⢷⡩⢶⡩⢞⣡⠞⣬⢣⡓⣬⠣⢏⡴⡙⢦⠛⡬⡱⢡⡙⡌⢦⡘⢤⡙⠤⢣⠌⡥⡘⠰⢸⡂⠀⠀⠘⣿⠈⢂⠡⢐⡿⠀⠀⠀⢠⡿⠀⠰⢀⢸⡇⠀⠀⣸⠋⠄⣸⡏⠀⠀⢸⡗⡈⠂⣼⠁⠀⠀⢸⡇⠀⠆⡐⢉⡐⠠⠉⡐⢁⠂⠆⡁⢊⠰⠡⠈⡄⠡⠘⠠⡁⠩⡀⠆⢁⠒⠈⠔⡁⠂⠡⡀⠃⠄⠀⣧⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⡘⢧⣙⢦⣹⢚⡴⢋⡖⡱⢎⡖⡹⣒⠲⣙⠦⡛⡔⣑⠣⡜⣑⢢⡑⢆⡙⠦⣁⠎⡔⠡⠃⢼⡁⠀⠀⠀⣿⠀⠢⠐⣺⠃⠀⠀⠀⣸⠃⠀⠀⠀⢸⡇⠀⠀⢿⣰⠾⠋⠀⠀⢀⡼⢃⠴⣡⡏⠀⠀⠀⣾⠀⠘⠀⠐⠠⠀⠅⠂⠄⠃⡈⠄⡐⠂⢁⠂⠡⢀⠃⡁⠡⢄⠡⢀⠒⡆⠢⢡⢀⠐⠡⢁⠐⡈⠄⠂⡧⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⣿⠻⣄⠻⣄⢇⡛⢤⡛⠼⣃⠇⡜⣣⡘⠧⣘⠤⢣⡸⣀⠧⠸⣀⠇⡸⢄⠸⢃⡄⠜⡠⢛⠠⢸⡇⠀⠀⠀⣿⠀⡃⠀⢿⡀⠀⠀⠀⡟⢀⣠⣼⢿⠿⣿⡄⠀⠀⠛⠃⠀⠀⠀⣸⣧⢛⡤⣛⣧⠀⠀⢀⣿⠀⡀⠃⠘⠀⠃⢀⠃⠄⠠⠀⠄⠠⠘⢀⠸⠀⠄⠠⠃⠄⡀⠄⡀⠄⠀⢠⠀⡀⠠⠀⡀⠄⠠⠀⠀⡧⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⠱⡎⡽⡘⣎⠵⢪⡙⣖⠩⢎⡱⢆⡙⡲⢩⠜⡡⢆⠥⣊⠕⠢⡜⢡⠊⢆⡡⠘⣂⠱⡈⠒⠠⠹⢦⣀⡴⠟⠀⠂⠄⠀⠻⣦⢀⣴⡿⢻⣭⣿⣿⣷⣿⣿⣦⣄⣀⢀⣠⣤⣾⣿⣿⣿⣾⣿⣿⣧⣄⢰⠇⠀⠀⢁⠀⠈⠐⠀⠄⡈⠠⢁⠈⠄⢁⠂⠄⡁⠈⠄⡁⢂⠐⠠⠀⠌⡘⠃⠈⠄⠀⠐⠀⠌⠀⡁⠀⡗⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⢱⢩⢖⠳⣌⡛⢤⡓⡬⢓⢎⡱⢊⡜⡱⢂⡎⡱⢊⡒⠬⣌⠱⡘⢂⠜⠤⡘⡁⠆⡡⠘⠨⡐⠀⡄⠉⡀⠄⠂⠀⠀⠀⣠⡶⣟⣵⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣆⠀⢀⠈⠀⠂⠠⠀⠐⡀⠈⡀⢀⠈⠄⡀⠁⢂⠐⠀⠂⢁⠠⠀⢀⠐⠠⢀⠐⠁⢈⠀⠂⡀⠀⡗⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⣿⠌⠧⣎⠳⡜⣜⢢⡱⢡⡋⢦⡘⢥⠒⣅⠣⢒⡅⢣⢘⠰⡠⢃⠔⠣⡈⠆⡡⠘⢠⠡⠉⢄⠠⠁⠄⡐⠠⠀⠀⣄⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠠⠀⠀⠀⠐⠀⡀⠀⠄⠀⢈⠀⠠⠐⠀⠂⠁⡀⠂⠐⠀⠂⠀⠂⠀⡀⠀⡀⠀⠁⠀⠀⡕⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⡘⡣⢎⢳⣉⠖⣢⢑⠣⡜⡰⡘⢤⡉⠦⡉⠦⡘⢡⠊⠔⡡⠌⠌⠤⡁⠎⠐⠡⠂⠄⠃⠄⠠⢁⠐⢀⠀⢠⣿⢟⣻⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠠⠀⠀⠀⠂⠀⠀⠐⠀⠀⠄⠀⠀⠂⠀⠀⠀⠀⠀⠄⠀⠅⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⡐⢧⡙⢦⢌⠫⣄⢋⠦⢱⠱⡘⠆⡜⠤⡙⢄⠣⠂⢍⠢⠑⡈⠆⡡⠄⡉⠌⠄⠡⠈⡐⠈⠄⡀⠈⠀⣴⡿⡱⣾⣿⣿⣞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⣿⣻⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠁⠀⠀⠄⠀⠀⠀⠀⠀⠀⠂⠀⠄⠀⠀⠀⠀⠀⠊⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⠘⢦⡙⠆⣎⠳⡀⢏⡸⢡⠒⢥⠚⠠⠓⡌⢂⠥⢉⠢⠌⡑⠤⠑⡀⠆⡐⢈⠠⢁⠂⠄⠈⢀⠀⠠⢀⣿⢗⣹⣿⣿⣿⣿⣿⣿⣿⡟⡻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣽⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⣿⢉⠦⣙⠲⡌⢣⢉⠦⠱⣁⠚⡄⢎⠑⡊⠔⢡⠊⡐⢀⠒⣀⠂⠒⡀⠂⠄⠂⡐⠀⠄⠂⠈⠀⠀⠐⣘⣿⢬⣿⣿⣿⣿⣿⣿⣿⣿⣥⠓⢌⠢⢍⠛⡹⢛⠿⣿⣿⣿⣯⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⣿⢈⡓⣌⢒⢩⠒⡌⢎⠱⣈⠒⡌⢢⠘⢄⠣⠄⢃⡐⠌⡐⠠⠈⠄⠠⢈⠐⠀⠄⠠⠀⠂⠁⠀⠀⠀⣸⡇⢺⣿⣿⣿⣿⣿⣿⣧⣶⣽⣷⣶⡷⢆⡘⢠⢃⡜⢦⣿⡽⣿⢻⣟⢿⡿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⠠⡓⢌⢎⢢⠓⡌⡌⠒⡄⢣⠘⠤⢉⠄⢂⠉⡄⠰⠀⡀⢂⠁⠂⠁⠄⠂⠈⠀⠀⠁⠀⠀⠀⠀⣠⡿⠀⣿⣿⣿⣿⣿⣿⣟⢫⣍⣹⣿⣿⣿⣮⡐⠐⣪⣜⣷⣾⡱⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⠐⡩⢌⠲⣈⠱⢠⢉⠒⢌⠢⠉⠔⡨⢀⠊⡐⠠⢁⠐⠠⠀⡈⠀⠡⠀⠀⠁⡀⠀⠀⠀⠀⠀⠀⠏⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠰⣡⣿⡿⣇⠳⡹⢧⡛⣿⢿⠿⣿⢿⣯⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⠈⡕⠬⡑⢌⡘⢂⠅⢎⡐⠂⡑⢈⣀⣦⡔⢀⠁⠂⠄⠂⠁⡀⠌⠀⡀⠁⠀⠀⠀⠀⠀⠠⠀⠂⠀⠀⠀⠠⣿⣿⣿⣿⣿⠟⣟⣫⣍⣯⣽⠿⠁⠠⢣⢱⡿⣿⣄⠫⡑⢳⡙⢎⡍⢻⡔⣫⢞⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⣿⠐⡅⠪⡅⠢⢘⠠⢊⠔⢠⣡⣶⣿⣿⠟⠀⡀⢊⠐⠀⢁⠠⠀⢀⠀⠀⠀⠄⠀⢀⠀⠀⠀⠀⠄⠂⠀⠀⢠⣿⣿⣿⣿⡿⠐⠈⠉⠉⠉⠀⢀⠠⠁⣆⢯⣿⢲⢿⠢⢍⢢⡑⢎⡜⢣⠞⣧⡻⢾⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢉⡀⠑⠂⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⠐⡌⢡⠰⣥⢦⡘⠠⣼⢟⠫⣷⠟⠁⠠⠐⠠⢀⠀⠐⠀⠀⠐⠀⡐⠈⠀⠀⠂⠀⠀⠀⠀⠌⣌⠡⣀⣴⣿⣿⣿⣿⣿⠁⠀⠀⠀⠂⢀⠐⣼⣷⣹⣾⣿⣾⣯⢾⡯⢆⢧⡘⢦⡚⢧⡻⣼⢿⣏⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠂⠄⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⠐⡌⢢⠘⢿⣤⣈⠁⡿⡈⣽⠟⠀⠀⢁⠐⠀⠂⠀⠂⠈⠀⠀⠄⠀⠀⠠⠀⠀⠀⠀⡀⠂⠠⣰⣿⣿⡿⣿⣿⣿⣿⣿⢀⠨⠀⡀⠰⡨⠜⠻⡟⢻⣿⣿⢟⡻⢏⠿⡜⢮⡙⣶⡹⢧⣻⢷⣻⣿⣞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠌⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⠠⠑⠢⠌⡈⢿⣿⡏⢇⣱⡟⠀⠀⠐⠠⠈⠀⠄⠁⠀⠀⠀⠀⠀⡀⠈⠀⠀⠀⠀⢀⣀⣴⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣐⠢⠡⡌⣷⣽⠇⢐⣠⣃⣜⣴⣮⢶⣭⣚⣭⠳⣝⡲⣽⢯⣛⡾⣽⣿⣿⣿⣿⣯⣿⢿⣿⣿⣻⣽⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⣿⠀⢍⠰⣰⡾⢿⡻⠟⠾⢛⠀⠀⠐⠂⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⢀⠈⢀⣤⡾⢛⣽⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⢑⢣⢾⣿⣣⣶⣿⣿⣿⣿⡿⢾⠿⣿⢿⣷⣿⣜⣷⡟⢬⡳⣽⣳⢿⣿⢺⣿⣿⣿⣿⣿⣷⣛⣾⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⣿⠈⠆⡂⠤⡐⠠⠐⡘⠂⠌⠴⠀⠀⠀⠡⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⢠⣾⢻⣼⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡌⣆⣛⡟⣿⣿⣿⣉⣀⣀⣀⣠⣶⣴⣿⣿⢿⡻⣱⢎⣣⣿⢶⣫⣿⢏⣾⣳⣿⣿⣿⣿⢿⣷⣯⢿⣽⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⣿⠀⡒⠡⠒⡈⢡⠠⠄⠡⢀⠀⠐⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠟⠁⣰⣿⢫⣽⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣗⠮⡙⠻⠏⢛⣿⡿⣿⢿⡿⣟⡿⣛⣯⣟⢧⡳⣿⢂⣽⣟⡮⣽⣿⠸⣷⣿⣿⣿⣿⢯⡻⣿⣿⣿⣮⣟⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⣿⠀⠢⢁⠣⠐⠠⠐⡈⠐⡀⢈⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⣼⡿⣋⣾⣿⣟⠃⣻⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⡗⢬⡁⢃⠀⠻⣿⣾⡽⣾⣽⣷⢿⡻⣝⢮⣿⢃⢾⣿⢧⣻⡯⣽⢓⡿⣾⣿⣿⣿⢣⠱⣿⣿⣿⣿⣾⡽⣻⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⡿⠀⠅⢂⠡⢈⠂⠐⠠⢁⠀⠀⠄⠀⡀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣟⣱⣿⣿⡿⢁⢰⣿⡿⣝⡷⣿⣿⣿⣿⣿⣿⣿⣿⣦⡑⢂⠀⠂⠰⠘⠚⠋⠩⠑⢪⠑⡎⢶⡩⣾⣿⣯⣟⣿⡷⣹⠮⣽⣿⣿⣿⣿⣧⣓⣿⣿⣿⣿⣿⣿⡵⣯⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⡟⠀⡅⢨⠐⡀⠊⠠⢁⠀⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣟⣾⢿⣿⠟⠁⢢⣿⣿⣹⢯⣟⣷⣿⣿⣿⣿⣿⣿⣿⣿⣞⡤⢂⠀⠀⠀⠀⠀⠀⠈⡄⢳⣜⣿⣽⣿⣟⣾⣿⢿⣿⡡⣿⢿⣿⣿⣿⣿⠿⣜⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⡯⢀⠐⡀⠂⠄⠡⢀⠣⡄⠀⠂⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⣩⡿⠋⠀⠄⣿⣿⢶⣻⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣴⣀⠲⣌⢦⣡⢳⣜⣷⣿⣿⣿⣿⣿⣿⢭⡿⣿⢥⣻⣿⣿⣿⣿⣣⠙⡬⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣇⠀⠀⠀⠀⡗⠀⡂⠌⡐⠈⠡⢀⠐⠨⠆⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⣿⣿⣛⣥⡾⠛⠀⠀⠀⢐⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣷⣿⣿⣿⣿⣿⣿⣿⡟⡼⣷⡟⣽⣖⣿⣿⣿⣿⣿⣧⢛⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣇⠀⠀⠀⠀⣏⠀⠄⠂⠄⠡⢀⠀⠌⡁⠸⡁⠀⠐⠀⠀⢠⣼⣿⣿⣽⣿⠿⠛⠓⠛⠉⠀⠀⠀⢀⡤⠊⢻⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⢿⡿⣿⣿⢿⡯⣷⣿⡯⢼⣿⣿⡹⣿⢽⣿⣿⣿⣿⣽⣿⢟⠻⡙⢍⠛⠻⠿⢿⠿⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡇⠀⠀⠀⠀⡇⠠⠈⡐⠁⢂⠠⠀⠀⡇⠀⡱⠀⠀⠀⣠⣿⡿⠟⠋⠁⠀⠀⠈⠀⠀⠀⠀⣀⣤⠞⠁⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡜⣯⢻⡳⢯⣟⡾⣹⠿⣡⢻⣿⣿⢱⣿⠎⣿⣿⣿⠟⣿⣷⢊⠔⠡⠊⡌⠱⢌⢢⡙⣶⣾⣝⣟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⠇⠀⡁⠄⡡⢀⠠⠐⢠⡗⠠⢱⠀⠒⠀⣾⣿⡧⠜⡁⠓⣄⠒⡚⠛⠑⠲⠞⠉⠀⠀⢀⣴⣿⢻⡽⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⢣⢟⡻⣌⢳⣍⢳⡔⣫⢿⣿⣸⠏⣶⣿⡿⠁⠀⠀⠉⠈⢀⡁⠂⢌⠱⣈⢆⠳⣔⠪⣟⡿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⠅⠀⠐⠂⣅⠀⠄⠂⢰⣿⢰⡏⢀⠁⢠⣿⣿⠃⣄⡶⠟⠋⠙⠙⠻⢶⣦⣄⣀⣠⣴⠿⣽⡮⣷⣻⢳⣯⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⢦⡊⡵⣊⠷⣌⢳⡜⣹⢎⣿⡜⢣⣿⡟⠀⠀⠀⠀⠀⠀⠄⠀⡈⠄⠒⡈⢆⡓⣌⠳⣌⠿⣏⠿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⡁⠀⠂⠄⠠⠑⠂⢬⣤⣿⣿⣗⣎⣾⣿⣿⣧⡿⠏⠐⠂⠂⠁⠐⠀⠀⠄⠈⣽⡿⣏⣿⠋⠔⣹⣯⡷⣹⢯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠳⡵⣃⠞⣬⠳⣌⢧⢻⣿⡇⣽⡿⠀⠀⠀⠀⠀⠀⠀⠄⠤⠀⠌⡡⠐⠆⡘⠦⡹⣌⢯⡹⣿⡞⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⡃⠀⠀⠀⠂⠀⠀⠀⠀⠈⠙⠻⠿⠛⠋⠁⠀⠀⠀⠀⠀⠄⠂⠀⠠⠀⠄⣾⣿⣱⣾⢡⢐⡼⣱⢻⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡍⢷⡩⢫⠔⣙⠾⣐⠏⣼⡗⣉⠁⠀⠀⠀⠠⢀⠂⠄⠠⠀⠌⡐⠠⢉⠢⠑⢬⠱⡌⢶⡱⢭⢿⣾⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⠃⠀⠀⠁⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡟⠁⣼⡏⢲⠛⣶⣿⢻⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⣿⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠂⣷⠉⣮⢱⡎⣴⠉⠛⠁⣾⠀⡄⠀⠑⢠⠂⠂⠈⠐⠀⠂⡄⠁⠂⢰⠉⢢⠑⠘⢣⡝⢺⡜⣮⡝⢻⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⠂⠀⠀⠀⠂⠀⠀⠁⠀⠈⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡟⢡⢂⣼⣤⠆⠡⢌⣤⣿⣿⣿⣿⡿⠛⠉⠉⠉⠉⠀⣿⡟⣿⡇⢈⠡⠀⠈⠉⠛⠛⠻⢿⣆⠰⡙⢦⠣⡜⣀⢺⠃⣽⣿⠠⠑⡀⢡⠊⡈⠄⢃⠄⢃⠐⠠⢁⠘⡠⠘⢄⠫⡕⠪⣕⢫⡜⣶⡹⢏⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡗⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠂⠀⠀⡐⠀⠀⠀⠀⠀⠐⠀⠂⠔⠠⠄⣄⣠⣠⣴⣟⣁⢃⡾⠋⢀⣠⣶⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⢀⣾⠟⣃⠆⠀⠀⣄⠀⠀⠀⠀⠀⠀⠀⢸⣧⠘⣄⠓⡌⣰⠏⣸⣿⣿⡇⡘⠰⡀⠑⢢⠉⡄⢊⠄⡈⡐⢀⠂⡁⠎⠰⢠⢉⠳⡌⢧⣝⠲⣝⡏⣾⢹⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⠀⠀⠀⡀⠀⠁⠀⠀⠀⡀⠐⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⢀⣈⠩⡙⠿⣿⣿⣦⣶⣿⣿⣯⣽⡿⠋⠁⠀⠀⠀⠀⠀⠀⣠⡞⢣⠐⠄⠀⠀⣰⣿⠀⠀⠀⠀⠀⠀⠀⡀⣿⠀⣈⠒⣰⡟⢠⣿⡯⠿⠃⢌⠡⢘⡀⢃⢂⡐⠢⠘⢠⠐⠂⢌⠐⡄⢃⠆⣉⠖⣩⢒⡼⣛⣬⢳⡭⡳⡽⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠄⠀⠂⠠⠐⠀⠀⠀⠀⠀⠂⢀⣈⣠⣜⡲⠶⠷⠾⠷⠿⠟⠛⠛⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠠⠞⠋⣸⡏⠀⠀⠀⠀⣿⣧⠀⠀⠀⠀⠀⣠⡾⠇⠸⡇⠀⣴⡟⢠⣿⣿⢇⠃⢡⠂⠐⠂⠄⡡⢊⠐⡡⢊⠔⡈⢡⠂⢌⠐⡨⠰⢌⠲⣑⢎⡲⡱⢎⣧⢳⡝⣵⢻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣇⠀⠀⠀⠀⠀⠀⠀⠠⠀⢀⠀⠀⠀⠠⠈⡀⠄⠠⢄⠒⠛⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⠀⠀⠀⠀⠀⠘⣿⣦⣀⣤⡴⣫⠙⠁⠀⠀⣿⢠⡟⢈⣿⣿⡯⠌⠐⠀⠃⡀⠈⠐⢀⠢⠘⠤⣁⠢⢘⠠⠌⢠⠊⡔⡑⢊⠵⣈⢦⠳⣍⢳⢬⡓⡾⢥⣛⢿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣇⠀⠀⠀⠀⠀⠀⠀⠠⠀⢀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⠀⠀⠀⠀⠀⠀⠀⠀⠙⠋⠉⠉⠀⠀⠀⠀⠀⢾⡿⠁⣾⣿⣿⠅⡈⠐⡀⢀⠉⠀⠁⠆⠄⢉⡐⠠⠘⣀⠣⡈⢆⠒⠤⢉⢆⡣⠜⡦⢛⡬⢏⡶⡹⢵⢫⡞⣭⢿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣇⠀⠀⠀⠀⠀⠀⠀⠄⠁⡀⠂⠐⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⣾⣿⣿⠇⡐⠠⠁⠀⠄⢂⠡⠀⠈⡐⢂⠠⢡⠁⢆⠢⢁⠢⡘⢢⠍⢦⠱⣩⢚⡵⣪⠝⡴⣫⠝⣮⡹⡼⢭⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡧⠀⠀⠀⠀⠀⠀⠐⡀⠂⢀⠠⠀⠂⡀⠀⢀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠁⣾⣿⣿⠋⡀⠠⠀⡐⠂⠀⡀⠂⡐⠂⡐⠠⡘⢠⢉⠄⡊⠔⡡⢘⡡⠚⡤⣛⢤⣋⠶⣱⢫⢖⣣⢛⡴⢫⣝⡳⣞⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⡏⠀⠀⠀⠀⠀⠀⠠⢀⠡⠀⠄⠀⠂⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⢃⠐⡀⢂⠐⢀⠀⠂⠠⠐⡀⡐⠠⠐⡀⠂⠌⡐⠄⣃⠰⢁⠰⢩⠔⡱⢢⡍⢶⡡⢏⡜⡲⣍⠞⡳⣜⢳⡭⣞⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣟⠀⠀⠀⠀⠀⠀⠐⡀⠂⠁⠌⠐⠀⡈⠀⠀⠈⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⣿⢏⠠⢀⠐⠠⢈⠠⠈⠄⠡⠈⡐⢠⢁⠂⡐⢉⠐⡈⠔⠠⠒⡈⠆⠣⠜⣡⠳⡸⣡⠛⡬⢎⡕⢎⡹⡱⢎⡳⢞⡱⣞⣿⡄⠀⠀⠀⠀⠀⠀⠀
⣿⣟⠀⠀⠀⠀⠀⠀⠐⠠⠈⠄⠂⡀⢁⠀⠠⢀⠠⠁⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⣿⢂⠀⠂⠐⠀⠄⠂⠤⢈⠂⠡⠄⠃⡄⠣⠄⠂⠰⠈⠔⠡⠑⠌⠌⡑⢊⠤⢣⠑⠦⡙⡔⠣⡜⢌⠲⣉⠮⡱⢏⡳⣍⢾⣿⡄⠀⠀⠀⠀⠀⠀
⣿⡿⠀⠀⠀⠀⠀⠢⠈⠀⡁⠂⠁⠀⠂⠠⠁⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣦⣠⣔⣤⣦⣨⣤⣔⣀⣄⣐⣌⣰⣠⣥⣢⣁⣂⣥⣬⣦⣥⣬⣴⣬⣦⣼⣦⣽⣶⣵⣬⣵⣬⣦⣵⣤⣷⣷⣮⣵⣾⣿⣿⣿⡆⠀⠀⠀⠀⠀
⣿⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣦⡀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼
⣿⣿⣿⣿⣶⣶⣴⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣦⣶⣶⣿⣿)";
}

// random number generator function
int random(int min, int max){
    return rand() % (max - min + 1) + min;
}

//function to print out bot name
void bot_name(){
    cout << "[SwiftieBot]: ";
}

//function to return the users input text
string user(){
    cout << "[" << USER_NAME << "]: ";
    getline(cin, input);
    return "[" + USER_NAME + "]: ";

}

//function to print fun fact 1
string fun_one(){
    return "Taylor Swift's Eras Tour is the highest grossing tour of all time.";
}

//function to print fun fact 2
string fun_two(){
    return "Taylor grew up on a Christmas tree farm ! Who knew !";
}

//function to print fun fact 3
string fun_three(){
    return "Taylor loves to drop Easter Eggs (little clues) for her fans about things like when her next album will drop or tour dates!";
}

//function to print fun fact 4
string fun_four(){
    return "Taylor appears in the hit movie Valentines Day as Taylor Lautner's love interest.";
}

// function that either prints out a random fact or prompts a user to ask about something else when input is not understood
string unclear_input(int num){
    string one = "Hmmmmmm.... I am not sure about that, but what I am sure about is that ";
    if (num == 1){
        return one + "you should ask me about the Eras Tour!";
    }
    else if(num == 2){
        return one + "you should try asking me about Taylor's best songs (I have lots of thoughts)";
    }
    else if (num == 3){
        return one + fun_one();
    }
    else if (num == 4){
        return one + fun_two();
    }
    else if (num == 5){
        return one + fun_three();
    }
    else{
        return one + fun_four();
    }
}


string worst_song(){
    return "Trick question-- there is none!";
}

string next_album(){
    return "It is unsure when Taylor's next album will come out. Fans should expect a drop likely within the next two years!";
}

//function to print information about Taylor swifts albums
string what_albums(){
    return "Taylor Swift has released 12 albums. The most popular among these being 1989, Red, and Fearless !! Here is the spotify link to Red if you wanna check it out (or are like me and want to listen for the millionth time...) https://open.spotify.com/album/1EoDsNmgTLtmwe1BDAVxV5";
}

//function to print what genre Taylor Swift Sings
string what_genre(){
    return "Taylor began her career as a country singer and over time has explored many other genres like pop and alternative.";
}

//function to print most popular songs and a link to my favorite song
string what_song(){
    return "Taylor has had so many amazing songs throughout her career. While it is a matter of personal opinion her most popular songs are Shake It Off and Love Story. Attatched is the link to my creator's favorite song. https://www.youtube.com/watch?v=tNxUxm3-658";
}

//function to print her hobbies
string what_hobbies(){
    return "In Taylor's free time she enjoys baking, spending time with friends, and of course hanging with her cats. Her chai cookies are pretty infamous... so here's the link to the recipe: https://joythebaker.com/2021/11/taylor-swifts-chai-sugar-cookies/";
}

string what_birthday(){
    return "Taylor's birthday is December 13, 1989";
}

//function that prints the release date period for her albums
string when_release(){
    return "Taylor released her first album in 2006 and his been steadily releasing albums to the current day !";
}

//function that prints when the eras tour was and gives some extra info too
string when_tour(){
    return "The Eras tour spanned from 2023-2025 ! Here is a bonus link to my favorite surprise song: https://www.youtube.com/watch?v=5uyAcPe1EC8 ";
}

//function that prints her birth year
string when_born(){
    return "Taylor was born in 1989.";
}

//prints the year of the infamous kanye incident
string when_kanye(){
    return "Ahhhh yes, the famous Kanye Taylor controversy (he was so wrong for that) was in 2009 when Taylor Swift was a mere 19.";
}

//prints where taylor was born
string where_born(){
    return "Taylor was born in Pennsylvania.";
}

//prints where taylor lives
string where_live(){
    return "Taylor has many houses all across the country, but she says her favorite house is her coastal home in Rhode Island.";
}

//prints where taylor will be married
string where_married(){
    return "Taylor is getting married this summer at her Rhode Island home.";
}

//prints where taylor likes to write music
string where_write(){
    return "Taylor writes her music in a variety of low key places, from her bed room floor to quiet rooms tucked away in her studio. Check out this video of her and her producer writing Getaway Car!!! https://www.youtube.com/watch?v=O10QP1tRTF4";
}

string who_TS(){
    return "Taylor Swift is a famous American singer songwriter!";
}

//prints who taylor is engaged to
string who_engaged(){
    return "Taylor is currently engaged to football star Travis Kelce.";
}

//prints who some of Taylor's more notable exes are
string who_exes(){
    return "Taylor has had many notable exes among them are Jake Gyllenhaal, Harry Styles, Joe Alwyn, and Taylor Lautner.";
}

//prints who inspires taylor's songs
string who_inspiration (){
    return "Most of Taylor's songs cover the theme of love and the loss of love. That being said often her inspiration is either current or prior boyfriends.";
}

//prints who Taylor is friends with
string who_friends(){
    return "Taylor's best friends are Blake Lively and Gigi Hadid.";
}

// ----- MAIN FUNCTION ----- //

int main(){

    srand(time(NULL)); // seed the random number generator (so that it's different each time)

    bot_name();
    cout << "Hey I am SwiftieBot the expert on all things Taylor Swift, what's your name!" << endl;

    cout << "[USER]: ";
    getline(cin, USER_NAME);

    ofstream outfile(USER_NAME + ".txt");
    outfile << "[SwiftieBot]: Hey I am SwiftieBot the expert on all things Taylor Swift, what's your name!" << endl;
    outfile << "[USER]: " << USER_NAME << endl;

    bot_name();
    cout <<"It is so nice to meet you " << USER_NAME << " ask me anything about our girl Tay Tay... or type exit to leave" << endl;
    cout << "But for the most accurate responses try asking me who, what, where, and when questions!" << endl;
    outfile << "[SwiftieBot]: It is so nice to meet you " << USER_NAME << " ask me anything about our girl Tay Tay... or type exit to leave" << endl;
    outfile << "But for the most accurate responses try asking me who, what, where, and when questions! Like: Where does she live? When was she born? What genre is her music?" << endl;


    //while the user does not wish to exit the program this loop runs
    while(input != "exit"){
        //user();
        outfile << user() << input << endl;

        //takes the input of the user and puts it all in lowercase
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        //checks the input for a series of keywords and if certain keywords are found corresponding functions are called
        if ((input.find("albums") != string::npos) && (input.find("what") != string::npos)){
            bot_name();
            cout << what_albums() << endl;
            outfile << "[SwiftieBot]: " << what_albums() << endl;
        }

        else if((input.find("genre") != string::npos) && (input.find("what") != string::npos) || (input.find("type") != string::npos) && (input.find("what") != string::npos)){
            bot_name();
            cout << what_genre() << endl;
            outfile << "[SwiftieBot]: " << what_genre() << endl;
        }

        else if((input.find("best song") != string::npos && (input.find("what") != string::npos))|| (input.find("popular song") != string::npos && (input.find("what") != string::npos))){
            bot_name();
            cout << what_song() << endl;
            outfile << "[SwiftieBot]: " << what_song() << endl;
        }

        else if(input.find("what") != string::npos && input.find("hobbies") != string::npos){
            bot_name();
            cout << what_hobbies() << endl;
            outfile << "[SwiftieBot]: " << what_hobbies() << endl;
        }

        else if(input.find("what") != string::npos && input.find("worst song") != string::npos){
            bot_name();
            cout << worst_song() << endl;
            outfile << "[SwiftieBot]: " << worst_song() << endl;
        }

        else if((input.find("birthday") != string::npos && (input.find("what") != string::npos))|| (input.find("birthday") != string::npos && (input.find("when") != string::npos))){
            bot_name();
            cout << what_birthday() << endl;
            outfile << "[SwiftieBot]: " << what_birthday() << endl;
        }

        else if(input.find("release") != string::npos && (input.find("when") != string::npos)){
            bot_name();
            cout << when_release() << endl;
            outfile << "[SwiftieBot]: " << when_release() << endl;
        }

        else if (input.find("eras tour") != string::npos && (input.find("when") != string::npos)){
            bot_name();
            cout << when_tour() << endl;
            outfile << "[SwiftieBot]: " << when_tour() << endl;
        }

        else if(input.find("kanye") != string::npos && (input.find("when") != string::npos)){
            bot_name();
            cout << when_kanye() << endl;
            outfile << "[SwiftieBot]: " << when_kanye() << endl;
        }

        else if(input.find("born") != string::npos && input.find("when") != string::npos){
            bot_name();
            cout << when_born() << endl;
            outfile << "[SwiftieBot]: " << when_born() << endl;
        }

        else if((input.find("born") != string::npos && input.find("where") != string::npos) || (input.find("from") != string::npos && input.find("where") != string::npos)){
            bot_name();
            cout << where_born() << endl;
            outfile << "[SwiftieBot]: " << where_born() << endl;
        }

        else if(input.find("live") != string::npos && (input.find("where") != string::npos)){
            bot_name();
            cout << where_live() << endl;
            outfile << "[SwiftieBot]: " << where_live() << endl;
        }

        else if ((input.find("getting married") != string::npos && input.find("where") != string::npos)|| (input.find("where") != string::npos && input.find("wedding") != string::npos)) { 
            bot_name();
            cout << where_married() << endl;
            outfile << "[SwiftieBot]: " << where_married() << endl;
        }

        else if(input.find("write") != string::npos && input.find("where") != string::npos){
            bot_name();
            cout << where_write() << endl;
            outfile << "[SwiftieBot]: " << where_write << endl;
        }
        else if(input.find("when") != string::npos && input.find("next album") != string::npos){
            bot_name();
            cout << next_album() << endl;
            outfile << "[SwiftieBot]: " << next_album() << endl;
        }
           
        else if(input.find("ex boyfriend") != string::npos && (input.find("who") != string::npos)){
            bot_name();
            cout << who_exes() << endl;
            outfile << "[SwiftieBot]: " << who_exes() << endl;
        }

        else if (input.find("who") != string::npos &&(input.find("engaged") != string::npos ||input.find("boyfriend") != string::npos || input.find("dating") != string::npos )) {
            bot_name();
            cout << who_engaged() << endl;
            outfile << "[SwiftieBot]: " << who_engaged() << endl;
        }

        else if(input.find("inspiration") != string::npos && (input.find("who") != string::npos)){
            bot_name();
            cout << who_inspiration() <<endl;
            outfile << "[SwiftieBot]: " << who_inspiration() << endl;
        }

        else if(input.find("friends") != string::npos && (input.find("who") != string::npos)){
            bot_name();
            cout << who_friends() << endl;
            outfile << "[SwiftieBot]: " << who_friends() << endl;
        }

        else if(input.find("taylor swift") != string::npos && (input.find("who") != string::npos)){
            bot_name();
            cout << who_TS() << endl;
            outfile << "[SwiftieBot]: " << who_TS() << endl;
        }

        
        else if((input.find("show me a picture") != string::npos)){
            bot_name();
            cout << pic() << endl;
            outfile << "[SwiftieBot]: " << pic() << endl;
        }

        else if (input.find("exit") != string::npos){
            bot_name();
            cout << "Bye "<< USER_NAME << " I will miss you !!!!!!!" << endl;
            outfile << "[SwiftieBot]: " << "Bye "<< USER_NAME << " I will miss you !!!!!!!" << endl;
            break;
        }

        //no keyword is found random output
        else{
            bot_name();
            string rand = unclear_input(random(1, 6));
            cout << rand << endl;
            outfile << "[SwiftieBot]: " << rand << endl;

        }
    }





    return 0;
}
// ----- END OF PROGRAM ----- //