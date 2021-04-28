#! /bin/sh

# configuring php & starting openrc
mkdir -p run/nginx
openrc default
openrc boot
# start services
rc-service php-fpm7 start
rc-service nginx start