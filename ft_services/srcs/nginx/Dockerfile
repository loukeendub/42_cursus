# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 12:21:22 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/26 17:47:45 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

USER root

# update OS
RUN apk update && apk upgrade --no-cache

# Install nginx & utils
RUN apk add nginx openssl --no-cache

# Get CSR for nginx using OpenSSL
RUN openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
    -subj "/C=IT/O=42RomaLuiss/CN=lmarzano" \
    -keyout etc/ssl/private/ft_services.key -out etc/ssl/certs/ft_services.crt
# Copy config
COPY srcs/nginx.conf /etc/nginx/nginx.conf

EXPOSE 80 443

CMD bash