kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl diff -f - -n kube-system

kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl apply -f - -n kube-system

docker build ./srcs/nginx -t nginx
docker build ./srcs/phpmyadmin -t phpmyadmin
docker build ./srcs/wordpress -t wordpress
docker build ./srcs/mysql -t mysql