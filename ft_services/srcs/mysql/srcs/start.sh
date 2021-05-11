#! /usr/local/bin

telegraf &

openrc default
openrc boot
/etc/init.d/mariadb setup
sleep 2
rc-service mariadb start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER 'wp_admin'@'%' IDENTIFIED BY 'admin';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wp_admin'@'%' IDENTIFIED BY 'admin' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'admin'@'%' IDENTIFIED BY 'admin' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
rc-service mariadb stop
mysqld
# sleep infinity && wait