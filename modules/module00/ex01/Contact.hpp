#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

enum Field {
    FirstName,
    LastName,
    Nickname,
    Phone,
    Secret
};

class Contact
{
    private:
        static std::string	fields_name[5];
        std::string			informations[5];
        int					index;
    public:
        Contact();
        ~Contact();

        bool	set_informations(int index);
        void	display_header(void);
        void	display(void);
};

#endif