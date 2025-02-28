#include "AForm.hpp"

AForm::AForm(const std::string &name, int sign, int exec) : \
_name(name),  _gradeSign(sign), _gradeExec(exec), _isSigned(false) {
    if (_gradeSign < 1 || _gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : _name(obj.getName()),
_gradeSign(obj.getGradeSign()), _gradeExec(obj.getGradeExec()) {
    std::cout << "AForm Copy constructor called" << std::endl;
    *this = obj;
}

AForm&   AForm::operator=(const AForm& obj) {
    std::cout << "Copy assignement called" << std::endl;
    if (this != &obj)
        _isSigned = obj._isSigned;
    return *this;
}

const std::string& AForm::getName() const {
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

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream&   operator<<(std::ostream& out, const AForm& f) {
    out << "AForm name: " << f.getName() << std::endl;
    out << "AForm Sign Grade: " << f.getGradeSign() << std::endl;
    out << "AForm Exec Grade: " << f.getGradeExec() << std::endl;
    out << "AForm Is Signed: " << (f.getIsSigned() ? "yes" : "no") << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}

AForm::~AForm() {
    std::cout << "Form destructor called" << std::endl; 
}

const char *AForm::FormNotSigned::what() const throw() {
    return "Form Not signed";
}

void    AForm::checkExecution(Bureaucrat &executor) const {
    if (!_isSigned)
        throw AForm::FormNotSigned();
    else if (executor.getGrade() > _gradeExec)
        throw AForm::GradeTooLowException();
}