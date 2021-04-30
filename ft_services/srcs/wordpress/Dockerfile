# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:38 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/30 11:49:16 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

USER root

# update OS
RUN apk update && apk upgrade --no-cache

# Install utils
RUN apk add vim wget tar -y

# Install WP
WORKDIR /tmp
RUN wget https://it.wordpress.org/latest-it_IT.tar.gz
RUN tar -xzvf latest-it_IT.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN rm -rf latest-it_IT.tar.gz
RUN rm -rf /var/www/html/wordpress/wp-config-sample.php

# Copy config
WORKDIR /root
COPY srcs/wp-config.php /var/www/html/wordpress/wp-config.php

EXPOSE 5050

#CMD bash