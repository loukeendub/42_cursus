service mysql start
echo "CREATE DATABASE IF NOT EXISTS ft_server;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON ft_server.* TO 'admin'@'localhost';" | mysql -u root --skip-password
echo "update mysql.user set plugin = 'mysql_native_password' where user='admin';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
service nginx start