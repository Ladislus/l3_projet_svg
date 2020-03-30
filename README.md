# Projet de rendu SVG

Project made by a group of 4 students of Orleans' University : Ladislas WALCAK, Simon DRIEUX, Baptiste JOFFROY and Luka MERCIER. Our goal is to create .svg art in realtime with other users. Wrote in C++17, it uses common libraries like cairo, gtk-3, rsvg2 and tinyxml2.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
Firstly, you need to clone this project on your local computer.

```bash
git clone https:// o<studentnumber> @pdicost.univ-orleans.fr/git/scm/lipi/drieux_joffroy_walcak_mercier.git
```
Then navigate to the project folder :
```bash
cd drieux_joffroy_walcak_mercier/
```

You can then compile manually the 2 programs with :
```bash
make
```
Then launch them with the commands :  
```bash
bin/client [address] [port]
```
```bash
bin/server [port]
```

but you can also compile and launch the programs with default port and addresses (127.0.0.1 on port 5555):
```bash
make run_server
```
```bash
make run_client
```

You can also use Cmake if you want, using the regular procedure.


### Prerequisites

What things you need to install the software and how to install them.
Here's a list of libraries and dependencies we used :

* libcairo2-dev
* libgtk-3-dev
* librsvg2-dev
* libtinyxml2-dev
* libcbor

#### On Ubuntu

As sudoer :

```
apt-get install libcairo2-dev libgtk-3-dev librsvg2 libcairo2-dev
```

#### On Arch

You can find all the packages on the AUR repository, but most of them are already installed becauses most of software are using them as dependencies.

## Built With

* [Make](https://www.gnu.org/software/make/manual/make.html) - Build tool
* [CMake](https://cmake.org/) - Build tool

## Versioning

We use [Git](https://git-scm.com/) for versioning.

## Authors

* **Ladislas WALCAK** - *Initial work* - [Github](https://github.com/Ladislus)
* **Simon DRIEUX** - *Initial work* - [Github](https://github.com/SimonDr18)
* **Baptiste JOFFRY** - *Initial work* - [Github](https://github.com/)
* **Luka MERCIER** - *Initial work* - [Github](https://github.com/)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Orleans University
* F. Becker and S. ROBERT, directors of the project
