# C++ Piscine Exercises

This repository contains a series of C++ projects organized by module and exercise number. Each exercise is implemented in its own directory with a self-contained `Makefile`, source files, and headers.

## Repository Structure

The repository is structured as follows:

- `Module00/` — beginner C++ tasks covering input/output, basic classes, and simple object management
- `Module01/` — class construction, dynamic allocation, memory ownership, and string manipulation
- `Module02/` — fixed-point arithmetic, operator overloading, comparisons, and basic geometry
- `Module03/` — class inheritance, polymorphism, and specialized combat-style objects
- `Module04/` — abstract classes, virtual functions, deep copy semantics, and inventory systems
- `Module05/` — early advanced exercises with class extensions and memory management
- `Module06/` — continued C++ practice, often with deeper object-oriented patterns
- `Module07/` — further exercises focused on program structure, safety, and behavior
- `Module08/` — extended application-level coding patterns and utility implementation
- `Module09/` — later-stage projects emphasizing design, reuse, and class interaction

Each module contains numbered exercise directories such as `ex00/`, `ex01/`, `ex02/`, etc.

## Module Highlights

### Module00
- `ex00/` — `megaphone`: simple argument echoing with uppercase conversion
- `ex01/` — `PhoneBook`: `Contact` and `PhoneBook` classes for storing and searching contacts
- `ex02/` — `Account`: account management with deposits, withdrawals, and transaction logging

### Module01
- `ex00/` — `Zombie` class with `newZombie` and `randomChump` object creation methods
- `ex01/` — `zombieHorde`: factory-style creation of dynamic zombie arrays
- `ex02/` — additional exercise centered on object behavior and lifecycle management
- `ex03/` — `HumanA` and `HumanB` with `Weapon` references and pointer ownership
- `ex04/` — `Replace`: reading and replacing text in a file
- `ex05/` — `Harl`: severity-based logging and message dispatch
- `ex06/` — extended `Harl` behavior or refined complaint handling logic

### Module02
- `ex00/` — `Fixed`: integer fixed-point number representation and conversion
- `ex01/` — expanded `Fixed` class operator support and comparison behavior
- `ex02/` — additional fixed-point arithmetic and improved class interaction
- `ex03/` — `bsp`: geometry helper to determine whether a point lies inside a triangle

### Module03
- `ex00/` — `ClapTrap`: base combat unit with attack, damage, and repair behavior
- `ex01/` — `ScavTrap`: derived type with guard mode and extended actions
- `ex02/` — `FragTrap`: derived type with special high-five behavior
- `ex03/` — `DiamondTrap`: multiple inheritance combining `ScavTrap` and `FragTrap`

### Module04
- `ex00/` — `Animal`, `Cat`, `Dog`, `WrongAnimal`, `WrongCat`: runtime polymorphism and virtual methods
- `ex01/` — `Brain`: deep-copy semantics for animal thoughts and copy behavior
- `ex02/` — `AAnimal`: abstract animal base class and correct dynamic memory usage
- `ex03/` — `AMateria` / `Character`: materia inventory, equip/unequip mechanics, and action execution

### Module05 through Module09
- `Module05/` — exercises `ex00`–`ex03` with more advanced class and object management patterns
- `Module06/` — exercises `ex00`–`ex02` continuing the C++ learning path in object-oriented design
- `Module07/` — exercises `ex00`–`ex02` focused on program structure, memory usage, and class behavior
- `Module08/` — exercises `ex00`–`ex02` covering extended application patterns and utility implementation
- `Module09/` — exercises `ex00`–`ex02` for later-stage projects and deeper design practice

## How to Build

To build a specific exercise:

```bash
cd ModuleXX/exYY
make
```

Replace `ModuleXX` and `exYY` with the desired module and exercise.

## How to Run

Run the executable produced by the `Makefile` from the same exercise folder. For example:

```bash
./<executable-name>
```

The executable name is usually defined by the `NAME` variable in the exercise `Makefile`.

## Common Makefile Targets

- `make` or `make all` — compile the exercise
- `make clean` — delete object files
- `make fclean` — delete object files and executable
- `make re` — clean and rebuild

## Notes

- Most exercises compile with `c++` using flags `-Wall -Wextra -Werror -std=c++98`.
- Source files use `.cpp` and headers use `.hpp`.
- Each exercise folder is intentionally self-contained.

## Example

To build and run the `megaphone` exercise in `Module00/ex00`:

```bash
cd Module00/ex00
make
./megaphone
```
