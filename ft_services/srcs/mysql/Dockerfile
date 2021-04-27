# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:03 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/27 16:47:14 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

# update OS
RUN apk update && apk upgrade

# Install mysql
RUN apk add mariadb-server

# Copy config


EXPOSE 3306

CMD bash