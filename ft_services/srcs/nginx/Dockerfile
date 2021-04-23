# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 12:21:22 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/23 17:30:22 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

# update OS
RUN apk update && apk upgrade --no-cache

# Install nginx
RUN apk add nginx openssl telegraf --no-cache

# Copy config
COPY srcs/nginx.conf /etc/nginx/nginx.conf

EXPOSE 80 443

CMD bash