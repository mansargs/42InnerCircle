# Minitalk

Minitalk is a simple client-server messaging application written in C. It demonstrates inter-process communication using UNIX signals, allowing a server to handle and reply to multiple clients concurrently.

## Features

- **Multi-client Support:** The server can handle and reply to multiple clients at the same time.
- **Reliable Communication:** Messages are sent from client to server using UNIX signals, ensuring data integrity.
- **Custom Libft Library:** Includes a custom implementation of standard C library functions for string and memory manipulation.
- **Modular Codebase:** Clear separation between client, server, and utility code.

## Project Structure

```
Minitalk/
  ├── client/         # Client source code
  ├── server/         # Server source code
  ├── libft/          # Custom C library (libft)
  └── Makefile        # Build instructions
```

## Build Instructions

1. **Clone the repository:**
   ```sh
   git clone <git@github.com:mansargs/Minitalk.git>
   cd Minitalk
   ```

2. **Build the project:**
   ```sh
   make
   ```

   This will compile both the server and client, as well as the custom `libft` library.

## Usage

1. **Start the server:**
   ```sh
   ./server/server
   ```

2. **Start a client (in another terminal):**
   ```sh
   ./client/client <server_pid> "Your message here"
   ```

   Replace `<server_pid>` with the process ID of the running server.

3. **Multiple clients can connect and send messages simultaneously. The server will reply to each client.**

## Further Features

- The server can clear inactive clients.
- Robust error handling and input validation.
- Easily extendable for additional features.

## Custom Library (libft)

This project includes a custom implementation of many standard C library functions, located in the `libft/` directory. These are used throughout the client and server code for string and memory operations.

## License

This project is for educational purposes and is not intended for production use.
