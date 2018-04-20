sudo sh ~/linkzw.com/algorithm/shell/update.sh

cd ~/linkzw.com/ && svn add * && svn commit -m "$1"

cd ~/Git/algorithm/ && git add . && git commit -a -m "$1"

cd ~/Git/wenruo95.github.io/ && git add . && git commit -a -m "$1"
