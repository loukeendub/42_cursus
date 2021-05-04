#! /bin/sh

# starting openrc
openrc default
openrc boot
# start services
rc-service php-fpm7 start
rc-service nginx start

# php -S localhost:5051
watch rc-service nginx status