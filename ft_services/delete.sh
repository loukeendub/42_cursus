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
kubectl delete service influxdb
kubectl delete deployment influxdb
kubectl delete service grafana
kubectl delete deployment grafana
kubectl delete pvc grafana-pvc
kubectl delete pvc influxdb-pv-claim
kubectl delete service ftps
kubectl delete deployment ftps
kubectl delete ns kubernetes-dashboard

rm -rf tmp.token
