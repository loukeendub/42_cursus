# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:38 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/05 12:36:39 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

USER root

# update OS
RUN apk update && apk upgrade --no-cache

# Install utils
RUN apk add nginx openssl openrc wget tar --no-cache
RUN	apk add php7 php7-fpm php7-pdo_mysql php7-cli php7-json php7-mbstring php7-common php7-session php7-iconv php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom --no-cache
RUN	mkdir -p /run/nginx

# Telegraf
RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf etc/telegraf/telegraf.conf

# Install WP
WORKDIR /var/www/html/
RUN wget https://it.wordpress.org/latest-it_IT.tar.gz
RUN tar -xzvf latest-it_IT.tar.gz
RUN rm -rf latest-it_IT.tar.gz
RUN rm -rf /var/www/html/wordpress/wp-config-sample.php

# Copy config
COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/wp-config.php /var/www/html/wordpress/wp-config.php
COPY srcs/start.sql /tmp/start.sql
COPY srcs/start_wp.sh /tmp/start_wp.sh

WORKDIR /
#RUN	chmod +x /bin/php-config

EXPOSE 5050

CMD sh tmp/start_wp.sh
