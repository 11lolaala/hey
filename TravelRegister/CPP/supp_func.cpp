#include <iostream>
#include <string>
#include "../HPP/error.hpp"
#include "../HPP/ui.hpp"

std::string input_command(){
    std::string input;
    std::getline(std::cin, input); //проверить заходит ли значение в син, сдлеать обработку ошибок функции
    return input;
}

bool correct_string_fio(std::string string){
    for (int i = 0; i<string.size(); i++){
        char sym = string[i];
        if (!((sym >= 'A' && sym <= 'Z')  || ( sym>='a' && sym <='z') || (sym == ' '))){
            return false;
        }
    }
    return true;
}

bool correct_digit(std::string string){
    for (int i = 0; i<string.size(); i++){
        char sym = string[i];
        if (sym <= '0' || sym >= '9'){
            return false;
        }
    }
    return true;
}


bool correct_date(std::string date){
    int count_dot = 0;
    if (size(date) != 10)
    if (correct_digit(date) == false){
        std::cout<<"Incorrect len date"<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
    if (date[0] > '3' || date[3] > '1' || date [6] != '2' || date[7] != '0' || date[8] < '2' || date[8] > '3'){
        std::cout<<error_consist_date<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
    if ((date[0] == '0' && date[1] == '0') || (date[3] == '0' && date[4] == '0')){
        std::cout<<error_consist_date<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
    if (date[8] == '3' && date[9]!= '0'){
        std::cout<<error_consist_date<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
    if (date[0] == '3' && date[1] > '1'){
        std::cout<<error_consist_date<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
    if (date[3] == '1' && date[4] > '2'){
        std::cout<<error_consist_date<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
    for (int i = 0; i<date.size(); i++){
        char sym = date[i];
        if (sym == '.'){
            count_dot++;
        }
    }
    if (date[2] == '.' && date[5] == '.'){
        if (count_dot == 2){
            return true;
        }
        else {
            std::cout<<error_consist_date<<std::endl;
            std::cout<<replay_command<<std::endl;
            return false;
        }
    }
    else {
        std::cout<<error_consist_date<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
}

bool correct_daily_rewards(float daily_rewards){
    if (daily_rewards < 0 || daily_rewards > 100'000){
        std::cout<<error_consist_date<<std::endl;
        std::cout<<replay_command<<std::endl;
        return false;
    }
    else {
        return true;
    }
}
