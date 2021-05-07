# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 17:00:20 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/05 18:30:25 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

USER root

# update OS
RUN apk update && apk upgrade --no-cache

# install utils
RUN apk add openssl openrc vsftpd --no-cache

# Get CSR for FTP using OpenSSL
RUN openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
    -subj "/C=IT/O=42RomaLuiss/CN=lmarzano" \
    -keyout /etc/vsftpd/vsftpd.key -out /etc/vsftpd/vsftpd.crt

# Telegraf
RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf etc/telegraf/telegraf.conf

# Copy configs from srcs
COPY ./srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY srcs/start.sh /tmp/start.sh

RUN { echo "password"; echo "password"; } | adduser ftps_admin

EXPOSE 20 21 21000

CMD sh /tmp/start.sh
