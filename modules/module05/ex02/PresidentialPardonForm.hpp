#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);

    public:
        PresidentialPardonForm(const std::string& target);
        virtual ~PresidentialPardonForm();
        void execute(Bureaucrat& executor);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        
    private:
        void pardonTarget() const;
};
