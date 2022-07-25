/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:58:56 by jfabi             #+#    #+#             */
/*   Updated: 2022/07/25 11:47:27 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "Message.hpp"
# include "Client.hpp"
# include "utils.hpp"

class Server;

int execCommand(Message message, Client *client, Server *server);

int execAdmin(Message message, Client *client, Server *server);
int execAway(Message message, Client *client); 
int execCap(Message message, Client *client, Server *server);
int execInfo(Client *client, Server *server);
int execInvite(Message message, Client *client, Server *server);
int execJoin(Message message, Client *client, Server *server);
int execKick(Message message, Client *client, Server *server);
int execList(Message message, Client *client, Server *server);
int execMode(Message message, Client *client, Server *server);
int execMotd(Message message, Client *client, Server *server);
int execNames(Message message, Client *client, Server *server);
int execNick(Message message, Client *client, Server *server);
int execNotice(Message message, Client *client, Server *server);
int execPart(Message message, Client *client, Server *server);
int execPass(Message message, Client *client, Server *server);
int execPing(Message message, Client *client, Server *server);
int execPrivmsg(Message message, Client *client, Server *server);
int execQuit(Message message, Client *client, Server *server);
int execTime(Message message, Client *client, Server *server);
int execTopic(Message message, Client *client, Server *server);
int execUser(Message message, Client *client);
int execVersion(Message message, Client *client, Server *server);

#endif
