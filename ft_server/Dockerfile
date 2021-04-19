# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 14:24:43 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/19 19:09:41 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

From debian:buster

# Update OS
RUN apt update -y
RUN apt upgrade -y

# Install Utilities
RUN apt install vim wget openssl tar -y

# Install MySQL
RUN apt install mariadb-server -y

# Install Nginx
RUN apt install nginx -y

# Install PHP 
RUN apt install php php-fpm php-mysql php-zip php-mbstring php-json php-zip php-gd php-xml php-cli -y

# Copying files
RUN rm -rf /etc/nginx/nginx.conf
COPY srcs/avvio.sh /avvio.sh
COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/mysql.sh /mysql.sh

# Install PhpmyAdmin
WORKDIR /tmp
RUN wget https://files.phpmyadmin.net/snapshots/phpMyAdmin-5.2+snapshot-all-languages.tar.gz
RUN tar -xzvf phpMyAdmin-5.2+snapshot-all-languages.tar.gz
RUN mv phpMyAdmin-5.2+snapshot-all-languages /var/www/html/phpmyadmin 
RUN rm -rf phpMyAdmin-5.2+snapshot-all-languages.tar.gz

#Install Wordpress
RUN wget https://it.wordpress.org/latest-it_IT.tar.gz
RUN tar -xzvf latest-it_IT.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN rm -rf latest-it_IT.tar.gz

#Copying Files pt. 2
COPY srcs/wp-config.php /var/www/html/wordpress/wp-config.php

# Permissions
RUN chown -R www-data:www-data /var/www/html
RUN chmod +x /avvio.sh /mysql.sh

#Init DB
RUN sh /mysql.sh

EXPOSE 80 443

CMD	/avvio.sh
