#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) _signed = other._signed;
    return *this;
}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

void AForm::checkGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high for form!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low for form!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() 
       << " (Sign Grade: " << form.getGradeToSign()
       << ", Execute Grade: " << form.getGradeToExecute()
       << ", Signed: " << (form.isSigned() ? "yes" : "no") << ")";
    return os;
}