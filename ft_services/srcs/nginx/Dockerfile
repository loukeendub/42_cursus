# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 12:21:22 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/04 15:49:29 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

USER root

# update OS
RUN apk update && apk upgrade --no-cache

# Install nginx & utils
RUN apk add nginx openssl --no-cache
RUN mkdir -p run/nginx

# Get CSR for nginx using OpenSSL
RUN openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
    -subj "/C=IT/O=42RomaLuiss/CN=lmarzano" \
    -keyout etc/nginx/ft_services.key -out etc/nginx/ft_services.crt

#  Copy config
COPY ./srcs/nginx.conf /etc/nginx/nginx.conf
COPY ./srcs/index.html /var/www/html/index.html
COPY ./srcs/start.sh /tmp/start.sh

EXPOSE 80 443

CMD sh /tmp/start.sh