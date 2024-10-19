/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"
/* #### Please don't change this line! #### */
int run_autograder();

int main() {
    auto station = Station();
    station.record("ENTER ABC1234 10:00");
    station.record("LEAVE ABC1234 12:30");
    station.setCharge(5);
    std::cout << station.getCharge() << '\n';

    /* #### Please don't change this line! #### */
    return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"
