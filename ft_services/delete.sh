kubectl delete ns metallb-system
kubectl delete service mysql
kubectl delete service nginx
kubectl delete deployment mysql
kubectl delete deployment nginx
kubectl delete pvc mysql-pv-claim
kubectl delete pv mysql-pv-volume
kubectl delete service phpmyadmin
kubectl delete deployment phpmyadmin
kubectl delete service wordpress
kubectl delete deployment wordpress
kubectl delete service ftps
kubectl delete deployment ftps
rm -rf tmp.token
