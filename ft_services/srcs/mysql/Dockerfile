# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:03 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/04 15:39:09 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

USER root

# update OS
RUN apk update && apk upgrade --no-cache

# Install mysql
RUN apk add mysql bash mariadb mysql-client mariadb-client openrc telegraf --no-cache
RUN mkdir ./etc/telegraf
RUN mv /etc/telegraf.conf /etc/telegraf/telegraf.conf

# Copy config
RUN mkdir -p /run/mysqld
COPY ./srcs/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY ./srcs/start.sh /tmp/start.sh

EXPOSE 3306

CMD sh /tmp/start.sh