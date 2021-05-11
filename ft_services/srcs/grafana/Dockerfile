# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:55:03 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/03 12:08:38 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

# update OS
RUN apk update && apk upgrade --no-cache

# Install Utils
RUN apk add nginx openssl openrc libc6-compat telegraf --no-cache

# # Get CSR for nginx using OpenSSL
RUN openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
     -subj "/C=IT/O=42RomaLuiss/CN=lmarzano" \
     -keyout /etc/nginx/ft_services.key -out /etc/nginx/ft_services.crt

# Install Grafana
RUN mkdir -p run/nginx
RUN wget https://dl.grafana.com/oss/release/grafana-7.5.5.linux-amd64.tar.gz
RUN tar -zxvf grafana-7.5.5.linux-amd64.tar.gz
RUN mkdir /var/www/html
RUN mv grafana-7.5.5 /var/www/html/grafana
RUN rm -rf grafana-7.5.5.linux-amd64.tar.gz

# Telegraf
RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf etc/telegraf/telegraf.conf

# Datasource & Dashboard
COPY ./srcs/datasource.yaml /var/www/html/grafana/conf/provisioning/datasources/datasource.yaml
COPY ./srcs/dashboard.yaml /var/www/html/grafana/conf/provisioning/dashboards/dashboard.yaml
COPY ./srcs/dashboard/*.json /var/www/html/grafana/conf/provisioning/dashboards/

# Copy configs from srcs
COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/start.sh /

EXPOSE 3000

CMD sh start.sh