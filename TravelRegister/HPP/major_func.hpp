#pragma once
#include <iostream>
#include <string>


struct Trip {
    std::string F_I_O;
    std::string departure_date;
    std::string return_date;
    std::string destination;
    std::string goal_trip;
    float daily_allowance;
    Trip* next;
};

Trip* MAKE(std::string fio, std::string departure_date, std::string return_date, std::string destination, std::string goal_trip, float daily_allowance);
void ADD(Trip* head, std::string fio, std::string departure_date, std::string return_date, std::string destination, std::string goal_trip, float daily_allowance);
void ADD_BACK(Trip* head, std::string fio, std::string departure_date, std::string return_date, std::string destination, std::string goal_trip, float daily_allowance);
void PRINT(Trip* head);
void CLEAR(Trip* head);
void add_trip(Trip* head, int count_trip);
void SEARCH (Trip* head, std::string search_fio);
void SORT (Trip* head);
