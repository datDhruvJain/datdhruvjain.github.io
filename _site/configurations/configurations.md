# Wallpapers
[Wall 1](https://datdhruvjain.github.io/configurations/walls/db6lwau2abz61.jpg)
[Wall 2](https://datdhruvjain.github.io/configurations/walls/kth09tk4s7071.jpg)

# Windows

### Applications
- MS Office
- Windows Terminal
- vscode
- Powershell 7, is much faster to startup than Powershell 6

### Dev Environment
- wsl version 1 for minimal linux tools
    wsl integrates nicely and you can run commands like git, make, gcc by doing
    ``` powershell
    wsl gcc
    wsl make
    wsl git clone https://git-repo
    ```

    There is an added step, in the distro, at `etc/wsl.conf`
    ```
    [automount]
    options = "metadata"
    ```
