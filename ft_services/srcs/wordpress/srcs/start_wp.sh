#! /bin/sh
telegraf &

# starting openrc
openrc default
openrc boot
# start services
rc-service php-fpm7 start
rc-service nginx start

mysql -u wp_admin -p admin < temp/start.sql

# php -S localhost:5051
watch rc-service nginx status