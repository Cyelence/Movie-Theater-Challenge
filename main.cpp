//prioritize earlier reservation identifiers, so those guests will get better seats
//Ex: R001 is identifer, 2 is the # of seats needed
//each identifier can be seated next to each other, since they're in the same group
//each separate identifer group must be seated at least a row or 3 seats apart
/*
priority of seats: 
seats near the middle are the best
seats towards the back
seats towards the front
*/

#include <iostream>
#include <fstream>

#include "Seating.h"

using namespace std;

int main (int argc, char *argv[]){

    Seating seats = Seating();

    ifstream file;
    file.open(argv[1], ios::in); 

    //read the lines from text file
    if (file.is_open()){
        string party;
        while (getline(file, party)){
            seats.add_reservations(party);
        }
    }
    //algorthim for assigning seats
    seats.AssignSeats();
    //print the reserved seating
    seats.printSeating();
    return 0;
}
