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

# Install influxdb
RUN apk add influxdb --no-cache
RUN apk add telegraf --no-cache
# Copy config
RUN mkdir /etc/telegraf
COPY ./srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY /srcs/start_influxdb.sh /tmp/start_influxdb.sh

EXPOSE 8086

CMD sh /tmp/start_influxdb.sh