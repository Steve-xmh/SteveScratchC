# SteveScratchC

本软件使用 GPL v3 协议开源

## 构建

首先准备 MSYS2 ，用 pacman 安装 gtk3 librsvg lua 即可

使用 pkg-config 生成构建参数~

构建的时候请记得定义这三个宏的其中一个：WINDOWS UNIX OSX ，为了适配各种系统（目前 Ubuntu 和 Windows x32 x64 均构建成功）

## 引用库
- GTK+ 3.0 (LGPL v2)
- Lua 5.3 (MIT)
- librsvg 2.0 (LGPL v2)
