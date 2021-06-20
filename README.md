# Indie Studio
> The aim of the Indie Studio is to implement a cross-platform 3D video game with real-world tools.

We decided to remake the _Wii tank_ game.

We used the _raylib_ graphical library.


[![Raylib logo](.github/Readme_resources/Raylib_logo.png)](https://www.raylib.com/)

[![GitHub release (latest by date)](https://img.shields.io/github/v/release/raysan5/raylib?label=raylib%20version&style=for-the-badge)](https://github.com/raysan5/raylib/releases/tag/3.7.0)
[![Discord][Discord-logo]](https://discord.com/channels/426912293134270465/)

## Previews
![Splash screen](/.github/Readme_resources/wait_screen.png)

- ### Main menu
    ![Main menu image](/.github/Readme_resources/main_menu.png)
- ### Settings
    ![Settings image](/.github/Readme_resources/settings_menu.png)
- ### In game
    ![In game image](/.github/Readme_resources/in_game.png)
- ### Pause menu
    ![pause menu image](/.github/Readme_resources/pause_menu.png)
- ### End menu
    ![end menu image](/.github/Readme_resources/end_game.png)

## Requirements
### Cmake >= 3.17
To install cmake please refer to the [installation guide](https://cmake.org/install/)
## Build and run

Linux and Windows:

```sh
cmake .
cmake --build .
```

## Documentation
>Make sure that you have [_Doxygen_](https://www.doxygen.nl/download.html) installed 

```shell
make doc
```

File are generated in _./Documentation_ folder.

>If you have _Firefox_ you can run:
```shell
make doc-firefox
```
It generate documentation and launch a html preview.


## Contributors
- Maxime Dodin [![github-link][github-logo]](https://github.com/maxime-dodin)
- Robin Levavasseur [![github-link][github-logo]](https://github.com/roblevepi)
- Clément Ruat  [![github-link][github-logo]](https://github.com/fantoruse)
- Charlie Chou [![github-link][github-logo]](https://github.com/Chch270)
- Antoine Desruet [![github-link][github-logo]](https://github.com/antwxne)


<!-- Markdown link & img definition's -->
[vsc-installation-doc]: https://code.visualstudio.com/docs/editor/command-line
[cmake-installation-doc]: https://cmake.org/install/
[Github-logo]: https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white
[Discord-logo]: https://img.shields.io/badge/Discord-7289DA?style=for-the-badge&logo=discord&logoColor=white
[Raylib-logo]: /.github/Readme_resources/Raylib_logo.png