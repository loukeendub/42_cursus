/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:37:15 by jfabi             #+#    #+#             */
/*   Updated: 2022/01/18 16:37:17 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

//* ################# Message #################

int _ft_set_element(std::string _text, int start, std::string *element)
{
    int next_pos;

    next_pos = _text.find(" ", start);
    if (next_pos != -1)
    {
        *element = _text.substr(start, next_pos - start);
        while (_text[next_pos] == ' ')
            next_pos++;
    }
    else
    {
        next_pos = _text.find(DEL, start);
        *element = _text.substr(start, next_pos);
    }
    return (next_pos);
}

std::vector<std::string> ft_split(std::string _text, char delimiter)
{
    std::vector<std::string>    ret;
    size_t                      i;
    int                         lastPosition;

    i = 0;
    lastPosition = -1;
    while (i < _text.size() && _text[i] == delimiter)
        i++;
    if (i < _text.size())
        lastPosition = _text.find(delimiter, i);
    while (lastPosition != -1)
    {
        ret.push_back(_text.substr(i, lastPosition - i));
        i = lastPosition;
        while (i < _text.size() && _text[i] == delimiter)
            i++;
        if (i < _text.size())
            lastPosition = _text.find(delimiter, i);
    }
    if (lastPosition == -1)
        ret.push_back(_text.substr(i, _text.size() - i));
    return (ret);
}
