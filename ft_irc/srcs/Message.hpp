/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:45:06 by jfabi             #+#    #+#             */
/*   Updated: 2022/07/25 11:47:44 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include <vector>

# include "utils.hpp"
class Message
{
    public:
        typedef std::vector<std::string>        str_list;

        Message();
        Message(std::string text);
        Message(const Message &copy);
        ~Message();

        //* ################# GETTERS #################

        std::string                 getPrefix() const;
        std::string                 getCommand() const;
        std::string                 getParametersIndex(size_t indx) const;
        std::string                 getLastParameter() const;
        //std::string                 getLastParameter() const;
        str_list                    getParameters();
        str_list                    getLastParameterMatrix();
        str_list::const_iterator    getParametersBegin() const;
        str_list::const_iterator    getParametersEnd() const;
        std::string                 getText() const;
        int                         getSize() const;
        bool                        getIsLastParameter() const;

        //* ################# SETTERS #################

        void            setMessage(std::string text);

    private:

        std::string _prefix;
        std::string _command;
        std::string _text;
        std::string _lastParameter;
        str_list    _parameters;
        bool        _isLastParameter;
};

std::ostream& operator<<(std::ostream& os, const Message &copy);

#endif
