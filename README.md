# Dotfile Manager

A personal project to help automate the installation of dotfiles. Reads from ```./configs/``` folder which the dots should
be saved into. `./configs` should be in the same directory as the `dotfile-manager` executable.

## How

- Achieves installation and deletion through the creation and deletion of symbolic links. Has simple git pull command.
- Should be bundled in with my [dotfiles](https://github.com/Fozzyack/dotfiles).

## Features

- [x] Install all dotfiles
- [x] Install single dotfile 
- [x] Uninstall all dotfiles
- [x] Uninstall single dotfile 
- [ ] Add a simple git pull function
- [ ] Other Error Handling

### How to build

I've been using ```cmake``` to create make file and build files.

```bash
cd build
cmake ..
make
./dotman
```
