# linkzw.com
cd ~/linkzw.com/ && svn update

# algorithm
cd ~/Git/algorithm/ && git pull

# wenruo95.github.io
cd ~/Git/wenruo95.github.io/ && git pull

# socket-server
cd ~/Git/socket-server/ && git pull

# clogger
cd ~/Git/clogger/ && git pull

# tools
cd ~/Git/tools/ && git pull

# c++
cd ~/Git/cpp-study/ && git pull

sudo sh ~/linkzw.com/algorithm/shell/copy-svn-git.sh

sudo sh ~/linkzw.com/algorithm/shell/copy-svn-blog.sh

sudo sh ~/linkzw.com/algorithm/shell/copy-svn-socket.sh

sudo cp -r ~/linkzw.com/tools/ ~/Git/

sudo cp -r ~/linkzw.com/clogger/ ~/Git/

sudo cp -r ~/linkzw.com/algorithm/c++/*.* ~/Git/cpp-study/

pwd
cd ~/Git/algorithm/ && git status

pwd
cd ~/Git/wenruo95.github.io/ && git status

pwd
cd ~/Git/socket-server/ && git status

pwd
cd ~/Git/clogger/ && git status

pwd
cd ~/Git/cpp-study/ && git status
