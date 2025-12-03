#include "../HPP/major_func.hpp"
#include "../HPP/supp_func.hpp"
#include "../HPP/error.hpp"
#include "../HPP/ui.hpp"
#include <iostream>
#include <string>

Trip* MAKE(std::string fio, std::string departure_date, std::string return_date, std::string destination, std::string goal_trip, float daily_allowance){
    Trip* newreg = new Trip;
    newreg->F_I_O = fio;
    newreg->departure_date = departure_date;
    newreg->return_date = return_date;
    newreg->destination = destination;
    newreg->goal_trip = goal_trip;
    newreg->daily_allowance = daily_allowance;
    return newreg;  
}

void ADD(Trip* head, std::string fio, std::string departure_date, std::string return_date, std::string destination, std::string goal_trip, float daily_allowance){
    Trip* newreg = MAKE(fio,departure_date,return_date,destination,goal_trip,daily_allowance);
    newreg->next = head->next;
    head->next = newreg;
}

void ADD_BACK(Trip* head, std::string fio, std::string departure_date, std::string return_date, std::string destination, std::string goal_trip, float daily_allowance){
    Trip* newreg = MAKE(fio,departure_date,return_date,destination,goal_trip,daily_allowance);
    newreg->next = nullptr;
    Trip* Tmp = head;
    while (Tmp->next != nullptr){
        Tmp=Tmp->next;
    }
    Tmp->next=newreg;
}

void PRINT(Trip* head){
    Trip* newreg = head->next;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "| ФИО                                | Дата выезда| Дата возвращ.| Место назнач. | Цель   | Суточные |" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    if (newreg == nullptr) {
        std::cout << "|                                    НЕТ ДАННЫХ                                      |" << std::endl;
    }
    while(newreg != nullptr) {
        std::cout << "| " << newreg->F_I_O;
        for(int i = newreg->F_I_O.length(); i < 35; i++) {
            std::cout << " ";
        }
        std::cout << "| " << newreg->departure_date;
        for(int i = newreg->departure_date.length(); i < 11; i++) {
            std::cout << " ";
        }
        std::cout << "| " << newreg->return_date;
        for(int i = newreg->return_date.length(); i < 13; i++) {
            std::cout << " ";
        }
        std::cout << "| " << newreg->destination;
        for(int i = newreg->destination.length(); i < 14; i++) {
            std::cout << " ";
        }
        std::cout << "| " << newreg->goal_trip;
        for(int i = newreg->goal_trip.length(); i < 7; i++) {
            std::cout << " ";
        }
        std::cout << "| " << newreg->daily_allowance;
        std::string allowance_str = std::to_string(newreg->daily_allowance);
        for(int i = allowance_str.length(); i < 8; i++) {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        newreg = newreg->next;
    }
    std::cout << "=====================================================================================================" << std::endl;
}

void CLEAR(Trip* head){
    if (head == nullptr) return;
    
    Trip* current = head->next;
    while (current != nullptr) {
        Trip* to_delete = current;
        current = current->next;
        delete to_delete;
    }
    head->next = nullptr;
}

void SORT (Trip* head){
    if (head == nullptr || head->next == nullptr) {
        std::cout<<"Список пуст"<<std::endl;
        return;
    }
    std::string tmp;
    bool swap = true;
    while (swap == true){
        Trip* current = head->next;
        swap = false;
        while (current->next != nullptr){
            if (current->F_I_O>current->next->F_I_O){
                tmp = current->F_I_O;                      
                current->F_I_O = current->next->F_I_O;    
                current->next->F_I_O = tmp;
                current = current->next;
                swap = true;
            }
            else {
                current = current->next;
            }     
        }
    }
    std::cout<<"Регист был отсортирован"<<std::endl;
}

void add_trip(Trip* head, int count_trip){
    std::cout<<"Введите фамилию (от 5 до 60 символов): ";
    std::string F_I_O = input_command();
    bool correct_fio_sym = correct_string_fio(F_I_O);
    if (size(F_I_O) < 5 || size(F_I_O) > 60){
        std::cout<<error_len_fio<<std::endl;
        std::cout<<replay_command<<std::endl;
        return;
    }
    if (correct_fio_sym == false){
        std::cout<<error_symbol_fio<<std::endl;
        std::cout<<replay_command<<std::endl;
        return;
    }
    std::cout<<"Введите дату выезда (в формате xx.xx.xxxx): ";
    std::string departure_date = input_command();
    if (correct_date(departure_date)==false){
        return;
    }
    std::cout<<"Введите дату приезда: ";
    std::string return_date = input_command();
    if (correct_date(return_date) == false){
        return;
    }
    std::cout<<"Введите место назначения: ";
    std::string destination = input_command();
    std::cout<<"Введите цель поездки: ";
    std::string goal_trip = input_command();
    std::cout<<"Введите суточные: ";
    float daily_allowance;
    std::cin>>daily_allowance;
    std::cin.ignore();
    if (correct_daily_rewards(daily_allowance) == false){
        return;
    }
    if (count_trip == 0){
        ADD(head, F_I_O, departure_date, return_date, destination, goal_trip, daily_allowance);
    }
    else {
        ADD_BACK(head, F_I_O, departure_date, return_date, destination, goal_trip, daily_allowance);
    }
    std::cout<<"Данные успешно внесены!"<<std::endl;
}

void SEARCH (Trip* head, std::string search_fio){
    int count = 0;
    int count_coincidence = 0;
    Trip* current = head->next;
    if (count_coincidence == 0){
        std::cout << "=====================================================================================================" << std::endl;
        std::cout << "| ФИО                                | Дата выезда | Дата возвращ. | Место назначения | Цель    | Суточные | Совпадения  |" << std::endl;
        std::cout << "=====================================================================================================" << std::endl;
    }
    while (current != nullptr){
        count++;
        if (current->F_I_O == search_fio){
            count_coincidence++;
            std::cout << "| " << current->F_I_O;
            for(int i = current->F_I_O.length(); i < 35; i++) {
                std::cout << " ";
            }
            std::cout << "| " << current->departure_date;
            for(int i = current->departure_date.length(); i < 12; i++) {
                std::cout << " ";
            }
            std::cout << "| " << current->return_date;
            for(int i = current->return_date.length(); i < 14; i++) {
                std::cout << " ";
            }
            std::cout << "| " << current->destination;
            for(int i = current->destination.length(); i < 17; i++) {
                std::cout << " ";
            }
            std::cout << "| " << current->goal_trip;
            for(int i = current->goal_trip.length(); i < 8; i++) {
                std::cout << " ";
            }
            std::cout << "| " << current->daily_allowance;
            for(int i = current->goal_trip.length(); i < 9; i++) {
                std::cout << " ";
            }
            std::cout << "| " << count_coincidence;
            std::string nodes_str = std::to_string(count_coincidence);
            for(int i = nodes_str.length(); i < 12; i++) {
                std::cout << " ";
            }
            std::cout << "|" << std::endl;
            current = current->next;
        }
        else{
            current = current->next;
        }
    }
    if (count_coincidence == 0){
        std::cout<<"Таких фамилий в регистре нет"<<std::endl;
    }
}