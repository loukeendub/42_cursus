/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RepliesCreator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:08:33 by jfabi             #+#    #+#             */
/*   Updated: 2022/07/25 11:47:51 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RepliesCreator.hpp"
#include "Client.hpp"

std::string makeWelcome(std::string CNickname, std::string CUsername, std::string SName)
{
    std::string text;
 
    text =  "001 "+ CNickname + " :Welcome to the" + SName +  \
            "Network, " + CUsername + DEL;
    return (text);
}

std::string makeYourHost(std::string Servname, std::string SVersion, std::string CNickname)
{
    std::string text;

    text =  "002 " + CNickname + " :Your host is " + Servname + \
            ", running version " + SVersion + DEL;
    return (text);
}

std::string makeCreated(std::string SDate, std::string CNick)
{
    std::string text;

    text = "003 " + CNick + " :This server was created " + SDate + DEL;
    return (text);
}

std::string makeISupport(std::string CNick, std::vector<std::string> parameter)
{
    std::string text;
    std::vector<std::string>::iterator  it;
    int         n;

    n = 1;
    it = parameter.begin();
    text = "005 " + CNick;
    while (it < parameter.end())
    {
        while (it < parameter.end() && it - parameter.begin() < 13 * n)
        {
            text += " " + *it;
            it++;
        }
        text += DEL;
        n++;
    }
    return (text);
}

std::string makeRplUModeis(Client *client)
{
    std::string text;

    text = "221 " + client->getNickname() + client->getMode() + DEL;
    return (text);
}

std::string makeAdminMe(std::string CNick)
{
    std::string text;

    text = "256 " + CNick + " IRCIONE :Info" + DEL;
    return (text);
}

std::string makeAdminLoc1(std::string CNick)
{
    std::string text;

    text = "257 " + CNick + " :Rome, Italy" + DEL;
    return (text);
}

std::string makeAdminLoc2(std::string CNick)
{
    std::string text;

    text = "258 " + CNick + " :42 Roma Luiss" + DEL;
    return (text);
}

std::string makeAdminEmail(std::string CNick)
{
    std::string text;

    text = "259 " + CNick + " :jacopo.fabi8@gmail.com" DEL;
    return (text);
}

std::string makeAway(std::string Client, std::string CNick, std::string message)
{
    std::string text;

    text = "301 " + Client + " " + CNick + " :" + message + DEL;
    return (text);
}

std::string makeUnAway(std::string Client)
{
    std::string text;

    text = "305 " + Client + " :You are no longer maarked as being away" + DEL;
    return (text);
}

std::string makeNowAway(std::string Client)
{
    std::string text;

    text = "306 " + Client + " :You have been marked ad being away" + DEL;
    return (text);
}

std::string makeEndOfWho(std::string cNick, std::string mask)
{
    std::string text;

    text = "315 " + cNick + " " + mask + " :End of WHO list" + DEL;
    return (text);
}

std::string makeRplListStart(std::string cNick)
{
    std::string text;

    text  = "321 " + cNick + " Channel :Users Topic" + DEL;
    return (text);
}

std::string makeRplList(std::string cNick, Channel channel)
{
    std::string text;

    std::stringstream n;
    n << channel.getNClient();
    text = "322 " + cNick + " " + channel.getName() + " " + n.str() + " :" + channel.getTopic() + DEL;
    return (text);
}

std::string makeRplListEnd(std::string cNick)
{
    std::string text;

    text = "323 " + cNick + " :End of /List" + DEL;
    return (text);
}

std::string makeRplChannelModeis(std::string cNick, Channel *channel)
{
    std::string text;

    text = "324 " + cNick + " " + channel->getName() + channel->getModes() + DEL;
    return (text);
}

std::string makeNoTopic(std::string channelName, std::string CNick)
{
    std::string text;

    text = "331 " + CNick + " " + channelName + " :No topic is set" + DEL;
    return (text);
}

std::string makeTopic(std::string channelName, std::string topic, std::string CNick)
{
    std::string text;

    text = "332 " + CNick + " " + channelName + " :" + topic + DEL; 
    return (text);
}

std::string makeTopicWhoTime(std::string cNick, Channel *channel)
{
    std::string text;

    text = "333 " + cNick + " " + channel->getName() + " " + channel->getTopicSet() + " " + channel->getTopicTime() + DEL;
    return (text);
}

std::string makeInviting(std::string CNick, std::string CNickTarget, std::string channel)
{
    std::string text;

    text = "341 " + CNick + " " + CNickTarget + " " + channel + DEL;
    return (text);
}

std::string makeVersion(std::string CNick)
{
    std::string text;

    text = "351 " + CNick + " IRCIONE 1.0 IRCIONE" + DEL;
    return (text);
}

std::string makeWhoReply(Client *client)
{
    std::string text;
    std::string channel;
    std::string away;
    std::string flag;
    std::vector<Channel *> list;

    flag = "";
    list = client->getChannels();
    if (list.begin() < list.end())
    {
        channel = (*list.begin())->getName();
        flag = (*list.begin())->getMaxPrefix(client->getNickname());
    }
    else
        channel = "*";
    if (client->getAwayStatus())
        away = "G";
    else
        away = "H";
    text = "352 " + client->getNickname() + " " + channel + " " + client->getUsername() + " " + client->getHostname() + " IRCIONE " + client->getNickname()  + " ";
    text += away + flag + " :0 " + client->getRealname() + DEL;
    return (text);
}

std::string makeNamReply(Channel *channel, std::string CNick, int flag)
{
    std::string text;
    std::string symbol;
    int         i;

    symbol = "\"=\"";
    i = 1;
    if (channel->hasMode('s'))
        symbol = "\"@\"";
    text = "353 " + CNick + " " + symbol + " " + channel->getName() + " :";
    std::vector<std::pair<int, Client *> >  clients;
    clients = channel->getClients();
    for (std::vector<std::pair<int, Client *> >::iterator it = clients.begin(); it < clients.end() ;it++)
    {
        std::cout << "Dentro l'iteratore" << std::endl;
        if (!((*it).second->hasMode('i')) || flag == 1)
        {
            std::cout << "Dopo l'if" << std::endl;
            if ((int)text.size() + (int)(*it).second->getNickname().size() + DELSIZE > (512 * i))
            {
                text += DEL;
                text += "353 " + CNick + " " + symbol + " " + channel->getName() + " :" + channel->ltop((*it).first) + (*it).second->getNickname();
                i++;
            }
            else
                text += " " + channel->ltop((*it).first) + (*it).second->getNickname();
        }
    }
    text += DEL;
    return (text);
}

std::string makeEndOfNames(std::string channelName, std::string CNick)
{
    std::string text;

    text = "366 " + CNick + " " + channelName + " :End of /NAMES list" + DEL;
    return (text);
}

std::string makeInfo(std::string CNick, std::string dateRun)
{
    std::string text;

    text = "371 " + CNick + " :server IRCIONE 1.0.0 Jacopo Fabi: jacopo.fabi8@gmail.com " + DEL;
    text += "371 " + CNick + " :this server was started " + dateRun + DEL;
    return (text);
}

std::string makeMotD(std::string CNick, std::string motd)
{
    std::string text;

    text = "372 " + CNick + ": " + motd + DEL;
    return (text);
}

std::string makeEndOfInfo(std::string CNick)
{
    std::string text;

    text = "374 " + CNick + " :End of INFO list" + DEL;
    return (text);
}

std::string makeMotDStart(std::string CNick, std::string ServeName, std::string motd)
{
    std::string text;

    text = "375 " + CNick + ":- " + ServeName + " Message of the day - " + motd + DEL; 
    return (text);
}

std::string makeEndOfMotD(std::string CNick)
{
    std::string text;

    text = "376 " + CNick + " :End of /MOTD command" + DEL;
    return (text);
}

std::string makeTime(std::string CNick, std::string servername, std::string date)
{
    std::string text;


    text = "391 " + CNick + " " + servername + " :" + date + DEL;
    return (text);
}

std::string makeErrorUnKnownError(std::string CNick, std::string command, std::string info)
{
    std::string text;

    text = "400 " + CNick + " " + command + " :" + info + DEL;
    return (text);
}

std::string makeNoSuchNick(std::string CNick, int flag)
{
    std::string text;

    if (flag)
        text = "401 " + CNick + " :No such channel" + DEL;
    else
        text = "401 " + CNick + " :No such nick" + DEL;
    return (text);
}

std::string makeNoSuchServer(std::string CNick, std::string SName)
{
    std::string text;

    text = "402 " + CNick + " " + SName + " :No such server" + DEL;
    return (text); 
}

std::string makeErrorNoSuchChannel(std::string CNick, std::string channelName)
{
    std::string text;

    text = "403 " + CNick + " " + channelName  + " :No such channel" + DEL;
    return (text);
}

std::string makeCannotSendToChan(std::string CNick, std::string channelName)
{
    std::string text;

    text = "404 " + CNick + " " + channelName  + " :Cannot send to channel" + DEL;
    return (text);
}

std::string makeTooManyChannels(std::string CNick, std::string ChannelName)
{
    std::string text;

    text = "405 " + CNick + ChannelName + " :You have joined too many channels" + DEL;
    return (text);
}

std::string makeErrorMotD(std::string CNick)
{
    std::string text;

    text = "422 " + CNick + " :MOTD File is missing" + DEL;
    return (text);
}

std::string makeErrorNoNickNameGiven(std::string CNick)
{
    std::string text;

    text = "431 " + CNick + " :No nickname given" + DEL;
    return (text);
}

std::string makeErrorErroneusNickName(std::string CNick, std::string nick)
{
    std::string text;

    text = "432 " + CNick + " " + nick + " :Erroneus" + DEL;
    return (text);
}

std::string makeErrorNickNameInUse(std::string CNick, std::string nick)
{
    std::string text;

    text = "433 " + CNick + " " + nick + " :Nickname is already in use" + DEL;
    return (text);
}

std::string makeErrorNotOnChannel(std::string CNick, std::string channelName)
{
    std::string text;

    text = "441 " + CNick + " " + channelName  + " :It's not on that channel" + DEL;
    return (text);
}

std::string makeErrorUserOnChannel(std::string CNick, std::string CNickTarget, std::string channelName)
{
    std::string text;

    text = "443 " + CNick + " " + CNickTarget + " " + channelName  + " :is already on channel" + DEL;
    return (text);
}

std::string makeErrorNeedMoreParams(std::string CNick, std::string command)
{
    std::string text;

    text = "461 " + CNick + " " + command + " :Not enough parameters" + DEL;
    return (text);
}

std::string makeErrorAlreadyRegistered(std::string CNick)
{
    std::string text;

    text = "462 " + CNick + " :You may not reregister" + DEL;
    return (text);
}

std::string makePasswdMisMatch(std::string CNick)
{
    std::string text;

    text = "464 " + CNick + " :Password incorrect" + DEL;
    return (text);
}

std::string makeErrorChannelIsFull(std::string CNick, std::string channelName)
{
    std::string text;

    text = "471 " + CNick + " " + channelName + " :Cannot join channel (+l)" + DEL;
    return (text);   
}

std::string makeErrorUnKnownMode(std::string CNick, char c)
{
    std::string text;

    text = "472 " + CNick + " " + c + " :is unknown mode char to me" + DEL;
    return (text);
}

std::string makeInviteOnlyChan(std::string CNick, std::string channelName)
{
    std::string text;

    text = "473 " + CNick + " " + channelName + " :Cannot join channel (+i)" + DEL;
    return (text);
}

std::string makeErrorBannedFromChan(std::string CNick, std::string channelName)
{
    std::string text;

    text = "474 " + CNick + " " + channelName + " :Cannot join channel (+b)" + DEL;
    return (text);
}

std::string makeErrorBadChannelKey(std::string CNick, std::string channelName)
{
    std::string text;

    text = "475 " + CNick + " " + channelName + " :Cannot join channel (+k)" + DEL;
    return (text);
}

std::string makeErrorBadChanMask(std::string channel)
{
    std::string text;

    text = "476 " + channel + " :Bad Channel Mask" + DEL;
    return (text);
}

std::string makeChanNoPrivsNeeded(std::string CNick, std::string channel)
{
    std::string text;

    text = "482 " + CNick + " " + channel + " :You're not channel operator" + DEL;
    return (text);
}

std::string makeErrorUModeUnknownFlag(std::string CNick)
{
    std::string text;

    text = "501 " + CNick + " :Unknown MODE flag" + DEL;
    return (text);
}

std::string makeErrorUsersDontmatch(std::string CNick)
{
    std::string text;

    text = "502 " + CNick + " :Cant change mode for other users" + DEL;
    return (text);
}
