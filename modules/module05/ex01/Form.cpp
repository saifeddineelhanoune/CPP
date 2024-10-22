#include "Form.hpp"

Form::Form(const std::string &name, int sign, int exec, bool isSigned) : \
_name(name), _gradeExec(exec), _gradeSign(sign), _isSigned(isSigned) {
    std::cout << "Form Param constructor called" << std::endl;
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
        *this = obj;
    return *this;
}

std::string Form::getName() const {
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

void    Form::beSigned(Bureaucrat& b) {
    if (_isSigned)
        throw std::logic_error("Bureaucrat already signed");
    if (_gradeSign < b.getGrade())
        throw Form::GradeTooLowException();
    _isSigned = true;
}

void    Form::signForm(Bureaucrat &b, Form &f) {
    try {
        f.beSigned(b);
        std::cout << "bureaucrat: " << b.getName() << " Signed Form" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream&   operator<<(std::ostream& out, const Form& f) {
    out << "Form name: " << f.getName() << std::endl;
    out << "Form Sign Grade:" << f.getGradeSign() << std::endl;
    out << "Form Exec Grade:" << f.getGradeExec() << std::endl;
    out << "Form Is Signed:" << f.getIsSigned() << std::endl;
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