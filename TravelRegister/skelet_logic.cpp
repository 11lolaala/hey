#include "HPP/major_func.hpp"
#include "HPP/ui.hpp"
#include "HPP/supp_func.hpp"
#include <iostream>
#include <string>

int count_trips = 0;
bool tmp_menu = true;
Trip head;

void command (bool &work_program){
    static bool first_call = true;
    if (first_call == true){
        head.next = nullptr;
        first_call = false;
    }
    if (tmp_menu == true){
        menu();
        tmp_menu = false;
    }
    std::string choice_command = input_command();
    if (choice_command == "1" || choice_command == "1."){
        add_trip(&head, count_trips);
        count_trips++;
    }
    else if (choice_command == "2" || choice_command == "2."){
        std::cout<<choice_sort<<std::endl;
        std::string choice_sort = input_command();
        if (choice_sort == "1" || choice_sort == "1."){
            SORT(&head);
            PRINT(&head);
            std::cout<<"Всего записей: "<<count_trips<<std::endl;
        }
        else if (choice_sort == "2" || choice_sort == "2."){
            PRINT(&head);
            std::cout<<"Всего записей: "<<count_trips<<std::endl;
        }
        else {
            std::cout<<replay_command<<std::endl;
        }
    }
    else if (choice_command == "3" || choice_command == "3."){
        std::cout<<"Введите Фамилию, которую хотите найти"<<std::endl;
        std::string search_surname = input_command();
        SEARCH(&head,search_surname);
    }
    else if (choice_command == "4" || choice_command == "4."){
        add_trip(&head, 0);
    }
    else if (choice_command == "0" || choice_command == "0."){
        work_program = false;
        CLEAR(&head);
    }
    else {
        std::cout<<"Неправильно введена команда!"<<std::endl;
        std::cout<<replay_command<<std::endl;
    }
}