#! /bin/sh

# starting openrc
openrc default
openrc boot
# start services
rc-service php-fpm7 start
rc-service nginx start