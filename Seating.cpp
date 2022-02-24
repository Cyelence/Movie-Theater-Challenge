#include "Seating.h"

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<unordered_map>


using namespace std;

Seating::Seating(){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < seatsPerRow; j++){
            availableSeats[i][j] = char(i+'A') + to_string(j+1);
        }
    }
}

void Seating::add_reservations(string line){
    int splitIdx = line.find(' ');
    string ID = line.substr(0, splitIdx);
    int numSeats = stoi(line.substr(splitIdx, line.length()));
    pair<string, int> party = make_pair(ID, numSeats);
    reservations.push_back(party);
}


void Seating::AssignSeats(){
    //start from middle row and move towards the back, then the front
    int curRow = numRows/2-1;
    int curSeat = 0;
    for (const pair<string,int> &party : reservations){
        bool leftOver = false;

        //handling buffer of 3 seats or next row
        if (curSeat+party.second>= seatsPerRow){
            for (int i = curSeat; i < seatsPerRow; i++){
                leftOverSeats[curRow].push_back(i);
            }
            curSeat = 0;
            curRow = (curRow + 1) % numRows;
            //curRow = numRows/2-2;
        }
        int leftOverRow = getLeftOverSeats(party);
        if (leftOverRow > -1){
            for (int j = 0; j < party.second; j++){
                string seat = availableSeats[leftOverRow][leftOverSeats[leftOverRow][j]];
                reservedSeats[party.first].push_back(seat);
                availableSeats[leftOverRow][leftOverSeats[leftOverRow][j]] = "";
                leftOverSeats[leftOverRow].erase(leftOverSeats[leftOverRow].begin() + j);   
            }
        }
        else {
            for (int i = curSeat; i < curSeat+party.second; i++){
            reservedSeats[party.first].push_back(availableSeats[curRow][i]);
            availableSeats[curRow][i] = "";
            }
            curSeat += party.second + 3;
        }
    }
    
}

/*
Checking if this party can be placed at any unused seats
that are 3 seats away from a taken seat.
Reserves the seat for the party if theres available leftover seats
large enough to hold the party
*/
int Seating::getLeftOverSeats(pair<string,int> party){
    int row = -1;
    for (int i = 0; i < numRows; i++){
        if (leftOverSeats[i].size() == party.second){
            row = i;
            break;
        }
    }
    return row;
}


//prints out the seats for each reservation
void Seating::printSeating(){
    for (const auto &party : reservations){
        cout<<party.first<<" ";
        int size = reservedSeats[party.first].size();
        for (int i = 0 ; i < size-1; i++){
            cout<<reservedSeats[party.first][i]<<",";
        }
        //This is to not print a comma after the last seat
        cout<<reservedSeats[party.first][size-1];
        cout<<"\n";
    }
}