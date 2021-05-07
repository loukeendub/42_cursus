# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:26 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/05 14:50:41 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

USER root

# update OS
RUN apk update --no-cache

# Install Utils
RUN apk add php7 php7-fpm php7-pdo_mysql php7-cli php7-json php7-mbstring php7-common php7-session php7-iconv php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom --no-cache
RUN apk add nginx openssl openrc --no-cache

# Get CSR for nginx using OpenSSL
RUN openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
    -subj "/C=IT/O=42RomaLuiss/CN=lmarzano" \
    -addext "subjectAltName=DNS:localhost" \
    -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.pem

# Telegraf
RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf etc/telegraf/telegraf.conf

# Install PHPMYADMIN
RUN mkdir -p run/nginx
RUN wget https://files.phpmyadmin.net/snapshots/phpMyAdmin-5.2+snapshot-all-languages.tar.gz
RUN tar -xzvf phpMyAdmin-5.2+snapshot-all-languages.tar.gz
RUN mkdir /var/www/html
RUN mv phpMyAdmin-5.2+snapshot-all-languages /var/www/html/phpmyadmin
RUN mkdir /var/www/html/phpmyadmin/tmp
RUN rm -rf phpMyAdmin-5.2+snapshot-all-languages.tar.gz

# Copy configs from srcs
COPY srcs/nginx.conf /etc/nginx/conf.d/default.conf
COPY srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php
RUN rm -rf /var/www/html/phpmyadmin/config.sample.inc.php
COPY srcs/start.sh /tmp/start.sh

EXPOSE 5000

RUN rc-update add nginx default
RUN rc-update add php-fpm7 default

CMD sh /tmp/start.sh
