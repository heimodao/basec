# !/bin/sh

usage(){
	echo "usage: sh chown.sh linkzw|zw|root"
}

if [ $# -lt 1 ];
then
	usage
	exit
fi

name = $1
sudo chown -R $name:$name ~/Git/algorithm/
echo "chown sucessed!!!"
