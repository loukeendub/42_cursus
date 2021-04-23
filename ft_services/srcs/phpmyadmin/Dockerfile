# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:26 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/23 16:26:16 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

# update OS
RUN apk update && apk upgrade

# Install Utils
RUN apk add vim wget tar -y

# Install PHPMYADMIN
WORKDIR /tmp
RUN wget https://files.phpmyadmin.net/snapshots/phpMyAdmin-5.2+snapshot-all-languages.tar.gz
RUN tar -xzvf phpMyAdmin-5.2+snapshot-all-languages.tar.gz
RUN mv phpMyAdmin-5.2+snapshot-all-languages /var/www/html/phpmyadmin 
RUN rm -rf phpMyAdmin-5.2+snapshot-all-languages.tar.gz

# Copy config
WORKDIR /root
COPY srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php 

EXPOSE 5000

CMD bash