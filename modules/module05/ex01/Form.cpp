#include "Form.hpp"

Form::Form(const std::string &name, int sign, int exec) : \
_name(name),  _gradeSign(sign), _gradeExec(exec), _isSigned(false) {
    if (_gradeSign < 1 || _gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : \
_name(obj.getName()),
_gradeSign(obj.getGradeSign()),
_gradeExec(obj.getGradeExec()),
_isSigned(obj.getIsSigned()) {
    std::cout << "Form Copy constructor called" << std::endl;
}

Form&   Form::operator=(const Form& obj) {
    std::cout << "Copy assignement called" << std::endl;
    if (this != &obj)
        _isSigned = obj._isSigned;
    return *this;
}

const std::string& Form::getName() const {
    return _name;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExec() const {
    return _gradeExec;
}

bool    Form::getIsSigned() const {
    return _isSigned;
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeSign)
        throw Form::GradeTooLowException();
    else
        _isSigned = true;
}

std::ostream&   operator<<(std::ostream& out, const Form& f) {
    out << "Form name: " << f.getName() << std::endl;
    out << "Form Sign Grade: " << f.getGradeSign() << std::endl;
    out << "Form Exec Grade: " << f.getGradeExec() << std::endl;
    out << "Form Is Signed: " << (f.getIsSigned() ? "yes" : "no") << std::endl;
    return out;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl; 
}