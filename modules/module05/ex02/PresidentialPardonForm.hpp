#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        explicit PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        virtual void execute(const Bureaucrat& executor) const;
    private:
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void pardonTarget() const;
};
