# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 16:47:23 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/05 18:46:28 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# see what changes would be made, returns nonzero returncode if different
kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl diff -f - -n kube-system

# actually apply the changes, returns nonzero returncode on errors only
kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl apply -f - -n kube-system
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/metallb.yaml

# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

# Create Dashboard && start service
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml
kubectl proxy &

# Build docker images
docker build --no-cache ./srcs/nginx -t nginx
docker build --no-cache ./srcs/phpmyadmin -t phpmyadmin
docker build --no-cache ./srcs/wordpress -t wordpress
docker build --no-cache ./srcs/mysql -t mysql
docker build --no-cache ./srcs/ftps -t ftps
docker build --no-cache ./srcs/influxdb -t influxdb
docker build --no-cache ./srcs/grafana -t grafana


# Apply yaml config files
kubectl apply -f ./srcs/k8s/mlb_conf.yaml
kubectl apply -f ./srcs/k8s/nginx.yaml
kubectl apply -f ./srcs/k8s/mysql.yaml
kubectl apply -f ./srcs/k8s/phpmyadmin.yaml
kubectl apply -f ./srcs/k8s/wordpress.yaml
kubectl apply -f ./srcs/k8s/ftps.yaml
kubectl apply -f ./srcs/k8s/influxdb.yaml
kubectl apply -f ./srcs/k8s/grafana.yaml

# Create Dashboard user
kubectl apply -f srcs/dashboard/dashboard-adminuser.yaml

# Get token
kubectl -n kubernetes-dashboard get secret $(kubectl -n kubernetes-dashboard get sa/admin-user -o jsonpath="{.secrets[0].name}") -o go-template="{{.data.token | base64decode}}" > tmp.token
open -a TextEdit tmp.token

sleep 10s
open http://localhost:8001/api/v1/namespaces/kubernetes-dashboard/services/https:kubernetes-dashboard:/proxy/