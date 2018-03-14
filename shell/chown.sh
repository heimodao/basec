# !/bin/sh

usage(){
	echo "usage: sh chown.sh linkzw|zw|root"
}
# chown linkzw:linkzw /home/linkzw/

if [ $# -lt 1 ];
then
	usage
	exit
fi

name = $1
sudo chown -R $name:$name ~/Git/algorithm/
echo "chown sucessed!!!"
