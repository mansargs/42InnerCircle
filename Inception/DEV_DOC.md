# DEV_DOC.md - Developer Documentation

## Overview

This project uses Docker Compose to orchestrate a WordPress stack with NGINX and MariaDB.
The repository includes:
- `Makefile` for build and lifecycle commands
- `srcs/docker-compose.yml` for service definitions
- `srcs/.env_example` for environment variables
- `srcs/secrets/` for Docker secrets
- service-specific Dockerfiles and startup scripts

---

## Prerequisites

- Linux-based host
- Docker installed
- Docker Compose installed
- GNU Make
- `openssl` installed for certificate generation

---

## Project Setup

### Clone repository

```bash
cd ~
git clone <repository-url> Inception
cd Inception
```

### Create environment file

```bash
cp srcs/.env_example srcs/.env
```

### Create secret files

```bash
mkdir -p srcs/secrets/maria_db
mkdir -p srcs/secrets/wordpress

echo -n "your_db_password" > srcs/secrets/maria_db/db_password.txt
echo -n "your_root_password" > srcs/secrets/maria_db/db_root_password.txt
echo -n "your_wordpress_user_pass" > srcs/secrets/wordpress/wp_user_password.txt
echo -n "your_wordpress_admin_pass" > srcs/secrets/wordpress/wp_root_password.txt
```

### Edit `srcs/.env`

Set required variables:

```bash
USERNAME=your_login
DOMAIN_NAME=your_login.42.fr
CERTS=/etc/nginx/ssl/your_login.crt
KEYOUT=/etc/nginx/ssl/your_login.key
MYSQL_USER=wordpress
MYSQL_DATABASE=wordpress
MYSQL_HOSTNAME=mariadb
WORDPRESS_TITLE="My Website"
WORDPRESS_ROOT_USERNAME=wpadmin
WORDPRESS_ROOT_EMAIL=admin@example.com
WORDPRESS_USER_USERNAME=subscriber
WORDPRESS_USER_EMAIL=user@example.com
```

---

## Build and Run

### Using Makefile

```bash
make
```

### Useful commands

```bash
make down
make clean
make fclean
make start
make stop
make re
```

### Docker Compose direct commands

```bash
cd srcs
docker-compose up -d --build
docker-compose down
docker-compose down -v
docker-compose logs -f nginx
```

---

## Service Definitions

### `nginx`

- Builds from `srcs/requirements/nginx/Dockerfile`
- Uses `.env` and secrets indirectly through startup script
- Mounts WordPress files from `wordpress-volume`
- Exposes port 443 to the host
- Waits for WordPress at `wordpress:9000`

### `wordpress`

- Builds from `srcs/requirements/wordpress/Dockerfile`
- Uses `WORDPRESS_*` environment variables from `.env`
- Uses secrets for `wp_user_password` and `wp_root_password`
- Mounts WordPress files from `wordpress-volume`
- Starts PHP-FPM on port 9000
- On first start, downloads WordPress and installs it

### `mariadb`

- Builds from `srcs/requirements/mariadb/Dockerfile`
- Uses secrets for database passwords
- Mounts data to `mariadb-volume`
- Initializes the database only once

---

## Docker Compose Details

### Volumes

The Compose file defines two bind-mounted volumes:

- `wordpress-volume` → `/home/$USER/data/wordpress`
- `mariadb-volume` → `/home/$USER/data/mariadb`

### Network

- `inception` network of type `bridge`
- All services are attached to this network

### Secrets

The Compose file loads these secrets:

- `db_password` → `srcs/secrets/maria_db/db_password.txt`
- `db_root_password` → `srcs/secrets/maria_db/db_root_password.txt`
- `wp_user_password` → `srcs/secrets/wordpress/wp_user_password.txt`
- `wp_root_password` → `srcs/secrets/wordpress/wp_root_password.txt`

---

## Runtime Behavior

### NGINX container

- Runs `tools/run_nginx.sh`
- Generates `/etc/nginx/ssl/*.crt` and `/etc/nginx/ssl/*.key` with OpenSSL
- Rewrites `default.conf` placeholders for domain and certificate paths
- Waits for WordPress PHP-FPM at `wordpress:9000`

### WordPress container

- Runs `tools/run_wordpress.sh`
- Reads secrets at `/run/secrets/db_password`, `/run/secrets/wp_user_password`, and `/run/secrets/wp_root_password`
- Downloads WordPress core if `wp-login.php` is missing
- Waits for MariaDB on `mariadb:3306`
- Writes `wp-config.php` and installs WordPress on first run
- Creates an additional subscriber user

### MariaDB container

- Runs `tools/run_mariadb.sh`
- Reads secrets at `/run/secrets/db_password` and `/run/secrets/db_root_password`
- Initializes the database directory if missing
- Creates the WordPress database and user
- Sets the MariaDB root password

---

## File Structure

```
Inception/
├── Makefile
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
└── srcs/
    ├── .env_example
    ├── .env
    ├── docker-compose.yml
    ├── secrets/
    │   ├── maria_db/
    │   │   ├── db_password.txt
    │   │   └── db_root_password.txt
    │   └── wordpress/
    │       ├── wp_user_password.txt
    │       └── wp_root_password.txt
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/default.conf
        │   └── tools/run_nginx.sh
        ├── wordpress/
        │   ├── Dockerfile
        │   └── tools/run_wordpress.sh
        └── mariadb/
            ├── Dockerfile
            └── tools/run_mariadb.sh
```

---

## Debugging and Troubleshooting

### Logs

```bash
docker-compose -f srcs/docker-compose.yml logs -f nginx

docker-compose -f srcs/docker-compose.yml logs -f wordpress

docker-compose -f srcs/docker-compose.yml logs -f mariadb
```

### Check running containers

```bash
docker ps
docker-compose -f srcs/docker-compose.yml ps
```

### Inspect volumes

```bash
docker volume ls
docker volume inspect inception_wordpress-volume
docker volume inspect inception_mariadb-volume
```

### Check host mounts

```bash
ls -la /home/$USER/data/wordpress
ls -la /home/$USER/data/mariadb
```

### Fix common issues

- If WordPress cannot reach MariaDB, verify `MYSQL_HOSTNAME=mariadb` in `srcs/.env`
- If NGINX fails, verify `DOMAIN_NAME`, `CERTS`, and `KEYOUT` values
- If database init fails, verify secret files exist and are non-empty

---

## Notes for Developers

- This project is built on Debian Bullseye slim images
- WordPress uses PHP 7.4 from the package repository
- MariaDB uses the official `mariadb-server` package
- Secrets are mounted into containers at `/run/secrets`
- Host bind mounts are configured in Docker Compose with `driver_opts`

