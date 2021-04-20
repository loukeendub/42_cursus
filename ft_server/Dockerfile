# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 14:24:43 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/20 15:38:34 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

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
RUN rm -rf /var/www/html/wordpress/wp-config-sample.php

#Copying Files pt. 2
COPY srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php
COPY srcs/wp-config.php /var/www/html/wordpress/wp-config.php

# Permissions
RUN chown -R www-data:www-data /var/www/html
RUN chmod +x /avvio.sh /mysql.sh

#SSL Key
RUN wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64
RUN mv mkcert-v1.4.1-linux-amd64 mkcert
RUN chmod +x mkcert
RUN mv mkcert /usr/local/bin
RUN mkcert -install
RUN mkcert localhost
RUN mv localhost.pem /etc/nginx/localhost.pem
RUN mv localhost-key.pem /etc/nginx/localhost-key.pem

#Init DB
RUN sh /mysql.sh

EXPOSE 80 443

CMD	/avvio.sh
