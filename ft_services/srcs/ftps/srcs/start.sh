#! bin/sh

# starting openrc
openrc default
openrc boot
# start services
rc-service vsftpd start

watch rc-service vsftpd status