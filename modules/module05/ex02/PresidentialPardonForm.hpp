#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        void pardonTarget() const;

    public:
        PresidentialPardonForm(const std::string& target);
        ~PresidentialPardonForm();
        void execute(Bureaucrat& executor) const;
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};
