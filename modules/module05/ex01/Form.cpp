#include "Form.cpp"

Form::Form() {
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string &name, int sign, int exec, bool isSigned) {
    std::cout << "Form Param constructor called" << std::endl;
    _name = name;
    _gradeSign = sign;
    _gradeExec = exec;
    _isSigned = isSigned;
}

Form::Form(const Form& obj) {
    std::cout << "Form Copy constructor called" << std::endl;
    _name = obj.name;
    _gradeSign = obj.sign;
    _gradeExec = obj.exec;
    _isSigned = obj.isSigned;
}

Form&   Form::operator=(const Form& obj) {
    std::cout << "Copy assignement called" << std::endl;
    if (this != obj) {
        _name = obj.name;
        _gradeSign = obj.sign;
        _gradeExec = obj.exec;
        _isSigned = obj.isSigned;
    }
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

void    Form::beSigned(Bureacrat& b) {
    if (_isSigned)
        throw Form::FormAlreadySignedException();
    if (_signGrade < b.getGrade())
        std::cerr << "F"
    isSigned = true;
}

void    Form::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	} catch (std::exception& e) {
		std::cout << *this << " could no t sign " << form << " because " << e.what() << std::endl;
	}
}

std::ostream&   operator<<(std::ostream& out, const Form& f) {
    out << "Form name: " << f.getName() << std::endl;
    out << "Form Sign Grade:" << f.getGradeSign() << std::endl;
    out << "Form Exec Grade:" << f.getGradeExec() << std::endl;
    out << "Form Is Signed:" << f.getIsSigned() << std::endl;
    return out;
}