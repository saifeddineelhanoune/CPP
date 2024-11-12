#include "AForm.hpp"

AForm::AForm(const std::string &name, int sign, int exec) : \
_name(name), _gradeExec(exec), _gradeSign(sign) {
    std::cout << "Form Param constructor called" << std::endl;
    if (_gradeSign < 1 || _gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw AForm::GradeTooLowException();
}

std::string AForm::getName() const {
    return _name;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExec() const {
    return _gradeExec;
}

bool    AForm::getIsSigned() const {
    return _isSigned;
}

