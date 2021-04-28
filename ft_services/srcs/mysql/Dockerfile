# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:03 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/28 13:02:24 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

# update OS
RUN apk update && apk upgrade

# Install mysql
RUN apk add mariadb-server

# Copy config


EXPOSE 3306

CMD bash