# Dotfile Manager

A personal project to help automate the installation of dotfiles. Reads from ```configs/``` folder which the dots should
be saved into.

## How

- Achieves installation and deletion through the creation and deletion of symbolic links. Has simple git pull command.
- Should be bundled in with my [dotfiles](https://github.com/Fozzyack/dotfiles).

## Features

- [x] Install all dotfiles
- [x] Install single dotfile 
- [x] Uninstall all dotfiles
- [x] Uninstall single dotfile 
- [x] Add a simple git pull function
- [ ] Other Error Handling

### Optionals

Unsure if I will add these.
- [ ] Add a "purge" function - Removes data stored in ```.local/share/[dotfile]``` -- Unsure if this is a good idea.
- [ ] Freshen up the UI
- [ ] Potentially add a feature to allow compatibility with other OS.
