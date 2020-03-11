# Projet de rendu SVG

Project made by a group of 4 students of Orleans' University : Ladislas WALCAK, Simon DRIEUX, Baptiste JOFFROY and Luka MERCIER. Our goal is to create .svg art in realtime with other users. Wrote in C++17, it uses common libraries like cairo, gtk-3, rsvg2 and tinyxml2.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
Firstly, you need to clone this project on your local computer.

```
git clone https:// o<studentnumber> @pdicost.univ-orleans.fr/git/scm/lipi/drieux_joffroy_walcak_mercier.git
```
Then navigate to the project folder :
```
cd drieux_joffroy_walcak_mercier/
```

Finally :
```
make
```
This will compile the program.

To launch :
```
make run_server
```
```
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


## Running the tests

//TODO
Explain how to run the automated tests for this system

## Built With

* [Make](https://www.gnu.org/software/make/manual/make.html) - Build tool
* [CMake](https://cmake.org/) - Build tool

## Versioning

We use [Git](https://git-scm.com/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags).

## Authors

* **Ladislas WALCAK** - *Initial work* - [Github](https://github.com/Ladislus)
* **Simon DRIEUX** - *Initial work* - [Github](https://github.com/SimonDr18)
* **Baptiste JOFFRY** - *Initial work* - [Github](https://github.com/)
* **Luka MERCIER** - *Initial work* - [Github](https://github.com/)

//TODO
See also the list of [contributors]() who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Orleans University
* F. Becker and S. ROBERT, directors of the project
