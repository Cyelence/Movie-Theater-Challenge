#ifndef SEATING_H
#define SEATING_H

#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

//implements seating algorithm

class Seating {
private: 
    static const int numRows = 10;
    static const int seatsPerRow = 20;
    string availableSeats[numRows][seatsPerRow];
    unordered_map<string, vector<string> > reservedSeats;
    vector<pair<string,int> >reservations;
    unordered_map<int, vector<int> > leftOverSeats;

public:
    Seating();
    void AssignSeats();
    int getLeftOverSeats(pair<string,int> party);
    void add_reservations(string line);
    void printSeating();

};


#endif
