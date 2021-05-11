influxd & 
telegraf &

influx -execute "CREATE DATABASE influxdb"
influx -execute "CREATE USER admin_if WITH PASSWORD 'admin'"
influx -execute "GRANT ALL ON influxdb TO admin_if"

tail -f /dev/null