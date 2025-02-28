#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {
        std::cout << "Shruberry Creation Constructor" << std::endl;
    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery Creation Form Destructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat& executor) const{
    checkExecution(executor);
    createShrubbery();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf) {
    AForm::operator=(scf);
    _target = scf._target;
    return *this;
}

void ShrubberyCreationForm::createShrubbery() const {
    std::ofstream file((_target + ".shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Cannot create shrubbery file");

    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/();\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file.close();
}