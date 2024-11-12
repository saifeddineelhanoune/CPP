#include "ShruberryCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) :
AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExec(), false) {
    std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &str) {

}

void    ShrubberyCreationForm::execute(const Bureaucrat &exec) {

}