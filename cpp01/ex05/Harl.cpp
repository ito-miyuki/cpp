#include "Harl.hpp"

void Harl::complain( std::string level )
{
    void(level);
    debug();
    info();
    warning();
    error();
}



void Harl::complain(std::string level) {
    // メンバー関数ポインタを定義
    void (Harl::*func_ptrs[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    // 各レベルと対応する関数ポインタをマッピング
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            // ポインタを使って関数を呼び出す
            (this->*func_ptrs[i])();
            return;
        }
    }
    std::cout << "Unknown level: " << level << std::endl;
}



void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}