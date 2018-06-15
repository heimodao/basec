# linkzw.com
cd ~/linkzw.com/ && svn update

# algorithm
cd ~/Git/algorithm/ && git pull

# wenruo95.github.io
cd ~/Git/wenruo95.github.io/ && git pull

# socket-server
cd ~/Git/socket-server/ && git pull

# tools
cd ~/Git/tools/ && git pull

sudo sh ~/linkzw.com/algorithm/shell/copy-svn-git.sh

sudo sh ~/linkzw.com/algorithm/shell/copy-svn-blog.sh

sudo sh ~/linkzw.com/algorithm/shell/copy-svn-socket.sh

sudo cp -r ~/linkzw.com/tools/ ~/Git/

cd ~/Git/algorithm/ && git status

cd ~/Git/wenruo95.github.io/ && git status

cd ~/Git/socket-server/ && git status
