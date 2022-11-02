/* CSE310
 * Homework3
 * Yuan Bo  1220397048
 *
 * unil.cpp will save the function of the "nextCommand"
 *
 * nextCommand will be the function be calling in a loop and keep ask user for next command to run the function
 *
 */


#include "util.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

char nextCommand(int &i, int &v, int &f, int &n, int &k) {
    // the bool to enter and exit the loop
    bool loop = true;
    //the char to get the user's input
    char c;
    while (loop) {

        //get user's first char input first to find the correct case to enter
        cin >> c;

        //if it's a space, tab or next line, keep looing for next input
        if (c == ' ' || c == '\t' || c == '\n') {
            continue;
        }

        //it it's s, r, w. end the loop and stop keep looing for input because these 3 command don't need any int
        else if (c == 'S' || c == 'R' || c == 'W' || c == 's' || c == 'r' || c == 'w') {
            loop = false;
        }

        //if it's c, enter the c case and find the int n.
        else if (c == 'C' || c == 'c') {
            cin >> n;
            loop = false;
            if (!cin) {
                cout << "bad value for command C" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
        }
        //if it's i, enter the i case and find the int f and k.
        else if (c == 'I' || c == 'i') {
            cin >> f;
            if (!cin) {
                cout << "bad value for command I" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            cin >> k;
            if (!cin) {
                cout << "bad value for command I" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            loop = false;
        }
        //if it's d, enter the d case and find the int f.
        else if (c == 'D' || c == 'd') {
            cin >> f;
            if (!cin) {
                cout << "bad value for command D" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            loop = false;
        }
        //if it's k, enter the k case and find the int f, i, v.
        else if (c == 'K' || c == 'k') {
            cin >> f;
            if (!cin) {
                cout << "bad value for command K" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            cin >> i;
            if (!cin) {
                cout << "bad value for command K" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            cin >> v;
            if (!cin) {
                cout << "bad value for command K" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            loop = false;
        }
        //if user enter anything not coverd, consend it as an invalid command, print out the error message and return.
        else {
            std::cout << "Invalid Command" << std::endl;
            loop = false;
        }
    }
    //return the char c befure function end.
    return c;
}