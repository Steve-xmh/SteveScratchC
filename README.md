# SteveScratchC

## 构建

首先准备 MSYS2 ，用 pacman 安装 gtk3 librsvg lua 即可

使用 pkg-config 生成构建参数~

构建的时候请记得定义这三个宏的其中一个：WINDOWS UNIX OSX ，为了适配各种系统（目前 Ubuntu 和 Windows x32 x64 均构建成功）
