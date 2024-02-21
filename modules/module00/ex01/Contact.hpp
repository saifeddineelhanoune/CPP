#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    private:
        int					index;
        static std::string	fields_name[5];
        std::string			informations[5];
        enum Field {
            FirstName = 0,
            LastName,
            Nickname,
            Phone,
            Secret
        };
    public:
        Contact();
        virtual ~Contact();

        bool	set_informations(int index);
        void	display_header(void);
        void	display(void);
};

#endif