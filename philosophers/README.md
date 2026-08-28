## Philosophers (philo & philo_bonus)

An implementation of the classic Dining Philosophers concurrency problem in C, featuring two variants:

- **philo**: Multithreaded solution using POSIX threads (`pthread`) and mutexes.
- **philo_bonus**: Multiprocess solution using POSIX processes and named semaphores.

Both programs simulate philosophers sitting around a table, alternately thinking, eating, and sleeping while competing for shared resources (forks). The goal is to avoid deadlocks and starvation while respecting timing constraints.

### Project Structure

```
philosophers/
  philo/           # Threaded implementation (mutexes)
    include/
    source/
    Makefile
  philo_bonus/     # Process-based implementation (semaphores)
    include/
    source/
    Makefile
```

### Build

Build each target independently from its directory:

```bash
cd philo && make        # builds the threaded version
cd ../philo_bonus && make  # builds the bonus (semaphore) version
```

Common Make targets:

- `make`: build
- `make clean`: remove object files
- `make fclean`: remove objects and binaries
- `make re`: rebuild from scratch

### Usage

Both executables accept the same arguments:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

For the bonus version:

```
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Parameters:

- `number_of_philosophers` (int > 0): number of philosophers and forks.
- `time_to_die` (ms): if a philosopher doesn’t start eating within this time since last meal, they die.
- `time_to_eat` (ms): eating duration.
- `time_to_sleep` (ms): sleeping duration.
- `[optional] number_of_times_each_philosopher_must_eat` (int > 0): if provided, the simulation stops when every philosopher has eaten at least this many times.

Example runs:

```bash
# 5 philosophers, 800ms to die, 200ms to eat, 200ms to sleep, run indefinitely
./philo 5 800 200 200

# 5 philosophers, stop after each eats 7 times
./philo 5 800 200 200 7

# Bonus (process + semaphores)
./philo_bonus 5 800 200 200 7
```

### What You’ll See

The programs print timestamped, synchronized logs such as:

```
123 1 has taken a fork
124 1 is eating
325 1 is sleeping
...
```

The simulation ends when a philosopher dies or when the optional meal goal is reached for all philosophers (if specified). Output is designed to be free of data races and interleaving issues.

### Design Highlights

- **philo (threads + mutexes)**:
  - One thread per philosopher; optional monitor for death detection.
  - Mutex-protected forks; careful ordering to avoid deadlocks.
  - Millisecond-accurate timing utilities with responsive sleeps.

- **philo_bonus (processes + semaphores)**:
  - One process per philosopher; parent process monitors and coordinates.
  - Named semaphores for forks and printing; optional per-philosopher semaphores for meal tracking.
  - Clean process lifecycle management and robust termination on death or completion.

### Validation Rules

- All arguments must be valid positive integers within reasonable ranges.
- Timings are in milliseconds; values too small may cause premature deaths.
- The program ensures no deadlocks and minimizes starvation.

### Troubleshooting

- If you see immediate deaths, increase `time_to_die` or reduce `time_to_eat`/`time_to_sleep`.
- On slow systems or VMs, prefer slightly larger timing values (e.g., `800 200 200`).
- For the bonus version, ensure your system supports POSIX named semaphores. If crashes occur after abrupt stops, you may need to manually unlink semaphores (implementation usually handles it):

```bash
ls /dev/shm | grep sem.
```

### Development Notes

- Code is written in C and adheres to common 42 project constraints (no forbidden functions, precise logging, strict timing).
- Key modules include parsing, initialization, time utilities, action loops, and cleanup logic in both variants.

### License

This project is provided as-is for educational purposes.


